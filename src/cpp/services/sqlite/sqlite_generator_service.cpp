//
// Created by Mike Roylance on 5/28/16.
//

#include "sqlite_generator_service.h"

SQLiteGeneratorService::SQLiteGeneratorService() {
    // these lists should never be that large, but this is a way for us to have default values in protobuf 3
    for(int i = 0; i < org::yaorm::sqlite::SQLiteType_descriptor()->value_count(); i++) {
        auto sqlite_type = org::yaorm::sqlite::SQLiteType_descriptor()->value(i);
        for(int j = 0; j < org::yaorm::sqlite::SQLiteTypeMapping_descriptor()->value_count(); j++) {
            auto protobuf_type = org::yaorm::sqlite::SQLiteTypeMapping_descriptor()->value(j);
            if (sqlite_type->number() == protobuf_type->number() && sqlite_type->number() != 0) {
                for(int k = 0; k < org::yaorm::ProtobufType_descriptor()->value_count(); k++) {
                    auto actual_proto_type = org::yaorm::ProtobufType_descriptor()->value(k);
                    if (actual_proto_type->name() == protobuf_type->name()) {
                        compiled_maps[actual_proto_type->number()] = sqlite_type->name();
                    }
                }
            }
        }
    }
}


std::string SQLiteGeneratorService::build_count_sql(org::yaorm::Definition definition) {
    return "select count(1) as long_val from " + definition.name();
}

std::string SQLiteGeneratorService::build_create_column(org::yaorm::Definition definition,
                                                        org::yaorm::PropertyDefinition property_definition) {
    if (compiled_maps.find(property_definition.type()) != compiled_maps.end()) {
        return "alter table "
               + definition.name()
               + " add column "
               + property_definition.name()
               + " "
               + compiled_maps[property_definition.type()];
    }

    return "";
}

int SQLiteGeneratorService::get_bulk_insert_size() {
    return 100;
}

std::string SQLiteGeneratorService::build_drop_column(org::yaorm::Definition definition,
                                                      org::yaorm::PropertyDefinition property_definition) {
    auto table_sql = build_create_table(definition);
    if (table_sql.length() == 0) {
        return "";
    }

    std::string workspace = "";
    workspace += "drop table if exists temp_" + definition.name() + SEMICOLON + CARRIAGE_RETURN;
    workspace += "alter table " + definition.name() + " rename to temp_" + definition.name() + SEMICOLON + CARRIAGE_RETURN;

    std::string column_names_without_id = common_sql_utilities.build_comma_separated_column_names(definition);
    workspace += "insert into "
                 + definition.name()
                 + " (" + column_names_without_id
                 + ") select "
                 + column_names_without_id + " from temp_" + definition.name() + SEMICOLON;

    return workspace;
}

std::string SQLiteGeneratorService::build_drop_index(org::yaorm::Definition definition,
                                                     std::vector<org::yaorm::PropertyDefinition> columns) {
    auto index_name = common_sql_utilities.build_index_name(columns);
    return "drop index if exists " + index_name + " on " + definition.name() + SEMICOLON;
}

std::string SQLiteGeneratorService::build_create_index(org::yaorm::Definition definition, org::yaorm::Index index) {
    std::vector<org::yaorm::PropertyDefinition> columns;
    for(auto column:definition.property_definitions()) {
        columns.push_back(column);
    }
    auto index_name = common_sql_utilities.build_index_name(columns);
    auto sorted_column_names = common_sql_utilities.build_comma_separated_column_names(definition);
    return "create index if not exists "
           + index_name
           + " on "
           + definition.name()
           + LEFT_PAREN
           + sorted_column_names
           + RIGHT_PAREN
           + SEMICOLON;
}

std::string SQLiteGeneratorService::build_drop_table(org::yaorm::Definition definition) {
    if (definition.name().length() == 0) {
        return "";
    }
    return "drop table if exists " + definition.name() + SEMICOLON;
}

std::string SQLiteGeneratorService::build_create_table(org::yaorm::Definition definition) {
    auto workspace = common_sql_utilities.build_column_name_type(definition, compiled_maps, primary_key);
    return "create table if not exists " + definition.name() + " (" + workspace + ");";
}

std::string SQLiteGeneratorService::build_delete_all(org::yaorm::Definition definition) {
    if (definition.name().length() == 0) {
        return "";
    }
    return "delete from " + definition.name() + SEMICOLON;
}

std::string SQLiteGeneratorService::build_delete_table(org::yaorm::Definition definition,
                                                       org::yaorm::PropertyHolder property_holder) {

    return "delete from " + definition.name() + " where " + property_holder.property_definition().name();
}

std::string SQLiteGeneratorService::build_delete_with_criteria(org::yaorm::Definition definition,
                                                               org::yaorm::WhereClauseItem where_clause) {
    auto where_clause_string = common_sql_utilities.build_where_clause_helper(where_clause);
    return "delete from " + definition.name() + " where " + where_clause_string + SEMICOLON;
}

std::string SQLiteGeneratorService::build_bulk_insert(org::yaorm::Definition definition, org::yaorm::Records records) {
    auto column_names = common_sql_utilities.build_comma_separated_column_names(definition);
    std::string initial_statement = "insert into " + definition.name() + " (" + column_names + ") ";
    std::string union_statements = "";
    std::vector<org::yaorm::PropertyHolder> sorted_vector;

    for(auto record:records.records()) {
        sorted_vector.clear();
        for(auto column:record.columns()) {
            sorted_vector.push_back(column);
        }

        std::sort(sorted_vector.begin(), sorted_vector.end(), sort_record_by_name);
        std::string select_statement = "";
        for (auto column:sorted_vector) {
            if (select_statement.length() == 0) {
                select_statement += "select "
                                    + common_sql_utilities.get_formatted_string(column)
                                    + " as "
                                    + column.property_definition().name();
            }
            else {
                select_statement += COMMA
                        + common_sql_utilities.get_formatted_string(column)
                        + " as "
                        + column.property_definition().name();
            }
        }

        if (union_statements.length() == 0) {
            union_statements += select_statement;
        }
        else {
            union_statements += SPACED_UNION + select_statement;
        }
    }

    return initial_statement + SPACE + union_statements + SEMICOLON;
}

std::string SQLiteGeneratorService::build_insert(org::yaorm::Definition definition, org::yaorm::Record record) {
    auto insert_into_table_template = "insert into %s (%s) values (%s);";
    std::string column_names = "";
    std::string values = "";
    for(auto column:record.columns()) {
        if (column_names.length() > 0) {
            column_names += COMMA + column.property_definition().name();
        }
        else {
            column_names += column.property_definition().name();
        }

        if (values.length() > 0) {
            values += COMMA + common_sql_utilities.get_formatted_string(column);
        }
        else {
            values += common_sql_utilities.get_formatted_string(column);
        }
    }


    return "insert into " +  definition.name() + "(" + column_names + ") values (" + values + ");";
}

std::string SQLiteGeneratorService::build_update(org::yaorm::Definition definition,
                                                 org::yaorm::PropertyHolder key,
                                                 org::yaorm::Record record) {
    org::yaorm::WhereClauseItem where_clause_item;
    where_clause_item.set_allocated_name_and_property(&key);
    where_clause_item.set_operator_type(org::yaorm::WhereClauseItem::OperatorType::WhereClauseItem_OperatorType_EQUALS);
    auto where_clause = common_sql_utilities.build_where_clause_helper(where_clause_item);
    std::string update_name_values = "";
    for(auto column:record.columns()) {
        if (update_name_values.length() > 0) {
            update_name_values += COMMA + column.property_definition().name() + EQUALS + common_sql_utilities.get_formatted_string(column);
        }
        else {
            update_name_values += column.property_definition().name() + EQUALS + common_sql_utilities.get_formatted_string(column);
        }
    }

    return "update " + definition.name() + " set " + update_name_values + where_clause + SEMICOLON;
}

std::string SQLiteGeneratorService::build_update_with_criteria(org::yaorm::Definition definition,
                                                               org::yaorm::Record record,
                                                               org::yaorm::WhereClauseItem where_clause) {
    auto where_clause_str = common_sql_utilities.build_where_clause_helper(where_clause);
    std::string update_name_values = "";
    for(auto column:record.columns()) {
        if (update_name_values.length() > 0) {
            update_name_values += COMMA + column.property_definition().name() + EQUALS + common_sql_utilities.get_formatted_string(column);
        }
        else {
            update_name_values += column.property_definition().name() + EQUALS + common_sql_utilities.get_formatted_string(column);
        }
    }

    return "update " + definition.name() + " set " + update_name_values + update_name_values + SEMICOLON;
}

std::string SQLiteGeneratorService::build_select_all(org::yaorm::Definition definition, int n) {
    return "select * from " + definition.name() + " limit " + std::to_string(n) + SEMICOLON;
}

std::string SQLiteGeneratorService::build_where_clause(org::yaorm::Definition definition,
                                                       org::yaorm::WhereClauseItem where_clause) {
    auto where_clause_str = common_sql_utilities.build_where_clause_helper(where_clause);
    return "select * from " + definition.name() + where_clause_str + SEMICOLON;
}


























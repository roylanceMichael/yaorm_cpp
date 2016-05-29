//
// Created by Mike Roylance on 5/28/16.
//

#include "sqlite_generator_service.h"
#include <iostream>
#include <string>

SQLiteGeneratorService::SQLiteGeneratorService() {
    for(int i = 0; i < org::yaorm::sqlite::SQLiteType_descriptor()->value_count(); i++) {
        auto sqlite_type = org::yaorm::sqlite::SQLiteType_descriptor()->value(i);
        for(int j = 0; j < org::yaorm::sqlite::SQLiteTypeMapping_descriptor()->value_count(); j++) {
            auto protobuf_type = org::yaorm::sqlite::SQLiteTypeMapping_descriptor()->value(j);
            if (sqlite_type->number() == protobuf_type->number() && sqlite_type->number() != 0) {
                std::cout << protobuf_type->name() << " " << sqlite_type->name() << std::endl;
                compiled_maps[protobuf_type->number()] = sqlite_type->name();
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

    std::string column_names_without_id = build_comma_separated_column_names(definition);
    workspace += "insert into "
                 + definition.name()
                 + " (" + column_names_without_id
                 + ") select "
                 + column_names_without_id + " from temp_" + definition.name() + SEMICOLON;

    return workspace;
}

std::string SQLiteGeneratorService::build_drop_index(org::yaorm::Definition definition,
                                                     std::vector<org::yaorm::PropertyDefinition> columns) {
    auto index_name = build_index_name(columns);
    return "drop index if exists " + index_name + " on " + definition.name() + SEMICOLON;
}

std::string SQLiteGeneratorService::build_create_index(org::yaorm::Definition definition, org::yaorm::Index index) {
    std::vector<org::yaorm::PropertyDefinition> columns;
    for(auto column:definition.property_definitions()) {
        columns.push_back(column);
    }
    auto index_name = build_index_name(columns);
    auto sorted_column_names = build_comma_separated_column_names(definition);
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
    if (definition.property_definitions_size() == 0) {
        return "";
    }

    if (definition.name().length() == 0) {
        return "";
    }

    auto workspace = build_column_name_type(definition, compiled_maps, primary_key);
    return "create table if not exists " + definition.name() + " " + workspace + ";";
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
    auto where_clause_string = build_where_clause_helper(where_clause);
    return "delete from " + definition.name() + " where " + where_clause_string + SEMICOLON;
}

std::string SQLiteGeneratorService::build_bulk_insert(org::yaorm::Definition definition, org::yaorm::Records records) {
    auto column_names = build_comma_separated_column_names(definition);
    std::string initial_statement = "insert into " + definition.name() + " (" + column_names + ") ";
    std::string union_statements = "";

    for(auto record:records.records()) {
        std::sort(record.columns().begin(), record.columns().end(), sort_record_by_name);
        std::string select_statement = "";
        for (auto column:record.columns()) {
            if (select_statement.length() == 0) {
                select_statement += "select "
                                    + get_formatted_string(column)
                                    + " as "
                                    + column.property_definition().name();
            }
            else {
                select_statement += COMMA
                        + get_formatted_string(column)
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
    return "";
}

std::string SQLiteGeneratorService::build_update(org::yaorm::Definition definition, org::yaorm::PropertyHolder key,
                                                 org::yaorm::Record record) {
    return "";
}

std::string SQLiteGeneratorService::build_update_with_criteria(org::yaorm::Definition definition,
                                                               org::yaorm::Record record,
                                                               org::yaorm::WhereClauseItem where_clause) {
    return "";
}

std::string SQLiteGeneratorService::build_select_all(org::yaorm::Definition, int n) {
    return "";
}

std::string SQLiteGeneratorService::build_where_clause(org::yaorm::Definition,
                                                       org::yaorm::WhereClauseItem where_clause) {
    return "";
}


























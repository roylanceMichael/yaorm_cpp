//
// Created by Mike Roylance on 5/28/16.
//

#include "common_sql_utilities.h"

std::string CommonSQLUtilities::build_column_name_type(const org::yaorm::TableDefinition &definition,
                                                       std::map<int, std::string> &compiled_maps,
                                                       const std::string &primary_key) {
    std::string workspace;

    bool added_column = false;
    for (int i = 0; i < definition.column_definitions_size(); i++) {
        const auto &property = definition.column_definitions(i);
        if (property.is_key()) {
            added_column = true;
            workspace += property.name();
            workspace += SPACE;
            workspace += compiled_maps[property.type()];
            workspace += SPACE;
            workspace += primary_key;
        }
    }

    for (int i = 0; i < definition.column_definitions_size(); i++) {
        const auto &property = definition.column_definitions(i);
        if (!property.is_key()) {
            if (added_column) {
                workspace += COMMA;
            }
            workspace += SPACE;
            workspace += property.name();
            workspace += SPACE;
            workspace += compiled_maps[property.type()];
        }
    }

    return workspace;
}

std::string CommonSQLUtilities::build_comma_separated_column_names(const org::yaorm::TableDefinition &definition) {
    std::string workspace;
    bool added_column = false;
    std::vector<org::yaorm::ColumnDefinition> list_to_sort;
    for (int i = 0; i < definition.column_definitions_size(); i++) {
        const auto &item = definition.column_definitions(i);
        list_to_sort.push_back(item);
    }

    sort(list_to_sort.begin(), list_to_sort.end(), sort_by_name);

    for (const auto &item:list_to_sort) {
        if (item.is_key()) {
            if (added_column) {
                workspace += COMMA;
            }
            workspace += item.name();
            added_column = true;
        }
    }

    for (const auto &item:list_to_sort) {
        if (!item.is_key()) {
            if (added_column) {
                workspace += COMMA;
            }
            workspace += item.name();
            added_column = true;
        }
    }

    return workspace;
}

std::string CommonSQLUtilities::build_index_name(std::vector<org::yaorm::ColumnDefinition> &columns) {
    std::vector<org::yaorm::ColumnDefinition> sort_vector;
    for (const auto &column:columns) {
        sort_vector.push_back(column);
    }

    std::sort(sort_vector.begin(), sort_vector.end(), sort_by_name);
    std::string workspace;

    for (const auto &item:sort_vector) {
        workspace += item.name();
        workspace += UNDERSCORE;
    }

    return workspace += "idx";
}

std::string CommonSQLUtilities::get_formatted_string(org::yaorm::Column &holder) {
    switch (holder.definition().type()) {
        case org::yaorm::ProtobufType::NONE:
            return NULL_NAME;
        case org::yaorm::ProtobufType::DOUBLE:
            return std::to_string(holder.double_holder());
        case org::yaorm::ProtobufType::FLOAT:
            return std::to_string(holder.float_holder());
        case org::yaorm::ProtobufType::INT32:
            return std::to_string(holder.int32_holder());
        case org::yaorm::ProtobufType::INT64:
            return std::to_string(holder.int64_holder());
        case org::yaorm::ProtobufType::UINT32:
            return std::to_string(holder.uint32_holder());
        case org::yaorm::ProtobufType::UINT64:
            return std::to_string(holder.uint64_holder());
        case org::yaorm::ProtobufType::SINT32:
            return std::to_string(holder.sint32_holder());
        case org::yaorm::ProtobufType::SINT64:
            return std::to_string(holder.sint64_holder());
        case org::yaorm::ProtobufType::FIXED32:
            return std::to_string(holder.fixed32_holder());
        case org::yaorm::ProtobufType::FIXED64:
            return std::to_string(holder.fixed64_holder());
        case org::yaorm::ProtobufType::SFIXED32:
            return std::to_string(holder.sfixed32_holder());
        case org::yaorm::ProtobufType::SFIXED64:
            return std::to_string(holder.sfixed64_holder());
        case org::yaorm::ProtobufType::BOOL:
            return std::to_string(holder.bool_holder() ? 1 : 0);
        case org::yaorm::ProtobufType::STRING:
            return SINGLE_QUOTE + holder.string_holder() + SINGLE_QUOTE;
        case org::yaorm::BYTES:
            break;
        case org::yaorm::PROTO:
            break;
        case org::yaorm::ProtobufType_INT_MIN_SENTINEL_DO_NOT_USE_:
            break;
        case org::yaorm::ProtobufType_INT_MAX_SENTINEL_DO_NOT_USE_:
            break;
            return NULL_NAME;
    }
    return NULL_NAME;
}

std::string CommonSQLUtilities::build_where_clause_helper(org::yaorm::WhereClause &where_clause) {
    std::string filter_items;
    org::yaorm::WhereClause current_where_clause = where_clause;
    bool terminated = false;

    while (!terminated) {
        auto left_side = current_where_clause.name_and_property().definition().name();
        auto right_side_raw = current_where_clause.name_and_property();
        auto right_side = get_formatted_string(right_side_raw);
        std::string operator_type;
        switch (where_clause.operator_type()) {
            case org::yaorm::WhereClause_OperatorType_EQUALS:
                operator_type = EQUALS;
                break;
            case org::yaorm::WhereClause_OperatorType_GREATER_THAN:
                operator_type = GREATER_THAN;
                break;
            case org::yaorm::WhereClause_OperatorType_LESS_THAN:
                operator_type = LESS_THAN;
                break;
            case org::yaorm::WhereClause_OperatorType_NOT_EQUALS:
                operator_type = NOT_EQUALS;
                break;
            default:
                operator_type = EQUALS;
                break;
        }

        filter_items += SPACE + left_side + operator_type + right_side + SPACE;
        switch (current_where_clause.connecting_and_or()) {
            case org::yaorm::WhereClause_ConnectingAndOr_AND:
                filter_items += AND + SPACE;
                break;
            case org::yaorm::WhereClause_ConnectingAndOr_OR:
                filter_items += OR + SPACE;
                break;
            default:
                break;
        }
        if (!current_where_clause.has_connecting_where_clause()) {
            terminated = true;
        } else {
            current_where_clause = current_where_clause.connecting_where_clause();
        }
    }
    return filter_items;
}

std::string CommonSQLUtilities::build_column_name_type(const google::protobuf::Descriptor &descriptor,
                                                       std::map<int, std::string> &compiled_maps,
                                                       const std::string primary_key) {
    std::string workspace;

    bool added_column = false;
    for (int i = 0; i < descriptor.field_count(); i++) {
        auto field = descriptor.field(i);
        if (field->lowercase_name() == ID_NAME) {
            added_column = true;
            int found_type = field->type();
            workspace += field->lowercase_name();
            workspace += SPACE;
            workspace += compiled_maps[found_type];
            workspace += SPACE;
            workspace += primary_key;
        }
    }
    for (int i = 0; i < descriptor.field_count(); i++) {
        auto field = descriptor.field(i);

        if (field->lowercase_name() != ID_NAME) {
            if (added_column) {
                workspace += COMMA;
            }
            int found_type = field->type();
            workspace += SPACE;
            workspace += field->lowercase_name();
            workspace += SPACE;
            workspace += compiled_maps[found_type];
            added_column = true;
        }
    }
    return workspace;
}

bool CommonSQLUtilities::check_if_child_ok(const google::protobuf::Descriptor &descriptor) {
    bool found_id = false;
    bool found_parent_id = false;
    for (int i = 0; i < descriptor.field_count(); i++) {
        auto field = descriptor.field(i);
        if (field->lowercase_name() == ID_NAME) {
            found_id = true;
        } else if (field->lowercase_name() == PARENT_ID_NAME) {
            found_parent_id = true;
        }
    }
    return found_id && found_parent_id;
}

bool CommonSQLUtilities::check_if_ok(const google::protobuf::Descriptor &descriptor) {
    for (int i = 0; i < descriptor.field_count(); i++) {
        auto field = descriptor.field(i);
        if (field->lowercase_name() == ID_NAME) {
            return true;
        }
    }
    return false;
}

std::string CommonSQLUtilities::build_column_name_type_field(const google::protobuf::FieldDescriptor &field) {
    if (field.type() == google::protobuf::FieldDescriptor::TYPE_MESSAGE) {
    }

    return "";
}








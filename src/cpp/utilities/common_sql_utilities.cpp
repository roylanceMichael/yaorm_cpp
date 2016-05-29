//
// Created by Mike Roylance on 5/28/16.
//

#include "common_sql_utilities.h"

std::string CommonSQLUtilities::build_column_name_type(const org::yaorm::Definition &definition,
                                   std::map<int, std::string> &compiled_maps,
                                   const std::string &primary_key) {
    std::string workspace = "";

    bool added_column = false;
    for(auto property:definition.property_definitions()) {
        if (property.is_key()) {
            added_column = true;
            workspace += property.name();
            workspace += SPACE;
            workspace += compiled_maps[property.type()];
            workspace += SPACE;
            workspace += primary_key;
        }
    }

    for (auto property:definition.property_definitions()) {
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

std::string CommonSQLUtilities::build_comma_separated_column_names(const org::yaorm::Definition &definition) {
    std::string workspace = "";
    bool added_column = false;
    std::vector<org::yaorm::PropertyDefinition> list_to_sort;
    for(auto item:definition.property_definitions()) {
        list_to_sort.push_back(item);
    }

    sort(list_to_sort.begin(), list_to_sort.end(), sort_by_name);

    for(auto item:list_to_sort) {
        if (item.is_key()) {
            if (added_column) {
                workspace += COMMA;
            }
            workspace += item.name();
            added_column = true;
        }
    }

    for(auto item:list_to_sort) {
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

std::string CommonSQLUtilities::build_index_name(std::vector<org::yaorm::PropertyDefinition> columns) {
    std::vector<org::yaorm::PropertyDefinition> sort_vector;
    for(auto column:columns) {
        sort_vector.push_back(column);
    }

    std::sort(sort_vector.begin(), sort_vector.end(), sort_by_name);
    std::string workspace = "";

    for(auto item:sort_vector) {
        workspace += item.name();
        workspace += UNDERSCORE;
    }

    return workspace += "idx";
}

std::string CommonSQLUtilities::get_formatted_string(org::yaorm::PropertyHolder holder) {
    switch(holder.property_definition().type()) {
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
        case org::yaorm::BYTES:break;
        case org::yaorm::PROTO:break;
        case org::yaorm::ProtobufType_INT_MIN_SENTINEL_DO_NOT_USE_:break;
        case org::yaorm::ProtobufType_INT_MAX_SENTINEL_DO_NOT_USE_:break;
            return NULL_NAME;
    }
    return NULL_NAME;
}

std::string CommonSQLUtilities::build_where_clause_helper(org::yaorm::WhereClauseItem &where_clause) {
    std::string filter_items = "";
    org::yaorm::WhereClauseItem current_where_clause = where_clause;
    bool terminated = false;

    while(!terminated) {
        auto left_side = current_where_clause.name_and_property().property_definition().name();
        auto right_side = get_formatted_string(current_where_clause.name_and_property());
        std::string operator_type = "";
        switch (where_clause.operator_type()) {
            case org::yaorm::WhereClauseItem_OperatorType_EQUALS:
                operator_type = EQUALS;
            case org::yaorm::WhereClauseItem_OperatorType_GREATER_THAN:
                operator_type = GREATER_THAN;
            case org::yaorm::WhereClauseItem_OperatorType_LESS_THAN:
                operator_type = LESS_THAN;
            case org::yaorm::WhereClauseItem_OperatorType_NOT_EQUALS:
                operator_type = NOT_EQUALS;
            case org::yaorm::WhereClauseItem_OperatorType_WhereClauseItem_OperatorType_INT_MIN_SENTINEL_DO_NOT_USE_:
            case org::yaorm::WhereClauseItem_OperatorType_WhereClauseItem_OperatorType_INT_MAX_SENTINEL_DO_NOT_USE_:
                operator_type = EQUALS;
        }

        filter_items += SPACE + left_side + operator_type + right_side + SPACE;
        switch (current_where_clause.connecting_and_or()) {
            case org::yaorm::WhereClauseItem_ConnectingAndOr_AND:
                filter_items += AND + SPACE;
            case org::yaorm::WhereClauseItem_ConnectingAndOr_OR:
                filter_items += OR + SPACE;
            case org::yaorm::WhereClauseItem_ConnectingAndOr_NONE:
            case org::yaorm::WhereClauseItem_ConnectingAndOr_WhereClauseItem_ConnectingAndOr_INT_MIN_SENTINEL_DO_NOT_USE_:break;
            case org::yaorm::WhereClauseItem_ConnectingAndOr_WhereClauseItem_ConnectingAndOr_INT_MAX_SENTINEL_DO_NOT_USE_:break;
        }

        if (!current_where_clause.has_connecting_where_clause()) {
            terminated = true;
        }
        else {
            current_where_clause = current_where_clause.connecting_where_clause();
        }
    }

    return filter_items;
}
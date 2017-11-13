//
// Created by Mike Roylance on 5/29/16.
//

#ifndef YAORM_CPP_COMMON_SQL_UTILITIES_H_H
#define YAORM_CPP_COMMON_SQL_UTILITIES_H_H

#include "../models/yaorm_models.pb.h"

const std::string ID_NAME = "id";
const std::string PARENT_ID_NAME = "parent_id";
const std::string SPACE = " ";
const std::string COMMA = ",";
const std::string NULL_NAME = "null";
const std::string EQUALS = "=";
const std::string SEMICOLON = ";";
const std::string CARRIAGE_RETURN = "\n";
const std::string SPACED_UNION = "\nunion";
const std::string SPACED_AND = " and ";
const std::string AND = "and";
const std::string OR = "or";
const std::string UNDERSCORE = "_";
const std::string IS = "is";
const std::string LEFT_PAREN = "(";
const std::string RIGHT_PAREN = ")";
const std::string SINGLE_QUOTE = "'";
const std::string GREATER_THAN = ">";
const std::string LESS_THAN = "<";
const std::string NOT_EQUALS = "!=";

class CommonSQLUtilities {
public:
    bool check_if_ok(const google::protobuf::Descriptor &descriptor);

    bool check_if_child_ok(const google::protobuf::Descriptor &descriptor);

    std::string build_column_name_type_field(const google::protobuf::FieldDescriptor &field);

    std::string build_column_name_type(const google::protobuf::Descriptor &descriptor,
                                       std::map<int, std::string> &compiled_maps,
                                       std::string primary_key);

    std::string
    build_column_name_type(const org::yaorm::TableDefinition &definition, std::map<int, std::string> &compiled_maps,
                           const std::string &primary_key);

    std::string build_comma_separated_column_names(const org::yaorm::TableDefinition &definition);

    std::string build_index_name(std::vector<org::yaorm::ColumnDefinition> &columns);

    std::string get_formatted_string(org::yaorm::Column &holder);

    std::string build_where_clause_helper(org::yaorm::WhereClause &where_clause);
};

static bool sort_by_name(const org::yaorm::ColumnDefinition &first, const org::yaorm::ColumnDefinition &second) {
    return first.name() < second.name();
}

static bool sort_record_by_name(const org::yaorm::Column &first, const org::yaorm::Column &second) {
    return first.definition().name() < second.definition().name();
}

// taken from stack-overflow
static std::string generate_guid() {
    char new_guid[255] = {0};
    srand((unsigned) time(NULL));

    sprintf(new_guid, "%x%x-%x-%x-%x-%x%x%x",
            rand(), rand(),                 // Generates a 64-bit Hex number
            rand(),                         // Generates a 32-bit Hex number
            ((rand() & 0x0fff) |
             0x4000),   // Generates a 32-bit Hex number of the form 4xxx (4 indicates the UUID version)
            rand() % 0x3fff + 0x8000,       // Generates a 32-bit Hex number in the range [0x8000, 0xbfff]
            rand(), rand(), rand());        // Generates a 96-bit Hex number

    return new_guid;
}

#endif //YAORM_CPP_COMMON_SQL_UTILITIES_H_H

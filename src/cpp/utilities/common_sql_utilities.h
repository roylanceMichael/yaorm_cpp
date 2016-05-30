//
// Created by Mike Roylance on 5/29/16.
//

#ifndef YAORM_CPP_COMMON_SQL_UTILITIES_H_H
#define YAORM_CPP_COMMON_SQL_UTILITIES_H_H

#include "../models/yaorm_models.pb.h"

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
    std::string build_column_name_type(const org::yaorm::Definition& definition, std::map<int, std::string>& compiled_maps,
                                       const std::string& primary_key);

    std::string build_comma_separated_column_names(const org::yaorm::Definition &definition);

    std::string build_index_name(std::vector<org::yaorm::PropertyDefinition>& columns);

    std::string get_formatted_string(org::yaorm::PropertyHolder& holder);

    std::string build_where_clause_helper(org::yaorm::WhereClauseItem& where_clause);
};

static bool sort_by_name(const org::yaorm::PropertyDefinition &first, const org::yaorm::PropertyDefinition &second) {
    return first.name() < second.name();
}

static bool sort_record_by_name(const org::yaorm::PropertyHolder &first, const org::yaorm::PropertyHolder &second) {
    return first.property_definition().name() < second.property_definition().name();
}

#endif //YAORM_CPP_COMMON_SQL_UTILITIES_H_H

//
// Created by Mike Roylance on 5/31/16.
//

#include "test_utilities.h"

void add_record_internal(org::yaorm::Records& records,
                org::yaorm::PropertyDefinition& id_property,
                org::yaorm::PropertyDefinition& display_property,
                std::string id,
                std::string display) {
    auto record = records.add_records();
    auto id_column = record->add_columns();
    id_column->set_string_holder(id);
    auto id_column_property = id_column->mutable_property_definition();
    id_column_property->MergeFrom(id_property);

    auto display_column = record->add_columns();
    display_column->set_string_holder(display);
    auto display_column_property = display_column->mutable_property_definition();
    display_column_property->MergeFrom(display_property);
}

org::yaorm::Definition TestUtilities::build_simple_test_definition() {
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");

    auto id_property = definition.add_property_definitions();
    id_property->set_name("id");
    id_property->set_type(org::yaorm::ProtobufType::STRING);
    id_property->set_is_key(true);

    auto display_property = definition.add_property_definitions();
    display_property->set_name("display");
    display_property->set_type(org::yaorm::ProtobufType::STRING);

    return definition;
}

org::yaorm::Records TestUtilities::build_simple_records() {
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");

    auto id_property = definition.add_property_definitions();
    id_property->set_name("id");
    id_property->set_type(org::yaorm::ProtobufType::STRING);
    id_property->set_is_key(true);

    auto display_property = definition.add_property_definitions();
    display_property->set_name("display");
    display_property->set_type(org::yaorm::ProtobufType::STRING);

    org::yaorm::Records records;
    add_record_internal(records, *id_property, *display_property, "11111", "mike");

    return records;
}




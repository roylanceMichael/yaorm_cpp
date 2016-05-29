//
// Created by Mike Roylance on 5/29/16.
//

#include "sqlite_generator_service_tests.h"

void SQLiteGeneratorServiceTests::simple_create_table_test() {
    // arrange
    const std::string expected_result = "create table if not exists cool_beans (id TEXT primary key, display TEXT);";
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");

    auto id_property = definition.add_property_definitions();
    id_property->set_name("id");
    id_property->set_type(org::yaorm::ProtobufType::STRING);
    id_property->set_is_key(true);

    auto display_property = definition.add_property_definitions();
    display_property->set_name("display");
    display_property->set_type(org::yaorm::ProtobufType::STRING);

    SQLiteGeneratorService generator_service;

    // act
    auto generated_sql = generator_service.build_create_table(definition);

    // assert
    if (generated_sql != expected_result) {
        std::cout << generated_sql << std::endl;
    }
    assert(generated_sql == expected_result);
}


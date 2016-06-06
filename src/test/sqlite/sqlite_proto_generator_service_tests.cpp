//
// Created by Mike Roylance on 6/4/16.
//

#include "sqlite_proto_generator_service_tests.h"

void SQLiteProtoGeneratorServiceTests::simple_create_table_test() {
    // arrange
    const std::string expected_result = "create table if not exists TestModel (id TEXT primary key, display TEXT);";
    SQLiteProtoGeneratorService generator_service;
    org::yaorm::tests::TestModel test_model;
    auto metadata = test_model.GetMetadata().descriptor;

    // act
    auto generated_sql = generator_service.build_create_table(metadata);

    // assert
    if (generated_sql != expected_result) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_create_table_test_proto" << std::endl;
    }
    assert(generated_sql == expected_result);
}

void SQLiteProtoGeneratorServiceTests::simple_check_ok() {
    // arrange
    SQLiteProtoGeneratorService generator_service;
    org::yaorm::tests::TestModel test_model;
    auto metadata = test_model.GetMetadata();

    // act
    auto result = generator_service.can_persist_proto(metadata->descriptor);

    // assert
    if (!result) {
        std::cout << "failed simple_check_ok_proto" << std::endl;
    }
    else {
        std::cout << "passed simple_check_ok_proto" << std::endl;
    }
    assert(result);
}

void SQLiteProtoGeneratorServiceTests::simple_check_child_ok() {
    // arrange
    SQLiteProtoGeneratorService generator_service;
    org::yaorm::tests::TestModel test_model;
    auto metadata = test_model.GetMetadata();

    // act
    auto result = generator_service.can_persist_as_child(metadata.descriptor;

    // assert
    if (result) {
        std::cout << "failed simple_check_child_ok_proto" << std::endl;
    }
    else {
        std::cout << "passed simple_check_child_ok_proto" << std::endl;
    }
    assert(!result);
}




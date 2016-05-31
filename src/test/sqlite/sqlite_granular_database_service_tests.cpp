//
// Created by Mike Roylance on 5/30/16.
//

#include "sqlite_granular_database_service_tests.h"
#include <iostream>

void SQLiteGranularDatabaseServiceTests::simple_select_query_test() {
    // arrange
    std::string file_name = "test_file.db";
    TestUtilities test_utilities;
    SQLiteGranularService granular_service(file_name);
    auto definition = test_utilities.build_simple_test_definition();
    auto records = test_utilities.build_simple_records();

    std::promise<org::yaorm::Record> record_promise;
    auto record_future = record_promise.get_future();

    SQLiteTestMapStreamer test_map_streamer(definition, record_promise);
    SQLiteGeneratorService generator_service;

    auto create_table_sql = generator_service.build_create_table(definition);
    granular_service.execute_update_query(create_table_sql);
    auto bulk_insert_sql = generator_service.build_bulk_insert(definition, records);
    granular_service.execute_update_query(bulk_insert_sql);

    // act
    auto select_sql = generator_service.build_select_all(definition);
    granular_service.execute_select_query_stream(select_sql, test_map_streamer);

    // assert
    auto found_record = record_future.get();
    assert(found_record.columns_size() == 2);

    auto first_column = found_record.columns(0);
    assert(first_column.string_holder() == "mike");
    auto second_column = found_record.columns(1);
    assert(second_column.string_holder() == "11111");
}


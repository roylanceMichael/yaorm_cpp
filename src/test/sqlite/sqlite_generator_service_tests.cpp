//
// Created by Mike Roylance on 5/29/16.
//

#include "sqlite_generator_service_tests.h"

// helper function
void add_record(org::yaorm::Records& records,
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
    else {
        std::cout << "passed simple_create_table_test" << std::endl;
    }
    assert(generated_sql == expected_result);
}

void SQLiteGeneratorServiceTests::simple_count_sql_test() {
    // arrange
    const std::string expected_result = "select count(1) as long_val from cool_beans;";
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
    auto generated_sql = generator_service.build_count_sql(definition);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_count_sql_test" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_create_column_test() {
    // arrange
    const std::string expected_result = "alter table cool_beans add column display TEXT;";
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
    auto generated_sql = generator_service.build_create_column(definition, *display_property);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_create_column_test" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_drop_column_test() {
    // arrange
    const std::string expected_result = "drop table if exists temp_cool_beans;\n"
            "alter table cool_beans rename to temp_cool_beans;\n"
            "create table if not exists cool_beans (id TEXT primary key, display TEXT);\n"
            "insert into cool_beans (id,display) select id,display from temp_cool_beans;";
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
    auto generated_sql = generator_service.build_drop_column(definition, *display_property);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_drop_column_test" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_drop_index_test() {
    // arrange
    const std::string expected_result = "drop index if exists display_id_idx on cool_beans;";
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");
    std::vector<org::yaorm::PropertyDefinition> index_columns;

    auto id_property = definition.add_property_definitions();
    id_property->set_name("id");
    id_property->set_type(org::yaorm::ProtobufType::STRING);
    id_property->set_is_key(true);
    index_columns.push_back(*id_property);

    auto display_property = definition.add_property_definitions();
    display_property->set_name("display");
    display_property->set_type(org::yaorm::ProtobufType::STRING);
    index_columns.push_back(*display_property);

    SQLiteGeneratorService generator_service;

    // act
    auto generated_sql = generator_service.build_drop_index(definition, index_columns);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_drop_index_test" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_create_index_test() {
    // arrange
    const std::string expected_result = "create index if not exists display_id_idx on cool_beans(id,display);";
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
    org::yaorm::Index index;
    auto column_name = index.add_column_names();
    column_name->set_name("id");
    column_name->set_type(org::yaorm::ProtobufType::STRING);

    // act
    auto generated_sql = generator_service.build_create_index(definition, index);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_create_index" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_drop_table_test() {
    // arrange
    const std::string expected_result = "drop table if exists cool_beans;";
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");
    SQLiteGeneratorService generator_service;

    // act
    auto generated_sql = generator_service.build_drop_table(definition);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_drop_table" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_delete_all_test() {
    // arrange
    const std::string expected_result = "delete from cool_beans;";
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");
    SQLiteGeneratorService generator_service;

    // act
    auto generated_sql = generator_service.build_delete_all(definition);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_delete_all_test" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_delete_table_test() {
    // arrange
    const std::string expected_result = "delete from cool_beans where  display='mike' ;";
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");
    SQLiteGeneratorService generator_service;

    auto id_property = definition.add_property_definitions();
    id_property->set_name("id");
    id_property->set_type(org::yaorm::ProtobufType::STRING);
    id_property->set_is_key(true);

    auto display_property = definition.add_property_definitions();
    display_property->set_name("display");
    display_property->set_type(org::yaorm::ProtobufType::STRING);

    org::yaorm::PropertyHolder property_holder;
    property_holder.set_string_holder("mike");
    auto display_property_holder = property_holder.mutable_property_definition();
    display_property_holder->MergeFrom(*display_property);

    // act
    auto generated_sql = generator_service.build_delete_table(definition, property_holder);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_delete_table_test" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_delete_with_criteria() {
    // arrange
    const std::string expected_result = "delete from cool_beans where  display='mike' ;";
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");
    SQLiteGeneratorService generator_service;

    auto id_property = definition.add_property_definitions();
    id_property->set_name("id");
    id_property->set_type(org::yaorm::ProtobufType::STRING);
    id_property->set_is_key(true);

    auto display_property = definition.add_property_definitions();
    display_property->set_name("display");
    display_property->set_type(org::yaorm::ProtobufType::STRING);

    org::yaorm::WhereClauseItem where_clause;
    where_clause.set_operator_type(where_clause.EQUALS);
    auto property_holder = where_clause.mutable_name_and_property();
    property_holder->set_string_holder("mike");
    auto display_property_holder = property_holder->mutable_property_definition();
    display_property_holder->MergeFrom(*display_property);

    // act
    auto generated_sql = generator_service.build_delete_with_criteria(definition, where_clause);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_delete_table_test" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_bulk_insert() {
    // arrange
    const std::string expected_result = "insert into cool_beans (id,display) \n"
            "  select 'mike' as display,'11111' as id\n"
            "union select 'jacob' as display,'22222' as id \n"
            "union select 'john' as display,'33333' as id \n"
            "union select 'josh' as display,'44444' as id ;";
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");
    SQLiteGeneratorService generator_service;

    auto id_property = definition.add_property_definitions();
    id_property->set_name("id");
    id_property->set_type(org::yaorm::ProtobufType::STRING);
    id_property->set_is_key(true);

    auto display_property = definition.add_property_definitions();
    display_property->set_name("display");
    display_property->set_type(org::yaorm::ProtobufType::STRING);

    org::yaorm::Records records;
    add_record(records, *id_property, *display_property, "11111", "mike");
    add_record(records, *id_property, *display_property, "22222", "jacob");
    add_record(records, *id_property, *display_property, "33333", "john");
    add_record(records, *id_property, *display_property, "44444", "josh");

    // act
    auto generated_sql = generator_service.build_bulk_insert(definition, records);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_bulk_insert" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_insert() {
    // arrange
    const std::string expected_result = "insert into cool_beans(id,display) values ('11111','mike');";
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");
    SQLiteGeneratorService generator_service;

    auto id_property = definition.add_property_definitions();
    id_property->set_name("id");
    id_property->set_type(org::yaorm::ProtobufType::STRING);
    id_property->set_is_key(true);

    auto display_property = definition.add_property_definitions();
    display_property->set_name("display");
    display_property->set_type(org::yaorm::ProtobufType::STRING);

    org::yaorm::Records records;
    add_record(records, *id_property, *display_property, "11111", "mike");
    auto inserted_record = records.records(0);

    // act
    auto generated_sql = generator_service.build_insert(definition, inserted_record);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_insert" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_update() {
    // arrange
    const std::string expected_result = "update cool_beans set id='11111',display='mike' where  id='11111' ;";
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");
    SQLiteGeneratorService generator_service;

    auto id_property = definition.add_property_definitions();
    id_property->set_name("id");
    id_property->set_type(org::yaorm::ProtobufType::STRING);
    id_property->set_is_key(true);

    auto display_property = definition.add_property_definitions();
    display_property->set_name("display");
    display_property->set_type(org::yaorm::ProtobufType::STRING);

    org::yaorm::Records records;
    add_record(records, *id_property, *display_property, "11111", "mike");
    auto inserted_record = records.records(0);

    org::yaorm::PropertyHolder id_property_holder;
    auto mutable_id_property = id_property_holder.mutable_property_definition();
    mutable_id_property->MergeFrom(*id_property);
    id_property_holder.set_string_holder("11111");

    // act
    auto generated_sql = generator_service.build_update(definition, id_property_holder, inserted_record);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_update" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_update_with_criteria() {
    // arrange
    const std::string expected_result = "update cool_beans set id='11111',display='mike' where  display='mike' ;";
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");
    SQLiteGeneratorService generator_service;

    auto id_property = definition.add_property_definitions();
    id_property->set_name("id");
    id_property->set_type(org::yaorm::ProtobufType::STRING);
    id_property->set_is_key(true);

    auto display_property = definition.add_property_definitions();
    display_property->set_name("display");
    display_property->set_type(org::yaorm::ProtobufType::STRING);

    org::yaorm::Records records;
    add_record(records, *id_property, *display_property, "11111", "mike");
    auto inserted_record = records.records(0);

    org::yaorm::WhereClauseItem where_clause;
    where_clause.set_operator_type(where_clause.EQUALS);
    auto property_holder = where_clause.mutable_name_and_property();
    property_holder->set_string_holder("mike");
    auto display_property_holder = property_holder->mutable_property_definition();
    display_property_holder->MergeFrom(*display_property);

    // act
    auto generated_sql = generator_service.build_update_with_criteria(definition, inserted_record, where_clause);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_update_with_criteria" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_select_all() {
    // arrange
    const std::string expected_result = "select * from cool_beans limit 1000;";
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");
    SQLiteGeneratorService generator_service;

    // act
    auto generated_sql = generator_service.build_select_all(definition);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_select_all" << std::endl;
    }
    assert(expected_result == generated_sql);
}

void SQLiteGeneratorServiceTests::simple_where_clause() {
    // arrange
    const std::string expected_result = "select * from cool_beans where  display='mike' ;";
    org::yaorm::Definition definition;
    definition.set_name("cool_beans");
    SQLiteGeneratorService generator_service;

    auto id_property = definition.add_property_definitions();
    id_property->set_name("id");
    id_property->set_type(org::yaorm::ProtobufType::STRING);
    id_property->set_is_key(true);

    auto display_property = definition.add_property_definitions();
    display_property->set_name("display");
    display_property->set_type(org::yaorm::ProtobufType::STRING);

    org::yaorm::WhereClauseItem where_clause;
    where_clause.set_operator_type(where_clause.EQUALS);
    auto property_holder = where_clause.mutable_name_and_property();
    property_holder->set_string_holder("mike");
    auto display_property_holder = property_holder->mutable_property_definition();
    display_property_holder->MergeFrom(*display_property);

    // act
    auto generated_sql = generator_service.build_where_clause(definition, where_clause);

    // assert
    if (expected_result != generated_sql) {
        std::cout << generated_sql << std::endl;
    }
    else {
        std::cout << "passed simple_where_clause" << std::endl;
    }
    assert(expected_result == generated_sql);
}































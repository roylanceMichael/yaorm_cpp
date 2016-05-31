//
// Created by Mike Roylance on 5/29/16.
//

#include <iostream>
#include "sqlite/sqlite_generator_service_tests.h"
#include "sqlite/sqlite_granular_database_service_tests.h"

using namespace std;

int main() {
    SQLiteGeneratorServiceTests tests;
    tests.simple_delete_table_test();
    tests.simple_create_table_test();
    tests.simple_count_sql_test();
    tests.simple_create_column_test();
    tests.simple_drop_column_test();
    tests.simple_drop_index_test();
    tests.simple_create_index_test();
    tests.simple_drop_table_test();
    tests.simple_delete_all_test();
    tests.simple_delete_with_criteria();
    tests.simple_bulk_insert();
    tests.simple_insert();
    tests.simple_update();
    tests.simple_update_with_criteria();
    tests.simple_select_all();
    tests.simple_where_clause();

    SQLiteGranularDatabaseServiceTests granular_tests;
    granular_tests.simple_select_query_test();
}

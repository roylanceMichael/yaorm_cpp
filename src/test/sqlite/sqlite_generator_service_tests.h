//
// Created by Mike Roylance on 5/29/16.
//

#ifndef YAORM_CPP_SQLITE_GENERATOR_SERVICE_TESTS_H
#define YAORM_CPP_SQLITE_GENERATOR_SERVICE_TESTS_H

#include <iostream>
#include "../../cpp/services/sqlite/sqlite_generator_service.h"

class SQLiteGeneratorServiceTests {
public:
    void simple_create_table_test();
    void simple_count_sql_test();
    void simple_create_column_test();
    void simple_drop_column_test();
    void simple_drop_index_test();
    void simple_create_index_test();
    void simple_drop_table_test();
    void simple_delete_all_test();
    void simple_delete_table_test();
    void simple_delete_with_criteria();
    void simple_bulk_insert();
    void simple_insert();
    void simple_update();
    void simple_update_with_criteria();
    void simple_select_all();
    void simple_where_clause();
};


#endif //YAORM_CPP_SQLITE_GENERATOR_SERVICE_TESTS_H

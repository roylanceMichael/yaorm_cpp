//
// Created by Mike Roylance on 5/30/16.
//

#ifndef YAORM_CPP_SQLITE_GRANULAR_DATABASE_SERVICE_TESTS_H
#define YAORM_CPP_SQLITE_GRANULAR_DATABASE_SERVICE_TESTS_H

#include <future>

#include "../../../src/cpp/models/sqlite_models.pb.h"
#include "../../../src/cpp/services/sqlite/sqlite_granular_database_service.h"
#include "../../../src/cpp/services/sqlite/sqlite_generator_service.h"
#include "sqlite_test_map_streamer.h"
#include "test_utilities.h"

class SQLiteGranularDatabaseServiceTests {
public:
    void simple_select_query_test();
};


#endif //YAORM_CPP_SQLITE_GRANULAR_DATABASE_SERVICE_TESTS_H

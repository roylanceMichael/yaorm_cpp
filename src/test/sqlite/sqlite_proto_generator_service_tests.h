//
// Created by Mike Roylance on 6/4/16.
//

#ifndef YAORM_CPP_SQLITE_PROTO_GENERATOR_SERVICE_TESTS_H
#define YAORM_CPP_SQLITE_PROTO_GENERATOR_SERVICE_TESTS_H

#include <iostream>
#include "../models/test_models.pb.h"
#include "../../cpp/services/sqlite/sqlite_proto_generator_service.h"

class SQLiteProtoGeneratorServiceTests {
public:
    void simple_create_table_test();
    void simple_check_ok();
    void simple_check_child_ok();
};


#endif //YAORM_CPP_SQLITE_PROTO_GENERATOR_SERVICE_TESTS_H

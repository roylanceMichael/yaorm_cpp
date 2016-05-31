//
// Created by Mike Roylance on 5/31/16.
//

#ifndef YAORM_CPP_TEST_UTILITIES_H
#define YAORM_CPP_TEST_UTILITIES_H

#include "../../../src/cpp/models/yaorm_models.pb.h"

class TestUtilities final {
public:
    org::yaorm::Definition build_simple_test_definition();
    org::yaorm::Records build_simple_records();
};

#endif //YAORM_CPP_TEST_UTILITIES_H

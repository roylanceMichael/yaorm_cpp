//
// Created by Mike Roylance on 5/29/16.
//

#include <iostream>
#include "../../src/cpp/services/sqlite/sqlite_generator_service.h"
#include "sqlite/sqlite_generator_service_tests.h"

using namespace std;

int main() {
    SQLiteGeneratorServiceTests tests;
    tests.simple_test();
}

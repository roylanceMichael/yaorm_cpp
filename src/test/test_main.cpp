//
// Created by Mike Roylance on 5/29/16.
//

#include <iostream>
#include "sqlite/sqlite_generator_service_tests.h"

using namespace std;

int main() {
    SQLiteGeneratorServiceTests tests;
    tests.simple_create_table_test();
}

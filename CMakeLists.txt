cmake_minimum_required(VERSION 3.5)
project(yaorm_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
set(CMAKE_EXE_LINKER_FLAGS "-L/usr/local/lib -lgrpc++ -lgrpc -lprotobuf -lpthread -ldl")

set(SOURCE_FILES
        src/cpp/models/yaorm_models.pb.h
        src/cpp/models/yaorm_models.pb.cc
        src/cpp/services/i_sql_generator_service.h
        src/cpp/services/sqlite/sqlite_generator_service.cpp
        src/cpp/services/sqlite/sqlite_generator_service.h
        src/cpp/models/sqlite_models.pb.h
        src/cpp/models/sqlite_models.pb.cc
        src/cpp/utilities/common_sql_utilities.cpp
        src/cpp/utilities/common_sql_utilities.h)
add_library(yaorm_cpp STATIC ${SOURCE_FILES})

enable_testing()
set(TEST_SOURCE_FILES ${SOURCE_FILES}
        src/test/sqlite/sqlite_generator_service_tests.cpp
        src/test/sqlite/sqlite_generator_service_tests.h src/test/test_main.cpp)
add_executable(yaorm_cpp_test ${TEST_SOURCE_FILES})


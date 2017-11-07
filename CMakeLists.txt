cmake_minimum_required(VERSION 3.5)
project(yaorm_cpp)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
set(CMAKE_EXE_LINKER_FLAGS "-L/usr/local/lib -lpthread -ldl")

set(protobuf_source_dir vendor/Protobuf/source/protobuf-3.4.1)

include_directories(${protobuf_source_dir}/src)

set(PROTOBUF_SOURCE
        ${protobuf_source_dir}/src/google/protobuf/arena.cc
        ${protobuf_source_dir}/src/google/protobuf/arenastring.cc
        ${protobuf_source_dir}/src/google/protobuf/extension_set.cc
        ${protobuf_source_dir}/src/google/protobuf/generated_message_util.cc
        ${protobuf_source_dir}/src/google/protobuf/io/coded_stream.cc
        ${protobuf_source_dir}/src/google/protobuf/io/zero_copy_stream.cc
        ${protobuf_source_dir}/src/google/protobuf/io/zero_copy_stream_impl_lite.cc
        ${protobuf_source_dir}/src/google/protobuf/message_lite.cc
        ${protobuf_source_dir}/src/google/protobuf/repeated_field.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/atomicops_internals_x86_gcc.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/atomicops_internals_x86_msvc.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/bytestream.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/common.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/int128.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/once.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/status.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/statusor.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/stringpiece.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/stringprintf.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/structurally_valid.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/strutil.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/time.cc
        ${protobuf_source_dir}/src/google/protobuf/wire_format_lite.cc

        ${protobuf_source_dir}/src/google/protobuf/any.cc
        ${protobuf_source_dir}/src/google/protobuf/any.pb.cc
        ${protobuf_source_dir}/src/google/protobuf/api.pb.cc
        ${protobuf_source_dir}/src/google/protobuf/compiler/importer.cc
        ${protobuf_source_dir}/src/google/protobuf/compiler/parser.cc
        ${protobuf_source_dir}/src/google/protobuf/descriptor.cc
        ${protobuf_source_dir}/src/google/protobuf/descriptor.pb.cc
        ${protobuf_source_dir}/src/google/protobuf/descriptor_database.cc
        ${protobuf_source_dir}/src/google/protobuf/duration.pb.cc
        ${protobuf_source_dir}/src/google/protobuf/dynamic_message.cc
        ${protobuf_source_dir}/src/google/protobuf/empty.pb.cc
        ${protobuf_source_dir}/src/google/protobuf/extension_set_heavy.cc
        ${protobuf_source_dir}/src/google/protobuf/field_mask.pb.cc
        ${protobuf_source_dir}/src/google/protobuf/generated_message_reflection.cc
        ${protobuf_source_dir}/src/google/protobuf/generated_message_table_driven.cc
        ${protobuf_source_dir}/src/google/protobuf/io/gzip_stream.cc
        ${protobuf_source_dir}/src/google/protobuf/io/printer.cc
        ${protobuf_source_dir}/src/google/protobuf/io/strtod.cc
        ${protobuf_source_dir}/src/google/protobuf/io/tokenizer.cc
        ${protobuf_source_dir}/src/google/protobuf/io/zero_copy_stream_impl.cc
        ${protobuf_source_dir}/src/google/protobuf/map_field.cc
        ${protobuf_source_dir}/src/google/protobuf/message.cc
        ${protobuf_source_dir}/src/google/protobuf/reflection_ops.cc
        ${protobuf_source_dir}/src/google/protobuf/service.cc
        ${protobuf_source_dir}/src/google/protobuf/source_context.pb.cc
        ${protobuf_source_dir}/src/google/protobuf/struct.pb.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/mathlimits.cc
        ${protobuf_source_dir}/src/google/protobuf/stubs/substitute.cc
        ${protobuf_source_dir}/src/google/protobuf/text_format.cc
        ${protobuf_source_dir}/src/google/protobuf/timestamp.pb.cc
        ${protobuf_source_dir}/src/google/protobuf/type.pb.cc
        ${protobuf_source_dir}/src/google/protobuf/unknown_field_set.cc
        ${protobuf_source_dir}/src/google/protobuf/util/delimited_message_util.cc
        ${protobuf_source_dir}/src/google/protobuf/util/field_comparator.cc
        ${protobuf_source_dir}/src/google/protobuf/util/field_mask_util.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/datapiece.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/default_value_objectwriter.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/error_listener.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/field_mask_utility.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/json_escaping.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/json_objectwriter.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/json_stream_parser.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/object_writer.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/proto_writer.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/protostream_objectsource.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/protostream_objectwriter.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/type_info.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/type_info_test_helper.cc
        ${protobuf_source_dir}/src/google/protobuf/util/internal/utility.cc
        ${protobuf_source_dir}/src/google/protobuf/util/json_util.cc
        ${protobuf_source_dir}/src/google/protobuf/util/json_util.h
        ${protobuf_source_dir}/src/google/protobuf/util/message_differencer.cc
        ${protobuf_source_dir}/src/google/protobuf/util/time_util.cc
        ${protobuf_source_dir}/src/google/protobuf/util/type_resolver_util.cc
        ${protobuf_source_dir}/src/google/protobuf/wire_format.cc
        ${protobuf_source_dir}/src/google/protobuf/wrappers.pb.cc)

add_library(protobuf SHARED ${PROTOBUF_SOURCE})

set(SOURCE_FILES
        src/cpp/models/yaorm_models.pb.h
        src/cpp/models/yaorm_models.pb.cc
        src/cpp/services/i_sql_generator_service.h
        src/cpp/services/sqlite/sqlite_generator_service.cpp
        src/cpp/services/sqlite/sqlite_generator_service.h
        src/cpp/models/sqlite_models.pb.h
        src/cpp/models/sqlite_models.pb.cc
        src/cpp/utilities/common_sql_utilities.cpp
        src/cpp/utilities/common_sql_utilities.h
        src/cpp/services/i_granular_database_service.h
        src/cpp/services/i_map_streamer.h
        src/cpp/services/i_cursor.h
        src/cpp/services/i_entity_service.h
        src/cpp/services/i_entity_message_service.h
        src/cpp/services/i_entity_context.h
        src/cpp/services/entity_context.cpp
        src/cpp/services/sqlite/sqlite_generator_service2.cpp
        src/cpp/services/sqlite/sqlite_generator_service2.h)

add_library(yaorm_sqlite_cpp SHARED ${SOURCE_FILES})
target_link_libraries(yaorm_sqlite_cpp protobuf)

set(sqlite_source_dir vendor/SQLite)
if (WIN32)
else(WIN32)
    add_definitions(-DHAVE_PTHREAD)
endif(WIN32)

include_directories(${sqlite_source_dir})

set(SQLITE_SOURCE
        ${sqlite_source_dir}/sqlite3.c)

add_library(sqlite3 SHARED ${SQLITE_SOURCE})

enable_testing()
set(TEST_SOURCE_FILES ${SOURCE_FILES}
        src/test/sqlite/sqlite_granular_database_service.cpp
        src/test/sqlite/sqlite_granular_database_service.h
        src/test/sqlite/sqlite_generator_service_tests.cpp
        src/test/sqlite/sqlite_generator_service_tests.h
        src/test/sqlite/sqlite_granular_database_service_tests.cpp
        src/test/sqlite/sqlite_granular_database_service_tests.h
        src/test/test_main.cpp
        src/test/sqlite/test_utilities.cpp
        src/test/sqlite/test_utilities.h
        src/test/sqlite/sqlite_test_map_streamer.cpp
        src/test/sqlite/sqlite_test_map_streamer.h
        src/test/models/test_models.pb.h
        src/test/models/test_models.pb.cc)
add_executable(yaorm_cpp_test ${TEST_SOURCE_FILES})
target_link_libraries(yaorm_cpp_test protobuf sqlite3)

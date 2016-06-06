//
// Created by Mike Roylance on 6/1/16.
//

#include "sqlite_proto_generator_service.h"

SQLiteProtoGeneratorService::SQLiteProtoGeneratorService() {
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_BOOL] = org::yaorm::sqlite::SQLiteType_descriptor()->value(2)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_DOUBLE] = org::yaorm::sqlite::SQLiteType_descriptor()->value(3)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_FLOAT] = org::yaorm::sqlite::SQLiteType_descriptor()->value(3)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_INT32] = org::yaorm::sqlite::SQLiteType_descriptor()->value(2)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_INT64] = org::yaorm::sqlite::SQLiteType_descriptor()->value(2)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_FIXED32] = org::yaorm::sqlite::SQLiteType_descriptor()->value(2)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_FIXED64] = org::yaorm::sqlite::SQLiteType_descriptor()->value(2)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_SFIXED32] = org::yaorm::sqlite::SQLiteType_descriptor()->value(2)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_SFIXED64] = org::yaorm::sqlite::SQLiteType_descriptor()->value(2)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_SINT32] = org::yaorm::sqlite::SQLiteType_descriptor()->value(2)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_SINT64] = org::yaorm::sqlite::SQLiteType_descriptor()->value(2)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_UINT32] = org::yaorm::sqlite::SQLiteType_descriptor()->value(2)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_UINT64] = org::yaorm::sqlite::SQLiteType_descriptor()->value(2)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_BYTES] = org::yaorm::sqlite::SQLiteType_descriptor()->value(4)->name();
    compiled_maps[google::protobuf::FieldDescriptor::TYPE_STRING] = org::yaorm::sqlite::SQLiteType_descriptor()->value(1)->name();
}

std::string SQLiteProtoGeneratorService::build_create_table(google::protobuf::Descriptor &descriptor) {
    auto workspace = common_sql_utilities.build_column_name_type(descriptor, compiled_maps, primary_key);
    return "create table if not exists " + descriptor->name() + " (" + workspace + ");";
}

bool SQLiteProtoGeneratorService::can_persist_proto(google::protobuf::Descriptor &descriptor) {
    return common_sql_utilities.check_if_ok(descriptor);
}

bool SQLiteProtoGeneratorService::can_persist_as_child(google::protobuf::Descriptor &descriptor) {
    return common_sql_utilities.check_if_child_ok(descriptor);
}










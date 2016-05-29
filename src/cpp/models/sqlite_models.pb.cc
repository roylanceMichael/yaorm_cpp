// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sqlite_models.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "sqlite_models.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace org {
namespace yaorm {
namespace sqlite {

namespace {

const ::google::protobuf::EnumDescriptor* SQLiteType_descriptor_ = NULL;
const ::google::protobuf::EnumDescriptor* SQLiteTypeMapping_descriptor_ = NULL;

}  // namespace


void protobuf_AssignDesc_sqlite_5fmodels_2eproto() {
  protobuf_AddDesc_sqlite_5fmodels_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "sqlite_models.proto");
  GOOGLE_CHECK(file != NULL);
  SQLiteType_descriptor_ = file->enum_type(0);
  SQLiteTypeMapping_descriptor_ = file->enum_type(1);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_sqlite_5fmodels_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_sqlite_5fmodels_2eproto() {
}

void protobuf_AddDesc_sqlite_5fmodels_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\023sqlite_models.proto\022\020org.yaorm.sqlite*"
    "H\n\nSQLiteType\022\017\n\013SQLITE_NONE\020\000\022\010\n\004TEXT\020\001"
    "\022\013\n\007INTEGER\020\002\022\010\n\004REAL\020\003\022\010\n\004BLOB\020\004*\344\001\n\021SQ"
    "LiteTypeMapping\022\027\n\023SQLITE_MAPPING_NONE\020\000"
    "\022\n\n\006DOUBLE\020\003\022\t\n\005FLOAT\020\003\022\t\n\005INT32\020\002\022\t\n\005IN"
    "T64\020\002\022\n\n\006UINT32\020\002\022\n\n\006UINT64\020\002\022\n\n\006SINT32\020"
    "\002\022\n\n\006SINT64\020\002\022\013\n\007FIXED32\020\002\022\013\n\007FIXED64\020\002\022"
    "\014\n\010SFIXED32\020\002\022\014\n\010SFIXED64\020\002\022\010\n\004BOOL\020\002\022\n\n"
    "\006STRING\020\001\022\t\n\005BYTES\020\004\032\002\020\001b\006proto3", 352);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "sqlite_models.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_sqlite_5fmodels_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_sqlite_5fmodels_2eproto {
  StaticDescriptorInitializer_sqlite_5fmodels_2eproto() {
    protobuf_AddDesc_sqlite_5fmodels_2eproto();
  }
} static_descriptor_initializer_sqlite_5fmodels_2eproto_;
const ::google::protobuf::EnumDescriptor* SQLiteType_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SQLiteType_descriptor_;
}
bool SQLiteType_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}

const ::google::protobuf::EnumDescriptor* SQLiteTypeMapping_descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SQLiteTypeMapping_descriptor_;
}
bool SQLiteTypeMapping_IsValid(int value) {
  switch(value) {
    case 0:
    case 1:
    case 2:
    case 3:
    case 4:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace sqlite
}  // namespace yaorm
}  // namespace org

// @@protoc_insertion_point(global_scope)

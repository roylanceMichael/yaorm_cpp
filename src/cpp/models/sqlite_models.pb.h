// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sqlite_models.proto

#ifndef PROTOBUF_sqlite_5fmodels_2eproto__INCLUDED
#define PROTOBUF_sqlite_5fmodels_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)

namespace org {
namespace yaorm {
namespace sqlite {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_sqlite_5fmodels_2eproto();
void protobuf_AssignDesc_sqlite_5fmodels_2eproto();
void protobuf_ShutdownFile_sqlite_5fmodels_2eproto();


enum SQLiteType {
  SQLITE_NONE = 0,
  TEXT = 1,
  INTEGER = 2,
  REAL = 3,
  BLOB = 4,
  SQLiteType_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SQLiteType_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SQLiteType_IsValid(int value);
const SQLiteType SQLiteType_MIN = SQLITE_NONE;
const SQLiteType SQLiteType_MAX = BLOB;
const int SQLiteType_ARRAYSIZE = SQLiteType_MAX + 1;

const ::google::protobuf::EnumDescriptor* SQLiteType_descriptor();
inline const ::std::string& SQLiteType_Name(SQLiteType value) {
  return ::google::protobuf::internal::NameOfEnum(
    SQLiteType_descriptor(), value);
}
inline bool SQLiteType_Parse(
    const ::std::string& name, SQLiteType* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SQLiteType>(
    SQLiteType_descriptor(), name, value);
}
enum SQLiteTypeMapping {
  SQLITE_MAPPING_NONE = 0,
  DOUBLE = 3,
  FLOAT = 3,
  INT32 = 2,
  INT64 = 2,
  UINT32 = 2,
  UINT64 = 2,
  SINT32 = 2,
  SINT64 = 2,
  FIXED32 = 2,
  FIXED64 = 2,
  SFIXED32 = 2,
  SFIXED64 = 2,
  BOOL = 2,
  STRING = 1,
  BYTES = 4,
  SQLiteTypeMapping_INT_MIN_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32min,
  SQLiteTypeMapping_INT_MAX_SENTINEL_DO_NOT_USE_ = ::google::protobuf::kint32max
};
bool SQLiteTypeMapping_IsValid(int value);
const SQLiteTypeMapping SQLiteTypeMapping_MIN = SQLITE_MAPPING_NONE;
const SQLiteTypeMapping SQLiteTypeMapping_MAX = BYTES;
const int SQLiteTypeMapping_ARRAYSIZE = SQLiteTypeMapping_MAX + 1;

const ::google::protobuf::EnumDescriptor* SQLiteTypeMapping_descriptor();
inline const ::std::string& SQLiteTypeMapping_Name(SQLiteTypeMapping value) {
  return ::google::protobuf::internal::NameOfEnum(
    SQLiteTypeMapping_descriptor(), value);
}
inline bool SQLiteTypeMapping_Parse(
    const ::std::string& name, SQLiteTypeMapping* value) {
  return ::google::protobuf::internal::ParseNamedEnum<SQLiteTypeMapping>(
    SQLiteTypeMapping_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace sqlite
}  // namespace yaorm
}  // namespace org

#ifndef SWIG
namespace google {
namespace protobuf {

template <> struct is_proto_enum< ::org::yaorm::sqlite::SQLiteType> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::org::yaorm::sqlite::SQLiteType>() {
  return ::org::yaorm::sqlite::SQLiteType_descriptor();
}
template <> struct is_proto_enum< ::org::yaorm::sqlite::SQLiteTypeMapping> : ::google::protobuf::internal::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::org::yaorm::sqlite::SQLiteTypeMapping>() {
  return ::org::yaorm::sqlite::SQLiteTypeMapping_descriptor();
}

}  // namespace protobuf
}  // namespace google
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_sqlite_5fmodels_2eproto__INCLUDED

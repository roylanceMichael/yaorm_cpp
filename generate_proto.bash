#!/usr/bin/env bash
protoc -I=src/proto --proto_path=src/proto --cpp_out=src/cpp/models src/proto/sqlite_models.proto src/proto/yaorm_models.proto
protoc -I=src/proto --proto_path=src/proto --cpp_out=src/test/models src/proto/test_models.proto

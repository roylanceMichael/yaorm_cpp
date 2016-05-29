#!/usr/bin/env bash
protoc -I=src/proto --proto_path=src/proto --cpp_out=src/cpp/models src/proto/*.proto

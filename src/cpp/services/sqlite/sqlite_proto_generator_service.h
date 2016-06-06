//
// Created by Mike Roylance on 6/1/16.
//

#ifndef YAORM_CPP_SQLITE_PROTO_GENERATOR_SERVICE_H
#define YAORM_CPP_SQLITE_PROTO_GENERATOR_SERVICE_H

#include "../../utilities/common_sql_utilities.h"
#include "../i_sql_proto_generator_service.h"
#include "../../models/sqlite_models.pb.h"
#include "../../models/yaorm_models.pb.h"

class SQLiteProtoGeneratorService final: public ISQLProtoGeneratorService {
public:
    SQLiteProtoGeneratorService();
    bool can_persist_proto(google::protobuf::Descriptor& descriptor);
    bool can_persist_as_child(google::protobuf::Descriptor& descriptor);
    std::string build_create_table(google::protobuf::Descriptor& descriptor);
private:
    std::map<int,std::string> compiled_maps;
    CommonSQLUtilities common_sql_utilities;
    const std::string primary_key = "primary key";
};


#endif //YAORM_CPP_SQLITE_PROTO_GENERATOR_SERVICE_H

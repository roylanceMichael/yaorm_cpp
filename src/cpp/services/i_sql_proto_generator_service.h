//
// Created by Mike Roylance on 6/1/16.
//

#ifndef YAORM_CPP_I_PROTO_SQL_GENERATOR_SERVICE_H
#define YAORM_CPP_I_PROTO_SQL_GENERATOR_SERVICE_H

#include <iostream>
#include "../models/yaorm_models.pb.h"

class ISQLProtoGeneratorService {
    virtual std::string build_create_table(google::protobuf::Metadata& metadata) = 0;
};

#endif //YAORM_CPP_I_PROTO_SQL_GENERATOR_SERVICE_H

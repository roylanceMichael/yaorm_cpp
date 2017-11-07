//
// Created by Mike Roylance on 11/6/17.
//

#ifndef YAORM_CPP_I_ENTITY_CONTEXT_H
#define YAORM_CPP_I_ENTITY_CONTEXT_H

#include "i_entity_service.h"

class IEntityContext {
public:
    IEntityContext(google::protobuf::FileDescriptor &file_descriptor, IEntityService &entity_service,
                       std::map<std::string, org::yaorm::Index> &indexes, std::string &context_name);



private:
    IEntityService &entity_service;
    google::protobuf::FileDescriptor &file_descriptor;
    std::map<std::string, org::yaorm::Index> &indexes;
    std::string &context_name;
};

#endif //YAORM_CPP_I_ENTITY_CONTEXT_H

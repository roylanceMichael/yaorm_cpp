//
// Created by Mike Roylance on 11/6/17.
//
#include "i_entity_context.h"

IEntityContext::IEntityContext(google::protobuf::FileDescriptor &file_descriptor, IEntityService &entity_service,
                               std::map<std::string, org::yaorm::Index> &indexes, std::string &context_name)
        : file_descriptor(file_descriptor), entity_service(entity_service), indexes(indexes),
          context_name(context_name) {

}
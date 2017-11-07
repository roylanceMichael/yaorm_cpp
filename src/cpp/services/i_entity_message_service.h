//
// Created by Mike Roylance on 11/6/17.
//

#ifndef YAORM_CPP_I_ENTITY_MESSAGE_SERVICE_H
#define YAORM_CPP_I_ENTITY_MESSAGE_SERVICE_H


#include "../models/yaorm_models.pb.h"
#include "i_map_streamer.h"
#include "i_entity_service.h"

class IEntityMessagesService {
public:
    virtual bool create_entire(google::protobuf::FileDescriptor &file_descriptor) = 0;

    virtual bool drop_create_entire(google::protobuf::FileDescriptor &file_descriptor) = 0;

    virtual bool bulk_insert(std::vector<google::protobuf::Message> &messages) = 0;

    virtual bool merge(google::protobuf::Message &message) = 0;

    virtual bool merge_table(std::vector<google::protobuf::Message> &messages, google::protobuf::Message &message) = 0;

    virtual bool delete_message(google::protobuf::Message &message) = 0;

    virtual google::protobuf::Message &get(google::protobuf::Message &message, std::string id) = 0;

    virtual std::vector<std::string> &get_keys(google::protobuf::Message &message) = 0;

    virtual void get_keys_stream(google::protobuf::Message &message, IMapStreamer &streamer) = 0;

    virtual std::vector<google::protobuf::Message> &get_many(google::protobuf::Message &message,
                                                             std::vector<std::string> ids) = 0;

    virtual std::vector<google::protobuf::Message> &get_many(google::protobuf::Message &message,
                                                             int limit,
                                                             int offset) = 0;

    virtual void get_many_stream(google::protobuf::Message &message,
                                  int limit,
                                  int offset,
                                  IMapStreamer &streamer) = 0;


    virtual std::vector<google::protobuf::Message> &get_many_single_level(google::protobuf::Message &message,
                                                                          int limit,
                                                                          int offset) = 0;

    virtual std::vector<google::protobuf::Message> &where(google::protobuf::Message &message,
                                                          org::yaorm::WhereClause &whereClause) = 0;

    virtual int get_count(google::protobuf::Message &message) = 0;

    virtual std::vector<google::protobuf::Message> &get_custom_single_level(google::protobuf::Message &message,
                                                                            std::string sql) = 0;


    virtual org::yaorm::DatabaseExecutionReport &get_report() = 0;

private:
    IEntityService &entity_service;
};

#endif //YAORM_CPP_I_ENTITY_MESSAGE_SERVICE_H

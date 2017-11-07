//
// Created by Mike Roylance on 5/30/16.
//

#ifndef YAORM_CPP_I_GRANULAR_DATABASE_SERVICE_H
#define YAORM_CPP_I_GRANULAR_DATABASE_SERVICE_H

#include "../models/yaorm_models.pb.h"
#include "i_map_streamer.h"

class IGranularDatabaseService {
public:
    virtual bool is_available() = 0;

    virtual bool execute_update_query(std::string &query) = 0;

    virtual bool execute_select_query_stream(std::string &query, IMapStreamer &streamer) = 0;

    virtual bool close() = 0;
};

#endif //YAORM_CPP_I_GRANULAR_DATABASE_SERVICE_H

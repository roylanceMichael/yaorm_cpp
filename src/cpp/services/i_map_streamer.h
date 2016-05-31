//
// Created by Mike Roylance on 5/30/16.
//

#ifndef YAORM_CPP_I_MAP_STREAMER_H
#define YAORM_CPP_I_MAP_STREAMER_H

#include "../models/yaorm_models.pb.h"

class IMapStreamer {
public:
    virtual std::map<std::string, org::yaorm::PropertyDefinition>& get_properties() = 0;
    virtual void stream(org::yaorm::Record& record) = 0;
};

#endif //YAORM_CPP_I_MAP_STREAMER_H

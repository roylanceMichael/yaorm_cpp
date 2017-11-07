//
// Created by Mike Roylance on 11/6/17.
//

#ifndef YAORM_CPP_I_CURSOR_H
#define YAORM_CPP_I_CURSOR_H

#include "i_map_streamer.h"

class ICursor {
public:
    virtual org::yaorm::Records &get_records() = 0;

    virtual void get_records_stream(IMapStreamer &streamer) = 0;
};

#endif //YAORM_CPP_I_CURSOR_H

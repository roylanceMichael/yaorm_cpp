//
// Created by Mike Roylance on 5/31/16.
//

#ifndef YAORM_CPP_SQLITE_TEST_MAP_STREAMER_H
#define YAORM_CPP_SQLITE_TEST_MAP_STREAMER_H

#include "../../../src/cpp/services/i_map_streamer.h"
#include <future>

class SQLiteTestMapStreamer final: public IMapStreamer {
public:
    SQLiteTestMapStreamer(org::yaorm::Definition& definition, std::promise<org::yaorm::Record>& promise);
    std::map<std::string, org::yaorm::PropertyDefinition>& get_properties();
    void stream(org::yaorm::Record& record);
private:
    std::map<std::string, org::yaorm::PropertyDefinition> properties;
    std::promise<org::yaorm::Record>& saved_promise;
};


#endif //YAORM_CPP_SQLITE_TEST_MAP_STREAMER_H

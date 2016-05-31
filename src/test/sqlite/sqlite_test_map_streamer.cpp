//
// Created by Mike Roylance on 5/31/16.
//

#include "sqlite_test_map_streamer.h"

SQLiteTestMapStreamer::SQLiteTestMapStreamer(
        org::yaorm::Definition &definition,
        std::promise<org::yaorm::Record>& promise):saved_promise(promise) {
    for(auto item:definition.property_definitions()) {
        properties[item.name()] = item;
    }
}

std::map<std::string, org::yaorm::PropertyDefinition> &SQLiteTestMapStreamer::get_properties() {
    return properties;
}

void SQLiteTestMapStreamer::stream(org::yaorm::Record &record) {
    saved_promise.set_value(record);
}






//
// Created by Mike Roylance on 5/30/16.
//

#include "sqlite_granular_database_service.h"
#include <sqlite3.h>

static int callback_static(void *NotUsed, int argc, char **argv, char **azColName){
    IMapStreamer* streamer = (IMapStreamer*)NotUsed;
    auto properties = streamer->get_properties();
    org::yaorm::Record record;

    for(auto i = 0; i < argc; i++) {
        auto name = azColName[i];
        if (properties.find(name) != properties.end()) {
            auto property = properties[name];
            auto property_holder = record.add_columns();
            auto definition = property_holder->mutable_property_definition();
            definition->MergeFrom(property);

            switch (property.type()) {
                case org::yaorm::ProtobufType_INT_MIN_SENTINEL_DO_NOT_USE_:break;
                case org::yaorm::ProtobufType_INT_MAX_SENTINEL_DO_NOT_USE_:break;
                case org::yaorm::NONE:break;
                case org::yaorm::PROTO:break;
                case org::yaorm::ProtobufType::DOUBLE:
                    property_holder->set_double_holder(std::stod(argv[i]));
                    break;
                case org::yaorm::ProtobufType::FLOAT:
                    property_holder->set_float_holder(std::stof(argv[i]));
                    break;
                case org::yaorm::INT32:
                case org::yaorm::INT64:
                case org::yaorm::UINT32:
                case org::yaorm::UINT64:
                case org::yaorm::SINT32:
                case org::yaorm::SINT64:
                case org::yaorm::FIXED32:
                case org::yaorm::FIXED64:
                case org::yaorm::SFIXED32:
                case org::yaorm::SFIXED64:
                    property_holder->set_int32_holder(std::stoi(argv[i]));
                    break;
                case org::yaorm::BOOL:
                    property_holder->set_bool_holder(std::stoi(argv[i]) == 1);
                    break;
                case org::yaorm::STRING:
                    property_holder->set_string_holder(argv[i]);
                    break;
                case org::yaorm::BYTES:
                    property_holder->set_bytes_holder(argv[i]);
                    break;
            }
        }
    }

    streamer->stream(record);
    return 0;
}

SQLiteGranularService::SQLiteGranularService(const std::string file_name)  {
    rc = sqlite3_open(file_name.c_str(), &db);
}

bool SQLiteGranularService::is_available() {
    return rc == 0;
}

bool SQLiteGranularService::execute_update_query(const std::string query) {
    if (rc != 0) {
        return false;
    }
    char *zErrMsg = 0;
    sqlite3_exec(db, query.c_str(), 0, 0, &zErrMsg);
    return true;
}

bool SQLiteGranularService::execute_select_query_stream(const std::string query, IMapStreamer &streamer) {
    if (rc != 0) {
        return false;
    }
    char *zErrMsg = 0;
    sqlite3_exec(db, query.c_str(), callback_static, (void*)&streamer, &zErrMsg);
    return true;
}

bool SQLiteGranularService::close() {
    sqlite3_close(db);
    return true;
}









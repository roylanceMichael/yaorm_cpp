//
// Created by Mike Roylance on 5/30/16.
//

#ifndef YAORM_CPP_SQLITE_GRANULAR_DATABASE_SERVICE_H
#define YAORM_CPP_SQLITE_GRANULAR_DATABASE_SERVICE_H

#include <sqlite3.h>
#include "../../cpp/services/i_granular_database_service.h"

class SQLiteGranularService final: public IGranularDatabaseService  {
public:
    explicit SQLiteGranularService(std::string file_name);

    bool is_available() override;
    bool execute_update_query(std::string query) override;
    bool execute_select_query_stream(std::string query, IMapStreamer& streamer) override;
    bool close() override;
private:
//    int callback(void *data, int argc, char **argv, char **azColName);
    sqlite3 *db;
    int rc;
};


#endif //YAORM_CPP_SQLITE_GRANULAR_DATABASE_SERVICE_H

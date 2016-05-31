//
// Created by Mike Roylance on 5/30/16.
//

#ifndef YAORM_CPP_SQLITE_GRANULAR_DATABASE_SERVICE_H
#define YAORM_CPP_SQLITE_GRANULAR_DATABASE_SERVICE_H

#include "../i_granular_database_service.h"
#include <sqlite3.h>

class SQLiteGranularService final: public IGranularDatabaseService  {
public:
    SQLiteGranularService(const std::string file_name);

    bool is_available();
    bool execute_update_query(const std::string query);
    bool execute_select_query_stream(const std::string query, IMapStreamer& streamer);
    bool close();
private:
//    int callback(void *data, int argc, char **argv, char **azColName);
    sqlite3 *db;
    int rc;
};


#endif //YAORM_CPP_SQLITE_GRANULAR_DATABASE_SERVICE_H

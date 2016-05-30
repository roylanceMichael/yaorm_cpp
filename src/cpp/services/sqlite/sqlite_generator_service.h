//
// Created by Mike Roylance on 5/28/16.
//

#ifndef YAORM_CPP_SQLITE_GENERATOR_SERVICE_H
#define YAORM_CPP_SQLITE_GENERATOR_SERVICE_H

#include "../i_sql_generator_service.h"
#include "../../models/sqlite_models.pb.h"
#include "../../utilities/common_sql_utilities.h"

class SQLiteGeneratorService final: public ISQLGeneratorService {
public:
    SQLiteGeneratorService();

    int get_bulk_insert_size();
    std::string build_count_sql(org::yaorm::Definition& definition);

    std::string build_create_column(org::yaorm::Definition& definition, org::yaorm::PropertyDefinition& property_definition);

    std::string build_drop_column(org::yaorm::Definition& definition, org::yaorm::PropertyDefinition& property_definition);

    std::string build_create_index(org::yaorm::Definition& definition, org::yaorm::Index& index);
    std::string build_drop_index(org::yaorm::Definition& definition, std::vector<org::yaorm::PropertyDefinition>& columns);

    std::string build_drop_table(org::yaorm::Definition& definition);
    std::string build_create_table(org::yaorm::Definition& definition);

    std::string build_delete_all(org::yaorm::Definition& definition);
    std::string build_delete_table(org::yaorm::Definition& definition, org::yaorm::PropertyHolder& property_holder);
    std::string build_delete_with_criteria(org::yaorm::Definition& definition, org::yaorm::WhereClauseItem& where_clause);

    std::string build_bulk_insert(org::yaorm::Definition& definition, org::yaorm::Records& records);
    std::string build_insert(org::yaorm::Definition& definition, org::yaorm::Record& record);

    std::string build_update(org::yaorm::Definition& definition, org::yaorm::PropertyHolder& key, org::yaorm::Record& record);
    std::string build_update_with_criteria(org::yaorm::Definition& definition, org::yaorm::Record& record, org::yaorm::WhereClauseItem& where_clause);

    std::string build_select_all(org::yaorm::Definition& definition, int n = 1000);
    std::string build_where_clause(org::yaorm::Definition& definition, org::yaorm::WhereClauseItem& where_clause);

private:
    std::map<int,std::string> compiled_maps;
    CommonSQLUtilities common_sql_utilities;
    const std::string primary_key = "primary key";
};


#endif //YAORM_CPP_SQLITE_GENERATOR_SERVICE_H

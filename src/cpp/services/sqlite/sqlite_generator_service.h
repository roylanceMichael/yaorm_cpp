//
// Created by Mike Roylance on 5/28/16.
//

#ifndef YAORM_CPP_SQLITE_GENERATOR_SERVICE_H
#define YAORM_CPP_SQLITE_GENERATOR_SERVICE_H

#include "../i_sql_generator_service.h"
#include "../../models/sqlite_models.pb.h"
#include "../../utilities/common_sql_utilities.h"

class SQLiteGeneratorService final : public ISQLGeneratorService {
public:
    SQLiteGeneratorService();

    int get_bulk_insert_size() override;

    std::string build_count_sql(org::yaorm::TableDefinition &definition) override;

    std::string build_create_column(org::yaorm::TableDefinition &definition,
                                    org::yaorm::ColumnDefinition &property_definition) override;

    std::string build_drop_column(org::yaorm::TableDefinition &definition,
                                  org::yaorm::ColumnDefinition &property_definition) override;

    std::string build_create_index(org::yaorm::TableDefinition &definition, org::yaorm::Index &index) override;

    std::string build_drop_index(org::yaorm::TableDefinition &definition,
                                 std::vector<org::yaorm::ColumnDefinition> &columns) override;

    std::string build_drop_table(org::yaorm::TableDefinition &definition) override;

    std::string build_create_table(org::yaorm::TableDefinition &definition) override;

    std::string build_delete_all(org::yaorm::TableDefinition &definition) override;

    std::string
    build_delete_table(org::yaorm::TableDefinition &definition, org::yaorm::ColumnDefinition &property_holder) override;

    std::string build_delete_with_criteria(org::yaorm::TableDefinition &definition,
                                           org::yaorm::WhereClause &where_clause) override;

    std::string build_bulk_insert(org::yaorm::TableDefinition &definition, org::yaorm::Records &records) override;

    std::string build_insert(org::yaorm::TableDefinition &definition, org::yaorm::Record &record) override;

    std::string build_update(org::yaorm::TableDefinition &definition, org::yaorm::ColumnDefinition &key,
                             org::yaorm::Record &record) override;

    std::string build_update_with_criteria(org::yaorm::TableDefinition &definition, org::yaorm::Record &record,
                                           org::yaorm::WhereClause &where_clause) override;

    std::string build_select_all(org::yaorm::TableDefinition &definition, int n = 1000) override;

    std::string
    build_where_clause(org::yaorm::TableDefinition &definition, org::yaorm::WhereClause &where_clause) override;

private:
    std::map<int, std::string> compiled_maps;
    CommonSQLUtilities common_sql_utilities;
    const std::string primary_key = "primary key";
};


#endif //YAORM_CPP_SQLITE_GENERATOR_SERVICE_H

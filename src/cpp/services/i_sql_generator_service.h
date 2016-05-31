//
// Created by Mike Roylance on 5/28/16.
//

#ifndef YAORM_CPP_I_SQL_GENERATOR_SERVICE_H
#define YAORM_CPP_I_SQL_GENERATOR_SERVICE_H

#include "../models/yaorm_models.pb.h"

class ISQLGeneratorService {
public:
    virtual int get_bulk_insert_size() = 0;

    virtual std::string build_count_sql(org::yaorm::Definition& definition) = 0;

    virtual std::string build_create_column(org::yaorm::Definition& definition,
                                            org::yaorm::PropertyDefinition& property_definition) = 0;
    virtual std::string build_drop_column(org::yaorm::Definition& definition,
                                          org::yaorm::PropertyDefinition& property_definition) = 0;

    virtual std::string build_create_index(org::yaorm::Definition& definition,
                                           org::yaorm::Index& index) = 0;
    virtual std::string build_drop_index(org::yaorm::Definition& definition,
                                         std::vector<org::yaorm::PropertyDefinition>& columns) = 0;

    virtual std::string build_drop_table(org::yaorm::Definition& definition) = 0;
    virtual std::string build_create_table(org::yaorm::Definition& definition) = 0;

    virtual std::string build_delete_all(org::yaorm::Definition& definition) = 0;
    virtual std::string build_delete_table(org::yaorm::Definition& definition,
                                           org::yaorm::PropertyHolder& property_holder) = 0;
    virtual std::string build_delete_with_criteria(org::yaorm::Definition& definition,
                                                   org::yaorm::WhereClauseItem& where_clause) = 0;

    virtual std::string build_bulk_insert(org::yaorm::Definition& definition,
                                          org::yaorm::Records& records) = 0;
    virtual std::string build_insert(org::yaorm::Definition& definition,
                                     org::yaorm::Record& record) = 0;

    virtual std::string build_update(org::yaorm::Definition& definition,
                                     org::yaorm::PropertyHolder& key,
                                     org::yaorm::Record& record) = 0;
    virtual std::string build_update_with_criteria(org::yaorm::Definition& definition,
                                                   org::yaorm::Record& record,
                                                   org::yaorm::WhereClauseItem& where_clause) = 0;

    virtual std::string build_select_all(org::yaorm::Definition& definition, int n) = 0;
    virtual std::string build_where_clause(org::yaorm::Definition& definition,
                                           org::yaorm::WhereClauseItem& where_clause) = 0;
};

#endif //YAORM_CPP_I_SQL_GENERATOR_SERVICE_H

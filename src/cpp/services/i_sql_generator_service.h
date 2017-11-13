//
// Created by Mike Roylance on 5/28/16.
//

#ifndef YAORM_CPP_I_SQL_GENERATOR_SERVICE_H
#define YAORM_CPP_I_SQL_GENERATOR_SERVICE_H

#include "../models/yaorm_models.pb.h"

class ISQLGeneratorService {
public:
    virtual int get_bulk_insert_size() = 0;

    virtual bool insert_same_as_update() = 0;

    virtual std::map<org::yaorm::ProtobufType, std::string> get_proto_type_to_sql_type() = 0;

    virtual std::map<std::string, org::yaorm::ProtobufType> get_sql_type_to_proto_type() = 0;

    virtual std::string get_text_type_name() = 0;
    virtual std::string get_integer_type_name() = 0;
    virtual std::string get_real_type_name() = 0;
    virtual std::string get_blob_type_name() = 0;

    virtual std::string build_count_sql(org::yaorm::TableDefinition &definition) = 0;

    virtual std::string build_create_column(org::yaorm::TableDefinition &definition,
                                            org::yaorm::ColumnDefinition &property_definition) = 0;

    virtual std::string build_drop_column(org::yaorm::TableDefinition &definition,
                                          org::yaorm::ColumnDefinition &property_definition) = 0;

    virtual std::string build_create_index(org::yaorm::TableDefinition &definition,
                                           std::map<org::yaorm::ColumnDefinition, std::string> &properties,
                                           std::map<org::yaorm::ColumnDefinition, std::string> &includes) = 0;

    virtual std::string build_drop_index(org::yaorm::TableDefinition &definition,
                                         std::map<std::string, org::yaorm::ColumnDefinition> &columns) = 0;

    virtual std::string build_drop_table(org::yaorm::TableDefinition &definition) = 0;

    virtual std::string build_create_table(org::yaorm::TableDefinition &definition) = 0;

    virtual std::string build_delete_all(org::yaorm::TableDefinition &definition) = 0;

    virtual std::string build_delete_table(org::yaorm::TableDefinition &definition,
                                           org::yaorm::Column &property_holder) = 0;

    virtual std::string build_delete_with_criteria(org::yaorm::TableDefinition &definition,
                                                   org::yaorm::WhereClause &where_clause) = 0;

    virtual std::string build_bulk_insert(org::yaorm::TableDefinition &definition,
                                          org::yaorm::Records &records) = 0;

    virtual std::string build_insert(org::yaorm::TableDefinition &definition,
                                     org::yaorm::Record &record) = 0;

    virtual std::string build_update(org::yaorm::TableDefinition &definition,
                                     org::yaorm::Record &record) = 0;

    virtual std::string build_update_with_criteria(org::yaorm::TableDefinition &definition,
                                                   org::yaorm::Record &record,
                                                   org::yaorm::WhereClause &where_clause) = 0;

    virtual std::string build_select_all(org::yaorm::TableDefinition &definition, int limit, int offset) = 0;

    virtual std::string build_where_clause(org::yaorm::TableDefinition &definition,
                                           org::yaorm::WhereClause &where_clause) = 0;

    virtual std::string build_select_ids(org::yaorm::TableDefinition &definition) = 0;

    virtual std::string get_schema_names() = 0;

    virtual std::string get_table_names(std::string schema_name) = 0;

    virtual std::string build_table_definition_sql(std::string &schema_name, std::string &table_name) = 0;

    virtual org::yaorm::TableDefinition build_table_definition(std::string &table_name,
                                                               org::yaorm::Records &records) = 0;

private:
};

#endif //YAORM_CPP_I_SQL_GENERATOR_SERVICE_H

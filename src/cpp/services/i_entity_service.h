//
// Created by Mike Roylance on 11/6/17.
//

#ifndef YAORM_CPP_I_ENTITY_SERVICE_H
#define YAORM_CPP_I_ENTITY_SERVICE_H

#include "../models/yaorm_models.pb.h"
#include "i_map_streamer.h"


class IEntityService {
public:
    virtual bool get_same_as_update() = 0;

    virtual bool create_table(org::yaorm::TableDefinition &definition) = 0;

    virtual bool drop_table(org::yaorm::TableDefinition &definition) = 0;

    virtual bool create_index(org::yaorm::Index &index, org::yaorm::TableDefinition &definition) = 0;

    virtual bool drop_index(org::yaorm::Index &index, org::yaorm::TableDefinition &definition) = 0;

    virtual bool create_column(org::yaorm::ColumnDefinition &propertyDefinition,
                               org::yaorm::TableDefinition &definition) = 0;

    virtual bool drop_column(org::yaorm::ColumnDefinition &propertyDefinition,
                             org::yaorm::TableDefinition &definition) = 0;

    virtual bool bulk_insert(org::yaorm::Records &instances, org::yaorm::TableDefinition &definition) = 0;

    virtual bool create_or_update(org::yaorm::Record &entity, org::yaorm::TableDefinition &definition) = 0;

    virtual bool create(org::yaorm::Record &entity, org::yaorm::TableDefinition &definition) = 0;

    virtual bool update(org::yaorm::Record &entity, org::yaorm::TableDefinition &definition) = 0;

    virtual bool update_with_criteria(org::yaorm::Record &new_values, org::yaorm::WhereClause &whereClause,
                                      org::yaorm::TableDefinition &definition) = 0;

    virtual bool update_custom(std::string &custom_sql) = 0;

    virtual bool delete_record(std::string &id, org::yaorm::TableDefinition &definition) = 0;

    virtual bool delete_all(org::yaorm::TableDefinition &definition) = 0;

    virtual bool get_count(org::yaorm::TableDefinition &definition) = 0;

    virtual org::yaorm::Record &get(std::string &id, org::yaorm::TableDefinition &definition) = 0;

    virtual std::vector<std::string> &get_ids(org::yaorm::TableDefinition &definition) = 0;

    virtual void get_ids_stream(org::yaorm::TableDefinition &definition, IMapStreamer &streamer) = 0;

    virtual org::yaorm::Records &get_custom(std::string &custom_sql, org::yaorm::TableDefinition &definition) = 0;

    virtual void get_custom_stream(std::string &custom_sql,
                                   org::yaorm::TableDefinition &definition,
                                   IMapStreamer &streamer) = 0;

    virtual org::yaorm::Records &get_many(org::yaorm::TableDefinition &definition, int limit, int offset) = 0;

    virtual void get_many_stream(org::yaorm::TableDefinition &definition,
                                 int limit,
                                 int offset,
                                 IMapStreamer &streamer) = 0;

    virtual org::yaorm::Records &where(org::yaorm::WhereClause &whereClause,
                                       org::yaorm::TableDefinition &definition) = 0;

    virtual org::yaorm::TableDefinition &build_definition_from_sql(std::string &custom_sql,
                                                                   int row_count) = 0;

    virtual std::vector<std::string> &get_schema_names() = 0;

    virtual std::vector<std::string> &get_table_names(std::string &schema_name) = 0;

    virtual org::yaorm::TableDefinition &get_table_definition(std::string &schema_name, std::string &table_name) = 0;

    virtual org::yaorm::DatabaseExecutionReport &get_report() = 0;
};

#endif //YAORM_CPP_I_ENTITY_SERVICE_H

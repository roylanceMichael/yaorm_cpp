//
// Created by Mike Roylance on 11/6/17.
//
#include "i_entity_context.h"

bool create_index(const org::yaorm::Difference &difference,
                  IEntityService &service) {
    if (difference.has_property_definition() && difference.has_table_definition()) {
        return service.create_index(difference.index(),
                                    difference.table_definition());
    }
    return false;
}

bool drop_index(const org::yaorm::Difference &difference,
                IEntityService &service) {
    if (difference.has_property_definition() && difference.has_table_definition()) {
        return service.drop_index(difference.index(),
                                  difference.table_definition());
    }
    return false;
}

bool create_column(const org::yaorm::Difference &difference,
                   IEntityService &service) {
    if (difference.has_property_definition() && difference.has_table_definition()) {
        return service.create_column(difference.property_definition(),
                                     difference.table_definition());
    }
    return false;
}

bool drop_column(const org::yaorm::Difference &difference,
                 IEntityService &service) {
    if (difference.has_property_definition() && difference.has_table_definition()) {
        return service.drop_column(difference.property_definition(),
                                   difference.table_definition());
    }
    return false;
}

bool create_table(const org::yaorm::Difference &difference,
                  IEntityService &service) {
    if (difference.has_property_definition() && difference.has_table_definition()) {
        return service.create_table(difference.table_definition());
    }
    return false;
}

bool drop_table(const org::yaorm::Difference &difference,
                IEntityService &service) {
    if (difference.has_property_definition() && difference.has_table_definition()) {
        return service.drop_table(difference.table_definition());
    }
    return false;
}

bool type_to_action(const org::yaorm::Difference &difference,
                    IEntityService &service) {
    if (difference.operation() == org::yaorm::Difference::Operation::Difference_Operation_CREATE) {
        if (difference.entity_type() == org::yaorm::Difference::EntityType::Difference_EntityType_COLUMN) {
            return create_column(difference, service);
        } else if (difference.entity_type() == org::yaorm::Difference::EntityType::Difference_EntityType_INDEX) {
            return create_index(difference, service);
        }
        return create_table(difference, service);
    }
    // drop
    if (difference.entity_type() == org::yaorm::Difference::EntityType::Difference_EntityType_COLUMN) {
        return drop_column(difference, service);
    } else if (difference.entity_type() == org::yaorm::Difference::EntityType::Difference_EntityType_INDEX) {
        return drop_index(difference, service);
    }
    return drop_table(difference, service);
}

IEntityContext::IEntityContext(google::protobuf::FileDescriptor &file_descriptor, IEntityService &entity_service,
                               std::map<std::string, org::yaorm::Index> &indexes, std::string &context_name)
        : file_descriptor(file_descriptor), entity_service(entity_service), indexes(indexes),
          context_name(context_name) {
}
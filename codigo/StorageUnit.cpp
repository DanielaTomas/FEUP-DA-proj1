//
// Created by berna on 27/03/2022.
//

#include "StorageUnit.h"

std::vector<Deliver> StorageUnit::getDelivers() const{
    return this->allDelivers;
}

std::vector<DeliverMan> StorageUnit::getDeliverMen() const{
    return this->allDeliverMen;
}

void StorageUnit::setDelivers(std::vector<Deliver> &delivers) {
    this->allDelivers = delivers;
}

void StorageUnit::setDeliverMen(std::vector<DeliverMan> &deliverMen) {
    this->allDeliverMen = deliverMen;
}

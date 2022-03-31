//
// Created by berna on 27/03/2022.
//

#ifndef CODIGO_STORAGEUNIT_H
#define CODIGO_STORAGEUNIT_H

#include "Deliver.h"
#include "DeliverMan.h"


class StorageUnit {
private:
    std::vector<Deliver> allDelivers;
    std::vector<DeliverMan> allDeliverMen;
public:
    std::vector<Deliver> getDelivers();
    std::vector<DeliverMan> getDeliverMen();
    void setDelivers(std::vector<Deliver>& delivers);
    void setDeliverMen(std::vector<DeliverMan>& deliverMen);

};


#endif //CODIGO_STORAGEUNIT_H

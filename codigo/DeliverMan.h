//
// Created by berna on 27/03/2022.
//

#ifndef CODIGO_DELIVERMAN_H
#define CODIGO_DELIVERMAN_H

#include "Deliver.h"

class DeliverMan {
private:
    int maxVolume;
    int maxWeight;
    int cost;
    std::string carPlate;
    std::vector<Deliver*> delivers;

};


#endif //CODIGO_DELIVERMAN_H

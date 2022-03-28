//
// Created by berna on 27/03/2022.
//

#ifndef CODIGO_DELIVERMAN_H
#define CODIGO_DELIVERMAN_H

#include "Deliver.h"

class DeliverMan {
private:
    int id;
    static int current_id;
    int maxVol;
    int maxW;
    float cost;
    std::string carPlate;
    std::vector<Deliver*> delivers;
public:
    DeliverMan(int maxVol, int maxW, float cost);
};


#endif //CODIGO_DELIVERMAN_H

//
// Created by berna on 27/03/2022.
//

#include "DeliverMan.h"

int DeliverMan::current_id = 0;

DeliverMan::DeliverMan(int maxVol, int maxW, float cost) : id(current_id++){

    this->maxVol = maxVol;
    this->maxW = maxW;
    this->cost = cost;
}

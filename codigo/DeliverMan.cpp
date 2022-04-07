#include "DeliverMan.h"

int DeliverMan::current_id = 0;

DeliverMan::DeliverMan(int maxVol, int maxW, float cost) : id(current_id++){

    this->maxVol = maxVol;
    this->maxW = maxW;
    this->cost = cost;
    this->full = false;
    this->remainingW = maxW;
    this->remainingVol = maxVol;

}

int DeliverMan::getRemainingVol() const {
    return this->remainingVol;
}

int DeliverMan::getRemainingW() const {
    return this->remainingW;
}

bool DeliverMan::addDeliver(Deliver &deliver) {

    if(this->remainingVol - deliver.getVolume() <= 0 || remainingW - deliver.getWeight() <= 0) {
        return false;
    }

    this->delivers.push_back(deliver);
    this->remainingVol -= deliver.getVolume();
    this->remainingW -= deliver.getWeight();

    return true;
}


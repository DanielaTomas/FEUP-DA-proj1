#include "DeliverMan.h"

int DeliverMan::current_id = 0;

DeliverMan::DeliverMan() :id(-1) {

    this->maxVol = -1;
    this->maxW = -1;
    this->cost = -1;
    this->full = false;
    this->remainingW = -1;
    this->remainingVol = -1;
}

DeliverMan::DeliverMan(int maxVol, int maxW, float cost) : id(current_id++){

    this->maxVol = maxVol;
    this->maxW = maxW;
    this->cost = cost;
    this->full = false;
    this->remainingW = maxW;
    this->remainingVol = maxVol;

}

int DeliverMan::getId() const {
    return this->id;
}

int DeliverMan::getRemainingVol() const {
    return this->remainingVol;
}

int DeliverMan::getRemainingW() const {
    return this->remainingW;
}

bool DeliverMan::getFull() const {
    return this->full;
}

bool DeliverMan::addDeliver(Deliver &deliver) {

    if(this->remainingVol == 0 || this->remainingW == 0) {
        this->full = true;
        return false;
    }

    if(this->remainingVol - deliver.getVolume() < 0 || remainingW - deliver.getWeight() < 0) {
        return false;
    }

    this->delivers.push_back(deliver);
    this->remainingVol -= deliver.getVolume();
    this->remainingW -= deliver.getWeight();

    return true;
}

bool operator==(const DeliverMan &d1, const DeliverMan &d2) {

    return d1.id == d2.id;
}

bool operator<(const DeliverMan &d1, const DeliverMan &d2) {

    if(d1.id < d2.id) {
        return true;
    }else if(d1.id > d2.id) {
        return false;
    }else {
        if(d1.maxVol < d2.maxVol) {
            return true;
        }else if(d1.maxVol > d2.maxVol) {
            return false;
        }else {
            if(d1.maxW < d2.maxW) {
                return true;
            }else {
                return false;
            }
        }
    }
}

/*
bool operator=(const DeliverMan &d1, const DeliverMan &d2) {



}
*/


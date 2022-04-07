#include "Deliver.h"

int Deliver::current_id = 0;

Deliver::Deliver(int volume, int weight, float reward, int duration) : id(current_id++){

    this->volume = volume;
    this->weight = weight;
    this->duration = duration;
    this->reward = reward;
}

int Deliver::getVolume() const {
    return this->volume;
}

int Deliver::getWeight() const {
    return this->weight;
}

float Deliver::getReward() const {
    return this->reward;
}

bool operator<(const Deliver &d1, const Deliver &d2) {

    if(d1.volume < d2.volume) {
        return true;
    }else if(d1.volume > d2.volume) {
        return false;
    }else {
        if(d1.weight < d2.weight) {
            return true;
        } else {
            return false;
        }
    }

}
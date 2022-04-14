#include "Deliver.h"

int Deliver::current_id = 0;

Deliver::Deliver(int volume, int weight, float reward, int duration) : id(current_id++){

    this->volume = volume;
    this->weight = weight;
    this->duration = duration;
    this->reward = reward;
    this->sumWeiVol = this->volume + this->weight;
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

int Deliver::getDuration() const {
    return this->duration;
}

bool operator<(const Deliver &d1, const Deliver &d2) {

    return d1.sumWeiVol < d2.sumWeiVol;
}

int Deliver::getId() const {
    return this->id;
}

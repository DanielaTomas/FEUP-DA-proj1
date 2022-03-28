//
// Created by berna on 27/03/2022.
//

#include "Deliver.h"

int Deliver::current_id = 0;

Deliver::Deliver(int volume, int weight, float reward, int duration) : id(current_id++){

    this->volume = volume;
    this->weight = weight;
    this->duration = duration;
    this->reward = reward;
}

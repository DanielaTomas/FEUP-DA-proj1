//
// Created by berna on 27/03/2022.
//

#ifndef CODIGO_DELIVER_H
#define CODIGO_DELIVER_H

#include <string>
#include <vector>

class Deliver {
public:
    int id;
    static int current_id;
    int volume;
    int weight;
    float reward;
    int duration;
public:
    Deliver(int volume, int weight, float reward, int duration);
};


#endif //CODIGO_DELIVER_H

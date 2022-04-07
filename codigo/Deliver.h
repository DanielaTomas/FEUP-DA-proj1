#ifndef CODIGO_DELIVER_H
#define CODIGO_DELIVER_H

#include <string>
#include <vector>

class Deliver {
private:
    int id;
    static int current_id;
    int volume;
    int weight;
    float reward;
    int duration;
public:
    Deliver(int volume, int weight, float reward, int duration);
    int getVolume() const;
    int getWeight() const;
    float getReward() const;
    friend bool operator<(const Deliver& d1, const Deliver& d2);
};


#endif //CODIGO_DELIVER_H

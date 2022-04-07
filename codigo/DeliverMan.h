#ifndef CODIGO_DELIVERMAN_H
#define CODIGO_DELIVERMAN_H

#include "Deliver.h"

class DeliverMan {
private:
    int id;
    static int current_id;
    int maxVol;
    int maxW;
    int remainingVol;
    int remainingW;
    float cost;
    std::string carPlate;
    std::vector<Deliver> delivers;
    bool full;
public:
    DeliverMan(int maxVol, int maxW, float cost);
    int getRemainingVol() const;
    int getRemainingW() const;
    bool addDeliver(Deliver& deliver);
};


#endif //CODIGO_DELIVERMAN_H

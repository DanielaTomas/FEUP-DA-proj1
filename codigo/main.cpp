#include <iostream>
#include "DeliverMan.h"
#include "Utils.h"

int main() {

    std::vector<DeliverMan> deliverMen;
    std::vector<Deliver> delivers;

    readFiles(deliverMen, delivers);

    return 0;
}

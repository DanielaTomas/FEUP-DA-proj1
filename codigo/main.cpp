#include <iostream>
#include "DeliverMan.h"
#include "Utils.h"
#include "StorageUnit.h"

bool firstScenery(StorageUnit& storageUnit) {

    std::cout << "1" << std::endl;

    return false;
}


bool secondScenery(StorageUnit& storageUnit) {

    std::cout << "2" << std::endl;

    return false;
}

bool thirdScenery(StorageUnit& storageUnit) {

    std::cout << "3" << std::endl;

    return false;
}


int main() {

    StorageUnit storageUnit;
    int num;

    readFiles(storageUnit);

    std::cout << "Choose a Scenery: " << std::endl;
    std::cin >> num;

    switch(num) {
        case 1:
            firstScenery(storageUnit);
            break;
        case 2:
            secondScenery(storageUnit);
            break;
        case 3:
            thirdScenery(storageUnit);
            break;
        default:
            break;
    }

    return 0;
}

#ifndef CODIGO_UTILS_H
#define CODIGO_UTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "DeliverMan.h"

//! Create Object (DeliverMan)
//!
//! \param deliverMen
//! \param values
void createObject(std::vector<DeliverMan>& deliverMen, std::vector<std::string>& values);
//! Create Object (Deliver)
//!
//! \param delivers
//! \param values
void createObject(std::vector<Deliver>& delivers, std::vector<std::string>& values);
//! Breaks string line into a series of tokens using the space as the delimiter. Tokens are stored in values
//!
//! \param line
//! \param values
void parseString(std::string& line, std::vector<std::string>& values);
//! Read Files
//!
//! \tparam T
//! \param objects
//! \param filepath
template <typename T>
void readFiles(std::vector<T>& objects, std::string& filepath) {

    std::ifstream file;

    file.open(filepath);

    if(!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        exit(1);
    }

    parseFile(file, objects);

    file.close();
}
//! Parse File
//!
//! \tparam T
//! \param file
//! \param objects
template <typename T>
void parseFile(std::ifstream& file, std::vector<T>& objects) {

    std::string line;

    getline(file, line);

    while(!file.eof()) {
        std::vector<std::string> values;
        getline(file, line);
        parseString(line, values);
        createObject(objects, values);

    }
}

/*
    vector<DeliverMan> deliverMenBF = deliverMen;
    set<DeliverMan> resultBF;
    */

//Best fit: Vai pondo cada encomenda no melhor estafeta(no que sobrar menos espaço).
/*
std::set<DeliverMan*> usedDeliverMen;
for(auto deliver : delivers) {
    int deliverManId = checkBestFit(usedDeliverMen, deliver);
    if(deliverManId != -1) {
        DeliverMan& deliverMan = searchForDeliverMan(deliverManId, deliverMenBF);
        if(deliverMan.getId() != -1) {
            deliverMan.addDeliver(deliver);
            continue;
        }
    }
    for(auto & deliverMan : deliverMenBF) {
        if(deliverMan.addDeliver(deliver)) {
            usedDeliverMen.insert(&deliverMan);
            resultBF.insert(deliverMan);
            break;
        }
    }
}

cout << "First Fit: " << resultFF.size() << endl;
cout << "Best Fit: " << resultBF.size() << endl;

if(resultFF.size() < resultBF.size()) {
    deliverMen = deliverMenFF;
    return resultFF.size();
}else {
    deliverMen = deliverMenBF;
    return resultBF.size();
}
*/




/*
int checkBestFit(set<DeliverMan*>& usedDeliverMen, Deliver& deliver) {

    int volume = 999999;
    int weight = 999999;
    int id = -1;

    for(auto & usedDeliverMan : usedDeliverMen) {
        if(deliver.getWeight() <= usedDeliverMan->getRemainingW()
        && deliver.getVolume() <= usedDeliverMan->getRemainingVol()) {
            if(usedDeliverMan->getRemainingVol() < volume
            && usedDeliverMan->getRemainingW() < weight) {
                volume = usedDeliverMan->getRemainingVol();
                weight = usedDeliverMan->getRemainingW();
                id = usedDeliverMan->getId();
            }
        }
    }

    return id;
}


DeliverMan* searchForDeliverMan(int id, vector<DeliverMan>& deliverMen) {

    DeliverMan* deliverMan1;

    for(auto & deliverMan : deliverMen) {
        if(deliverMan.getId() == id) {
            deliverMan1 = new DeliverMan(deliverMan);
            break;
        }
    }

    return deliverMan1;
}
*/


#endif //CODIGO_UTILS_H

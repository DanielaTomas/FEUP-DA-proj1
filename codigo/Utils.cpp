#include "Utils.h"

void createObject(std::vector<DeliverMan>& deliverMen, std::vector<std::string>& values) {

    DeliverMan deliverMan(stoi(values[0]), stoi(values[1]), stof(values[2]));

    deliverMen.push_back(deliverMan);
}


void createObject(std::vector<Deliver>& delivers, std::vector<std::string>& values) {

    Deliver deliver(stoi(values[0]), stoi(values[1]), stof(values[2]), stoi(values[3]));

    delivers.push_back(deliver);
}

void parseString(std::string& line, std::vector<std::string>& values) {

    std::stringstream ss(line);
    std::string aux;

    while(getline(ss, aux, ' ')) {
        values.push_back(aux);
    }
}
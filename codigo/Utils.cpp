//
// Created by berna on 28/03/2022.
//

#include "Utils.h"

void parseString(std::string& line, std::vector<std::string>& values) {

    std::stringstream ss(line);
    std::string aux;

    while(getline(ss, aux, ' ')) {
        values.push_back(aux);
    }
}

void readFiles(StorageUnit& storageUnit) {

    std::ifstream file;
    std::vector<DeliverMan> deliverMen;
    std::vector<Deliver> delivers;

    file.open("../../dataset/carrinhas_test.txt");

    if(!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        exit(1);
    }

    parseFile(file, deliverMen);

    file.close();

    file.open("../../dataset/encomendas_test.txt");

    if(!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        exit(1);
    }

    parseFile(file, delivers);

    storageUnit.setDeliverMen(deliverMen);
    storageUnit.setDelivers(delivers);

    file.close();
}

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

void createObject(std::vector<DeliverMan>& deliverMen, std::vector<std::string>& values) {

    DeliverMan deliverMan(stoi(values[0]), stoi(values[1]), stof(values[2]));

    deliverMen.push_back(deliverMan);
}


void createObject(std::vector<Deliver>& delivers, std::vector<std::string>& values) {

    Deliver deliver(stoi(values[0]), stoi(values[1]), stof(values[2]), stoi(values[3]));

    delivers.push_back(deliver);
}

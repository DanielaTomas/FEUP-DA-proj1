#include "Utils.h"

void parseString(std::string& line, std::vector<std::string>& values) {

    std::stringstream ss(line);
    std::string aux;

    while(getline(ss, aux, ' ')) {
        values.push_back(aux);
    }
}

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

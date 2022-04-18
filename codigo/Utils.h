#ifndef CODIGO_UTILS_H
#define CODIGO_UTILS_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "DeliverMan.h"

void createObject(std::vector<DeliverMan>& deliverMen, std::vector<std::string>& values);
void createObject(std::vector<Deliver>& delivers, std::vector<std::string>& values);
void parseString(std::string& line, std::vector<std::string>& values);

template <typename T>
void readFiles(std::vector<T>& objects, std::string& filepath) {

    std::ifstream file;

    file.open(filepath);

    if(!file.is_open()) {
        std::cout << "Error opening file!" << std::endl;
        exit(1);
    }

    parseFile(file, objects);

    std::cout << "fewfew" << std::endl;

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


#endif //CODIGO_UTILS_H

#ifndef CODIGO_UTILS_H
#define CODIGO_UTILS_

#include <fstream>
#include <iostream>
#include <vector>
#include <sstream>
#include "DeliverMan.h"

void parseString(std::string& line, std::vector<std::string>& values);
void readFiles(std::vector<Deliver>& delivers, std::vector<DeliverMan>& deliverMen);
template <typename T>
void parseFile(std::ifstream& file, std::vector<T>& objects);
void createObject(std::vector<DeliverMan>& deliverMen, std::vector<std::string>& values);
void createObject(std::vector<Deliver>& delivers, std::vector<std::string>& values);


#endif //CODIGO_UTILS_H

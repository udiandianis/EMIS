#include "tools.h"
#include <fstream>
#include <iostream>

int generateUniqueID(const std::string& fileName) {
    std::ifstream idFile(fileName);
    int lastId = 0;
    if (idFile.is_open()) {
        idFile >> lastId;
    }
    idFile.close();

    int newId = lastId + 1;

    std::ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << newId;
    }
    outFile.close();

    return newId;
}

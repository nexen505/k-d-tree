#include <iostream>
#include <sstream>
#include "FileGenerator.h"

FileGenerator::FileGenerator(string fileName) {
    ifstream in(fileName);
    if (!in) {
        throw invalid_argument("Cannot open the file : " + fileName);
    }
    string str;
    if (!getline(in, str)) {
        throw invalid_argument("Cannot parse vector to search : " + fileName);
    }
    double temp;
    stringstream vectorToSearchStream(str);
    while (vectorToSearchStream >> temp) this->vectorToSearch.push_back(temp);
    while (getline(in, str)) {
        vector<double> array;
        stringstream ss(str);
        while (ss >> temp) array.push_back(temp);
        this->storeContent.push_back(array);
    }
    in.close();
}

vector<double> FileGenerator::getVectorToSearch() {
    return this->vectorToSearch;
}

vector<vector<double>> FileGenerator::getStoreContent() {
    return this->storeContent;
}

#include <iostream>
#include <sstream>
#include "FileGenerator.h"

FileGenerator::FileGenerator(string fileName) {
    // open file
    ifstream in(fileName);
    if (!in) {
        throw invalid_argument("Cannot open the file : " + fileName);
    }

    // first line with vector to search must be
    string str;
    if (!getline(in, str)) {
        throw invalid_argument("Cannot parse vector to search : " + fileName);
    }

    // read line by stream and write into vector
    double temp;
    stringstream vectorToSearchStream(str);
    while (vectorToSearchStream >> temp) this->vectorToSearch.push_back(temp);

    // reading all other lines of file as vectors
    while (getline(in, str)) {
        // read line by stream and write into vector
        vector<double> array;
        stringstream ss(str);
        while (ss >> temp) array.push_back(temp);

        // push read vector into vectors list
        this->storeContent.push_back(array);
    }

    // close opened file
    in.close();
}

vector<double> FileGenerator::getVectorToSearch() {
    return this->vectorToSearch;
}

vector<vector<double>> FileGenerator::getStoreContent() {
    return this->storeContent;
}

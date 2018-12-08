//
// Created by Ilia on 03.12.2018.
//

#include <cstdio>
#include <sstream>
#include <iterator>
#include <iostream>
#include "VectorOfVectors.h"

VectorOfVectors::VectorOfVectors(const vector<vector<double>> &vectors, int count, int dimension) : VectorStore(vectors,
                                                                                                                count,
                                                                                                                dimension) {
    this->v_arr = vector<vector<double>>(vectors);
}

vector<double> *VectorOfVectors::search(const vector<double> &match) {
    vector<double> *result = nullptr;

    for (int i = 0; i < this->count; i++) {
        vector<double> vector = v_arr[i];
        if (vector == match) {
            result = &vector;
            break;
        }
    }

    return result;
}

VectorOfVectors::~VectorOfVectors() {
    std::cout << "VectorOfVectors is destroyed.." << endl;
    v_arr.clear();
    v_arr.shrink_to_fit();
}

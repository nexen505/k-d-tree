//
// Created by Ilia on 03.12.2018.
//

#include <cstdio>
#include <sstream>
#include <iterator>
#include "VectorOfVectors.h"

VectorOfVectors::VectorOfVectors(const vector<vector<double>> &vectors, int count, int dimension) : VectorStore(vectors,
                                                                                                                count,
                                                                                                                dimension) {
    this->v_arr = vectors;
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

//
// Created by Ilia on 03.12.2018.
//

#include <cstdlib>
#include "RandomVectorGenerator.h"

vector<double> RandomVectorGenerator::generate(const int dimension) {
    vector<double> res;
    for (int i = 0; i < dimension; ++i) {
        res.push_back(rand() % 10);
    }
    return res;
}

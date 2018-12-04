//
// Created by Ilia on 03.12.2018.
//

#include <cstdlib>
#include <time.h>
#include "RandomVectorGenerator.h"

vector<double> RandomVectorGenerator::generate(const int dimension) {
    vector<double> res;
    srand((unsigned int) time(nullptr) / 2);
    for (int i = 0; i < dimension; ++i) {
        res.push_back(rand() % 10);
    }
    return res;
}

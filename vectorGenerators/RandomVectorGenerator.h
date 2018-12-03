//
// Created by Ilia on 03.12.2018.
//

#ifndef CPP_K_D_TREE_RANDOMVECTORGENERATOR_H
#define CPP_K_D_TREE_RANDOMVECTORGENERATOR_H

#include <vector>
#include "VectorGenerator.h"

using namespace std;

class RandomVectorGenerator : public VectorGenerator {
public:
    vector<double> generate(int dimension) override;

    vector <vector<double>> generateList(int count, int dimension) override;
};


#endif //CPP_K_D_TREE_RANDOMVECTORGENERATOR_H

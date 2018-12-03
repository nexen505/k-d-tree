//
// Created by Ilia on 03.12.2018.
//

#ifndef CPP_K_D_TREE_VECTORGENERATOR_H
#define CPP_K_D_TREE_VECTORGENERATOR_H

#include <vector>

using namespace std;

class VectorGenerator {
public:
    virtual vector<double> generate(int dimension) = 0;

    virtual vector <vector<double>> generateList(int count, int dimension) = 0;
};


#endif //CPP_K_D_TREE_VECTORGENERATOR_H

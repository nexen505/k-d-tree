//
// Created by Ilia on 03.12.2018.
//

#ifndef CPP_K_D_TREE_VECTORCONTAINER_H
#define CPP_K_D_TREE_VECTORCONTAINER_H

#include <vector>

using namespace std;

class VectorStore {
protected:
    int count, dimension;
public:
    VectorStore(const vector<vector<double>> &vectors, int count, int dimension) : count(count),
                                                                                   dimension(dimension) {};

    virtual vector<double> *search(const vector<double> &match) = 0;
};


#endif //CPP_K_D_TREE_VECTORCONTAINER_H

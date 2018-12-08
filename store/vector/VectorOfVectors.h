//
// Created by Ilia on 03.12.2018.
//

#ifndef CPP_K_D_TREE_VECTOROFVECTORS_H
#define CPP_K_D_TREE_VECTOROFVECTORS_H


#include "../VectorStore.h"

class VectorOfVectors final : public VectorStore {
private:
    vector<vector<double>> v_arr;

public:
    ~VectorOfVectors() override;

    VectorOfVectors(const vector<vector<double>> &vectors, int count, int dimension);

    vector<double> *search(const vector<double> &match) override;
};


#endif //CPP_K_D_TREE_VECTOROFVECTORS_H

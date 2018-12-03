//
// Created by Ilia on 03.12.2018.
//

#ifndef CPP_K_D_TREE_VECTOROFVECTORS_H
#define CPP_K_D_TREE_VECTOROFVECTORS_H


#include "../VectorStore.h"

class VectorOfVectors : public VectorStore {
private:
    vector<vector<double>> v_arr;

public:
    void add(vector<double> a) override;

    void add(vector<vector<double>> vv) override;

    void search(vector<double> match) override;
};


#endif //CPP_K_D_TREE_VECTOROFVECTORS_H

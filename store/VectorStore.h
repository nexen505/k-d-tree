//
// Created by Ilia on 03.12.2018.
//

#ifndef CPP_K_D_TREE_VECTORCONTAINER_H
#define CPP_K_D_TREE_VECTORCONTAINER_H

#include <vector>

using namespace std;

class VectorStore {
public:
    virtual void add(vector<double> v) = 0;

    virtual void add(vector<vector<double>> vv) {
        for (auto const &value: vv) {
            add(value);
        }
    }

    virtual void search(vector<double> match) = 0;
};


#endif //CPP_K_D_TREE_VECTORCONTAINER_H

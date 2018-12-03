//
// Created by Ilia on 03.12.2018.
//

#ifndef CPP_K_D_TREE_KDTREE_H
#define CPP_K_D_TREE_KDTREE_H


#include "../VectorStore.h"

class KdTree : public VectorStore {
public:
    void add(vector<double> v) override;

    void search(vector<double> match) override;
};


#endif //CPP_K_D_TREE_KDTREE_H

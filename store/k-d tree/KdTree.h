//
// Created by Ilia on 03.12.2018.
//

#ifndef CPP_K_D_TREE_KDTREE_H
#define CPP_K_D_TREE_KDTREE_H


#include "../VectorStore.h"

struct kd_node_t {
    vector<double> x;
    struct kd_node_t *left{}, *right{};

    kd_node_t() = default;

    explicit kd_node_t(vector<double> x, kd_node_t *left = nullptr, kd_node_t *right = nullptr) : x(std::move(x)),
                                                                                                  left(left),
                                                                                                  right(right) {}
};

class KdTree final : public VectorStore {
private:
    kd_node_t *root;

    double dist(kd_node_t *a, kd_node_t *b);

    kd_node_t *makeTree(kd_node_t *t, int len, int i);

    void nearest(kd_node_t *root, kd_node_t *node, int i, kd_node_t **bestDistanced, double *bestDistance);

public:
    KdTree(const vector<vector<double>> &vectors, int count, int dimension);

    vector<double> *search(const vector<double> &match) override;
};


#endif //CPP_K_D_TREE_KDTREE_H

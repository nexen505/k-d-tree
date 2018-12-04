//
// Created by Ilia on 03.12.2018.
//

#include <stdlib.h>
#include "KdTree.h"

void swap(struct kd_node_t *a, struct kd_node_t *b) {
    a->x.swap(b->x);
}

/* see quickselect method */
kd_node_t *find_median(kd_node_t *start, kd_node_t *end, int idx) {
    if (end <= start) return nullptr;
    if (end == start + 1)
        return start;

    struct kd_node_t *p, *store, *md = start + (end - start) / 2;
    double pivot;
    while (true) {
        pivot = md->x[idx];

        swap(md, end - 1);
        for (store = p = start; p < end; p++) {
            if (p->x[idx] < pivot) {
                if (p != store)
                    swap(p, store);
                store++;
            }
        }
        swap(store, end - 1);

        /* median has duplicate values */
        if (store->x[idx] == md->x[idx])
            return md;

        if (store > md) end = store;
        else start = store;
    }
}

KdTree::KdTree(const vector<vector<double>> &vectors, int count, int dimension) : VectorStore(vectors, count,
                                                                                              dimension) {
    auto *wp = new kd_node_t[count];
    for (int j = 0; j < count; ++j) {
        wp[j].x = vectors[j];
    }
    root = makeTree(wp, count, 0);
}

kd_node_t *KdTree::makeTree(kd_node_t *t, int len, int i) {
    kd_node_t *n;

    if (!len) return nullptr;

    if ((n = find_median(t, t + len, i))) {
        i = (i + 1) % dimension;
        n->left = makeTree(t, static_cast<int>(n - t), i);
        n->right = makeTree(n + 1, static_cast<int>(t + len - (n + 1)), i);
    }
    return n;
}

double KdTree::dist(kd_node_t *a, kd_node_t *b) {
    double t, d = 0;
    for (int i = 0; i < a->x.size(); ++i) {
        t = a->x[i] - b->x[i];
        d += t * t;
    }
    return d;
}

void KdTree::nearest(kd_node_t *root, kd_node_t *node, int i, kd_node_t **bestDistanced, double *bestDistance) {
    if (!root) return;
    double d = dist(root, node);

    if (!*bestDistanced || d < *bestDistance) {
        *bestDistance = d;
        *bestDistanced = root;
    }
    if (*bestDistance == 0) return;

    i = (i + 1) % dimension;
    double dx = root->x[i] - node->x[i], dx2 = dx * dx;
    nearest(dx > 0 ? root->left : root->right, node, i, bestDistanced, bestDistance);
    if (dx2 >= *bestDistance) return;
    nearest(dx > 0 ? root->right : root->left, node, i, bestDistanced, bestDistance);
}

vector<double> *KdTree::search(const vector<double> &match) {
    kd_node_t *found = nullptr, *testNode = new kd_node_t(match);
    double best_dist;

    nearest(root, testNode, 0, &found, &best_dist);
    return best_dist != 0 ? nullptr : &found->x;
}

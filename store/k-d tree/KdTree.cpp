//
// Created by Ilia on 03.12.2018.
//

#include <stdlib.h>
#include <cmath>
#include <iostream>
#include "KdTree.h"

/**
 * Swap two vectors
 * @private
 * @param a - vector to be swapped
 * @param b - vector to be swapped
 */
void swap(struct kd_node_t *a, struct kd_node_t *b) {
    a->x.swap(b->x);
}

/**
 * Find median between two nodes on concrete coordinate.
 * Quickselect method implementation.
 * @see Quickselect method
 * @param start - pointers on node to find median between
 * @param end - pointers on node to find median between
 * @param idx - coordinate index
 * @return median between nodes or nullptr if it's not found
 */
kd_node_t *find_median(kd_node_t *start, kd_node_t *end, int idx) {
    if (end <= start) return nullptr; // if start and end is reversed
    if (end == start + 1) return start; // nodes are neighbours

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

        if (store->x[idx] == md->x[idx]) return md; // median has duplicate values

        if (store > md) end = store;
        else start = store;
    }
}

/**
* Default constructor.
* It initializes tree root by nodes array that is based on input vector of vectors.
* @param vectors - vectors to store
* @param count - count of vectors
* @param dimension - vector dimension
*/
KdTree::KdTree(const vector<vector<double>> &vectors, int count, int dimension) : VectorStore(vectors, count,
                                                                                              dimension) {
    auto *wp = new kd_node_t[count];
    for (int i = 0; i < count; ++i) {
        wp[i].x = vector<double>(vectors[i]);
    }
    root = makeTree(wp, count, 0);
}

/**
 * Construct tree root by recursive division related to median.
 * @param t - tree nodes array pointer
 * @param len - length of tree nodes array
 * @param i - index of coordinate to find median for.
 * @return constructed tree root
 */
kd_node_t *KdTree::makeTree(kd_node_t *t, int len, int i) {
    kd_node_t *n;

    if (!len) return nullptr;

    if ((n = find_median(t, t + len, i))) { // getting median
        i = (i + 1) % dimension;
        n->left = makeTree(t, static_cast<int>(n - t), i); // constructing left subtree
        n->right = makeTree(n + 1, static_cast<int>((len - 1) - (n - t)), i); // constructing right subtree
    }
    return n;
}

/**
 * Calculate distance between two nodes.
 * It is Euclidean distance.
 * @param a - vector to calculate distance for
 * @param b - vector to calculate distance for
 * @return Euclidean distance between node elements.
 */
double KdTree::dist(kd_node_t *a, kd_node_t *b) {
    double t, d = 0;
    for (int i = 0; i < a->x.size(); ++i) {
        d += pow(a->x[i] - b->x[i], 2);
    }
    return d;
}

/**
* Find nearest neighbour for node.
* @param root - root of tree to find neighbour place in
* @param node - node to find neighbour for
* @param i - index of coordinate to find median for
* @param bestDistanced - pointer to store node with best distance
* @param bestDistance - best distance pointer
*/
void KdTree::nearest(kd_node_t *root, kd_node_t *node, int i, kd_node_t **bestDistanced, double *bestDistance) {
    if (!root) return;
    double d = dist(root, node);

    if (!*bestDistanced || d < *bestDistance) { // updating best distance node and value
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

/**
 * Search for concrete node.
 * If it is not found, nullptr is returned.
 * @param match - vector to find
 * @return search result vector pointer or nullptr if it is not found
 */
vector<double> *KdTree::search(const vector<double> &match) {
    kd_node_t *found = nullptr, *testNode = new kd_node_t(match);
    double best_dist;

    nearest(root, testNode, 0, &found, &best_dist);
    return best_dist != 0 ? nullptr : &found->x;
}

/**
 * Destructor that clears root children and itself.
 */
KdTree::~KdTree() {
    if (root != nullptr) {
        delete root->left;
        delete root->right;
        delete root;
    }
}

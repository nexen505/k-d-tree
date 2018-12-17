#ifndef CPP_K_D_TREE_KDTREE_H
#define CPP_K_D_TREE_KDTREE_H


#include "../VectorStore.h"

/**
 * K-d tree node struct.
 */
struct kd_node_t {
    /**
     * Tree node element.
     */
    vector<double> x;

    /**
     * Node children.
     */
    struct kd_node_t *left{}, *right{};

    /**
     * Default constructor.
     */
    kd_node_t() = default;

    /**
     * Node constructor.
     * @param x - node element
     * @param left - left node child
     * @param right - right node child
     */
    explicit kd_node_t(vector<double> x, kd_node_t *left = nullptr, kd_node_t *right = nullptr) : x(std::move(x)),
                                                                                                  left(left),
                                                                                                  right(right) {}

    /**
     * Node destructor.
     */
    ~kd_node_t() {
        if (left) {
            free(left);
        }
        if (right) {
            free(right);
        }
        left = nullptr;
        right = nullptr;
    }
};

/**
 * Vector store that is based on median k-d tree.
 */
class KdTree final : public VectorStore {
private:
    /**
     * Tree root.
     */
    kd_node_t *root;

    /**
     * Calculate distance between two nodes.
     * @param a - node to calculate distance for
     * @param b - node to calculate distance for
     * @return distance
     */
    double dist(kd_node_t *a, kd_node_t *b);

    /**
     * Construct tree for array of nodes.
     * @param t - node array pointer
     * @param len - length of tree
     * @param i - index of coordinate to find median for
     * @return tree root pointer
     */
    kd_node_t *makeTree(kd_node_t *t, int len, int i);

    /**
     * Find nearest neighbour for node.
     * @param root - root of tree to find neighbour place in
     * @param node - node to find neighbour for
     * @param i - index of coordinate to find median for
     * @param bestDistanced - pointer to store node with best distance
     * @param bestDistance - best distance pointer
     * @param visited - pointer to store visited vectors count
     */
    void nearest(
            kd_node_t *root,
            kd_node_t *node,
            int i,
            kd_node_t **bestDistanced,
            double *bestDistance,
            unsigned int *visited
    );

public:
    /**
     * Destructor.
     */
    ~KdTree() override;

    /**
     * Default constructor.
     * @param vectors - vectors to store
     * @param count - count of vectors
     * @param dimension - vector dimension
     */
    KdTree(const vector<vector<double>> &vectors, unsigned int count, unsigned int dimension, double *constructionTime);

    /**
    * Find vector in store.
    * If vector is not found, null is returned.
    * @param match  - vector to find
    * @param visited - pointer to store visited vectors count
    * @return found vector or null otherwise
    */
    vector<double> *search(const vector<double> &match, unsigned int *visited) override;
};


#endif //CPP_K_D_TREE_KDTREE_H

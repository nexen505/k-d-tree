#ifndef CPP_K_D_TREE_VECTORCONTAINER_H
#define CPP_K_D_TREE_VECTORCONTAINER_H

#include <vector>

using namespace std;

/**
 * Abstract vector store.
 * It has API to store vector of vectors and search for concrete one.
 */
class VectorStore {
protected:
    /**
     * Count of stored vectors and its dimension.
     */
    unsigned int count, dimension;

public:
    /**
     * Default destructor.
     */
    virtual ~VectorStore() = default;

    /**
     * Default constructor.
     * @param vectors - vectors to store
     * @param count - count of vectors
     * @param dimension - vector dimension
     */
    VectorStore(
            const vector<vector<double>> &vectors,
            unsigned int count,
            unsigned int dimension
    ) : count(count),
        dimension(dimension) {};

    /**
     * Find vector in store.
     * If vector is not found, null is returned.
     * @param match  - vector to find
     * @param visited - pointer to store visited vectors count
     * @return found vector or null otherwise
     */
    virtual vector<double> *search(const vector<double> &match, unsigned int *visited) = 0;
};


#endif //CPP_K_D_TREE_VECTORCONTAINER_H

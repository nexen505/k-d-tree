//
// Created by Ilia on 03.12.2018.
//

#ifndef CPP_K_D_TREE_VECTOROFVECTORS_H
#define CPP_K_D_TREE_VECTOROFVECTORS_H


#include "../VectorStore.h"

/**
 * Store that is based on vector of vectors.
 */
class VectorOfVectors final : public VectorStore {
private:
    /**
     * Vectors storage.
     */
    vector<vector<double>> v_arr;

public:
    /**
     * Destructor.
     */
    ~VectorOfVectors() override;

    /**
     * Default constructor.
     * @param vectors - vectors to store
     * @param count - count of vectors
     * @param dimension - vector dimension
     */
    VectorOfVectors(const vector<vector<double>> &vectors, int count, int dimension);

    /**
    * Find vector in store.
    * If vector is not found, null is returned.
    * @param match  - vector to find
    * @return found vector or null otherwise
    */
    vector<double> *search(const vector<double> &match) override;
};


#endif //CPP_K_D_TREE_VECTOROFVECTORS_H

//
// Created by Ilia on 03.12.2018.
//

#include <cstdio>
#include <sstream>
#include <iterator>
#include "VectorOfVectors.h"

/**
* Default constructor.
* @param vectors - vectors to store
* @param count - count of vectors
* @param dimension - vector dimension
*/
VectorOfVectors::VectorOfVectors(const vector<vector<double>> &vectors, int count, int dimension) : VectorStore(vectors,
                                                                                                                count,
                                                                                                                dimension) {
    this->v_arr = vector<vector<double>>(vectors);
}

/**
 * Search vector by simple linear cycle.
 * If vector is not found, null is returned.
 * @param match - vector to find
 * @return found vector or null otherwise
 */
vector<double> *VectorOfVectors::search(const vector<double> &match, int *visited) {
    vector<double> *result = nullptr;

    for (int i = 0; i < this->count; i++) {
        vector<double> vector = v_arr[i];
        *visited += 1;
        if (vector == match) {
            result = &vector;
            break;
        }
    }

    return result;
}

/**
 * Store destructor. It clears vectors storage.
 */
VectorOfVectors::~VectorOfVectors() {
    v_arr.clear();
    v_arr.shrink_to_fit();
}

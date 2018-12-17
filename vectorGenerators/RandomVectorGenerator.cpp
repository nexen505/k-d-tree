#include <cstdlib>
#include "RandomVectorGenerator.h"

/**
 * Generate vector of concrete dimension randomly.
 * @param dimension - vector dimension
 * @return random vector
 */
vector<double> RandomVectorGenerator::generate(const unsigned int dimension) {
    vector<double> res;
    res.reserve(dimension);

    for (int i = 0; i < dimension; ++i) {
        res.push_back(1 + rand() % 20);
    }

    return res;
}

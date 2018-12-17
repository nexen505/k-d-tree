#ifndef CPP_K_D_TREE_RANDOMVECTORGENERATOR_H
#define CPP_K_D_TREE_RANDOMVECTORGENERATOR_H

#include <vector>
#include "VectorGenerator.h"

using namespace std;

/**
 * Vector generator that is based on random numbers.
 */
class RandomVectorGenerator final : public VectorGenerator {
public:
    vector<double> generate(unsigned int dimension) override;
};


#endif //CPP_K_D_TREE_RANDOMVECTORGENERATOR_H

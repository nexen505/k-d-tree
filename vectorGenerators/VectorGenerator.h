#ifndef CPP_K_D_TREE_VECTORGENERATOR_H
#define CPP_K_D_TREE_VECTORGENERATOR_H

#include <vector>

using namespace std;

/**
 * Abstract vector generator.
 */
class VectorGenerator {
public:
    /**
     * Generate vector of concrete dimension.
     * @param dimension - vector dimension
     * @return generated vector
     */
    virtual vector<double> generate(unsigned int dimension) = 0;

    /**
     * Generate vector of vectors of concrete count and dimension.
     * @param count - count of vectors
     * @param dimension - vector dimension
     * @return generated vector of vectors
     */
    virtual vector<vector<double>> generateList(const unsigned int count, const unsigned int dimension) {
        vector<vector<double>> res;
        for (int i = 0; i < count; ++i) {
            res.push_back(generate(dimension));
        }
        return res;
    };
};


#endif //CPP_K_D_TREE_VECTORGENERATOR_H

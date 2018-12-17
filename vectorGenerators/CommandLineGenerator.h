#ifndef CPP_K_D_TREE_COMMANDLINEGENERATOR_H
#define CPP_K_D_TREE_COMMANDLINEGENERATOR_H


#include "VectorGenerator.h"

/**
 * Generator that is based on user input.
 */
class CommandLineGenerator final : public VectorGenerator {
public:
    vector<double> generate(unsigned int dimension) override;

    vector<vector<double>> generateList(unsigned int count, unsigned int dimension) override;
};


#endif //CPP_K_D_TREE_COMMANDLINEGENERATOR_H

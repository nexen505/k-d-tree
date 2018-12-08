//
// Created by Ilia on 03.12.2018.
//

#ifndef CPP_K_D_TREE_COMMANDLINEGENERATOR_H
#define CPP_K_D_TREE_COMMANDLINEGENERATOR_H


#include "VectorGenerator.h"

/**
 * Generator that is based on user input.
 */
class CommandLineGenerator final : public VectorGenerator {
public:
    vector<double> generate(int dimension) override;

    vector<vector<double>> generateList(int count, int dimension) override;
};


#endif //CPP_K_D_TREE_COMMANDLINEGENERATOR_H

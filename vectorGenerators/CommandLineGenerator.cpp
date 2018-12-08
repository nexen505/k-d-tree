//
// Created by Ilia on 03.12.2018.
//

#include <cstdio>
#include "CommandLineGenerator.h"

/**
 * Generate vector by input coordinates.
 * @param dimension - vector dimension
 * @return input vector
 */
vector<double> CommandLineGenerator::generate(int dimension) {
    vector<double> v;
    for (int j = 0; j < dimension; j++) {
        double data;
        printf("[%d] = ", j);
        scanf("%lf", &data);
        v.push_back(data);
    }
    return v;
}

/**
 * Generate vector by typing vectors.
 * @param count - vectors count
 * @param dimension - vector dimension
 * @return vector of vectors
 */
vector<vector<double>> CommandLineGenerator::generateList(int count, int dimension) {
    vector<vector<double>> vectors;
    for (int i = 0; i < count; i++) {
        printf("Input coordinates of vector %d: \n", i);
        vectors.push_back(generate(dimension));
    }
    return vectors;
}

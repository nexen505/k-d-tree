#include <cstdio>
#include "CommandLineGenerator.h"

/**
 * Generate vector by input coordinates.
 * @param dimension - vector dimension
 * @return input vector
 */
vector<double> CommandLineGenerator::generate(const unsigned int dimension) {
    vector<double> v;
    v.reserve(dimension);
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
vector<vector<double>> CommandLineGenerator::generateList(const unsigned int count, const unsigned int dimension) {
    vector<vector<double>> vectors;
    vectors.reserve(count);
    for (int i = 0; i < count; i++) {
        printf("Input coordinates of vector %d: \n", i);
        vectors.push_back(generate(dimension));
    }
    return vectors;
}

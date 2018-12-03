#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <vector>
#include "store/vector/VectorOfVectors.h"
#include "vectorGenerators/CommandLineGenerator.h"
#include "vectorGenerators/RandomVectorGenerator.h"

using namespace std;

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Rus");
    VectorOfVectors store;
    RandomVectorGenerator vectorGenerator;
    int count = 0, dimension = 0;
    printf("Input vectors count: ");
    scanf("%d", &count);
    printf("Input vector dimension: ");
    scanf("%d", &dimension);
    const vector<vector<double>> &vector = vectorGenerator.generateList(count, dimension);
    printf("Generated list with size %d", vector.size());
    store.add(vector);
    store.search(vectorGenerator.generate(dimension));
    return 0;
}
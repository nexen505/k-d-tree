#include <stdlib.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "store/vector/VectorOfVectors.h"
#include "vectorGenerators/CommandLineGenerator.h"
#include "vectorGenerators/RandomVectorGenerator.h"
#include "store/k-d tree/KdTree.h"

using namespace std;

int main(int argc, char *argv[]) {
    int count = 0, dimension = 0;
    printf("Input vectors count: ");
    scanf("%d", &count);
    printf("Input vector dimension: ");
    scanf("%d", &dimension);

    const int testsCount = 100;
    double vvDuration = 0.0, kdDuration = 0.0;
    RandomVectorGenerator vectorGenerator;
    for (int i = 0; i < testsCount; i++) {
        vector<vector<double>> generatedList = vectorGenerator.generateList(count, dimension);
        vector<double> match = vectorGenerator.generate(dimension);

        VectorStore *store = new VectorOfVectors(generatedList, count, dimension);
        printf("VectorOfVectors: count = %d, dimension = %d\n", count, dimension);
        clock_t start = clock();
        store->search(match);
        double duration = (clock() - start) / (double) CLOCKS_PER_SEC * 1e3;
        printf("VectorOfVectors: search time: %f ms\n", duration);
        vvDuration += duration;
        free(store);

        store = new KdTree(generatedList, count, dimension);
        printf("KdTree: count = %d, dimension = %d\n", count, dimension);
        start = clock();
        store->search(match);
        duration = (clock() - start) / (double) CLOCKS_PER_SEC * 1e3;
        printf("KdTree: search time: %f ms\n", duration);
        kdDuration += duration;
        free(store);
        match.clear();
        for (auto &elm: generatedList) {
            elm.clear();
        }
        generatedList.clear();
    }
    printf("Average search time: VectorOfVectors = %f ms, KdTree = %f ms", vvDuration / testsCount,
           kdDuration / testsCount);

    return 0;
}
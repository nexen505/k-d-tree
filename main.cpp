#include <stdlib.h>
#include <iostream>
#include <vector>
#include <ctime>
#include <cassert>
#include "store/vector/VectorOfVectors.h"
#include "vectorGenerators/CommandLineGenerator.h"
#include "vectorGenerators/RandomVectorGenerator.h"
#include "store/k-d tree/KdTree.h"

using namespace std;

int main(int argc, char *argv[]) {
//    int count = 1000000, dimension = 3;
    int count = 0, dimension = 0;
    printf("Input vectors count: ");
    scanf("%d", &count);
    printf("Input vector dimension: ");
    scanf("%d", &dimension);

    const int testsCount = 30;
    double vvDuration = 0.0, kdDuration = 0.0, kdConstructionDuration = 0.0;
    int vvVisited = 0, kdVisited = 0;
    RandomVectorGenerator vectorGenerator;
    VectorStore *store;
    vector<double> *searchResult, vvSearchResult, kdTreeSearchResult;

    for (int i = 0; i < testsCount; i++) {
        // Generating list and vector to test search
        printf("Starting test %d...\n", i);
        vector<vector<double>> generatedList = vectorGenerator.generateList(count, dimension);
        vector<double> match = vectorGenerator.generate(dimension);

        // Testing vector of vectors
        store = new VectorOfVectors(generatedList, count, dimension);
        printf("\tVectorOfVectors: count = %d, dimension = %d\n", count, dimension);
        clock_t start = clock();
        int visited = 0;
        searchResult = store->search(match, &visited);
        if (searchResult) {
            vvSearchResult = vector<double>(*searchResult);
        }
        double duration = (clock() - start) / (double) CLOCKS_PER_SEC * 1e3;
        printf("\tVectorOfVectors: search time: %f ms, visited: %d of %d\n", duration, visited, count);
        vvVisited += visited;
        vvDuration += duration;
        delete store;

        // Testing K-d tree
        double kdConstruction = 0.0;
        store = new KdTree(generatedList, count, dimension, &kdConstruction);
        printf("\tKdTree: count = %d, dimension = %d\n", count, dimension);
        start = clock();
        visited = 0;
        searchResult = store->search(match, &visited);
        if (searchResult) {
            kdTreeSearchResult = vector<double>(*searchResult);
        }
        assert(vvSearchResult == kdTreeSearchResult);
        duration = (clock() - start) / (double) CLOCKS_PER_SEC * 1e3;
        printf("\tKdTree: construction time: %f ms\n", duration);
        printf("\tKdTree: search time: %f ms, visited: %d of %d\n", duration, visited, count);
        kdVisited += visited;
        kdDuration += duration;
        kdConstructionDuration += kdConstruction;
        delete store;

        // Finishing test with clearing test data
        match.clear();
        match.shrink_to_fit();
        for (auto &elm: generatedList) {
            elm.clear();
            elm.shrink_to_fit();
        }
        generatedList.clear();
        generatedList.shrink_to_fit();
        printf("Finished test %d!\n\n", i);
    }
    printf(
            "Average search stats:\n\tVectorOfVectors = %f ms, %d visited of %d;\n\tKdTree = %f ms, %d visited of %d, average construction = %f ms",
            vvDuration / testsCount,
            vvVisited / testsCount,
            count,
            kdDuration / testsCount,
            kdVisited / testsCount,
            count,
            kdConstructionDuration / testsCount
    );

    return 0;
}
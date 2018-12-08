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
    double vvDuration = 0.0, kdDuration = 0.0;
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
        printf("VectorOfVectors: count = %d, dimension = %d\n", count, dimension);
        clock_t start = clock();
        searchResult = store->search(match);
        if (searchResult) {
            vvSearchResult = vector<double>(*searchResult);
        }
        double duration = (clock() - start) / (double) CLOCKS_PER_SEC * 1e3;
        printf("VectorOfVectors: search time: %f ms\n", duration);
        vvDuration += duration;
        delete store;

        // Testing K-d tree
        store = new KdTree(generatedList, count, dimension);
        printf("KdTree: count = %d, dimension = %d\n", count, dimension);
        start = clock();
        searchResult = store->search(match);
        if (searchResult) {
            kdTreeSearchResult = vector<double>(*searchResult);
        }
        assert(vvSearchResult == kdTreeSearchResult);
        duration = (clock() - start) / (double) CLOCKS_PER_SEC * 1e3;
        printf("KdTree: search time: %f ms\n", duration);
        kdDuration += duration;
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
            "Average search time: VectorOfVectors = %f ms, KdTree = %f ms",
            vvDuration / testsCount,
            kdDuration / testsCount
    );

    return 0;
}
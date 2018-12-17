#include <stdlib.h>
#include <iostream>
#include <vector>
#include <ctime>
#include "store/vector/VectorOfVectors.h"
#include "vectorGenerators/CommandLineGenerator.h"
#include "vectorGenerators/RandomVectorGenerator.h"
#include "store/k-d tree/KdTree.h"
#include "vectorGenerators/FileGenerator.h"

void testFileGenerator(const char *fileName);

void testRandomGenerator();

using namespace std;

int main(int argc, char *argv[]) {
    testFileGenerator("vectors_file.txt");
    testRandomGenerator();
    return 0;
}

void testFileGenerator(const char *fileName) {
    FileGenerator vectorGenerator(fileName);
    VectorStore *store;
    vector<double> *searchResult, vvSearchResult, kdTreeSearchResult = vvSearchResult;
    vector<vector<double>> generatedList = vectorGenerator.getStoreContent();
    vector<double> match = vectorGenerator.getVectorToSearch();

    // Testing vector of vectors
    printf("Starting test for file \'%s\'...\n", fileName);
    const unsigned int storeCount = generatedList.size(), storeDimension = match.size();
    store = new VectorOfVectors(generatedList, storeCount, storeDimension);
    printf("\tVectorOfVectors: count = %d, dimension = %d\n", storeCount, storeDimension);
    clock_t start = clock();
    unsigned int visited = 0;
    searchResult = store->search(match, &visited);
    if (searchResult) {
        vvSearchResult = vector<double>(*searchResult);
    }
    double duration = (clock() - start) / (double) CLOCKS_PER_SEC * 1e3;
    printf("\tVectorOfVectors: search time: %f ms, visited: %d of %d\n", duration, visited, storeCount);
    delete store;

    // Testing K-d tree
    double kdConstruction = 0.0;
    store = new KdTree(generatedList, storeCount, storeDimension, &kdConstruction);
    printf("\tKdTree: count = %d, dimension = %d\n", storeCount, storeDimension);
    start = clock();
    visited = 0;
    searchResult = store->search(match, &visited);
    if (searchResult) {
        kdTreeSearchResult = vector<double>(*searchResult);
    }
    duration = (clock() - start) / (double) CLOCKS_PER_SEC * 1e3;
    printf("\tKdTree: construction time: %f ms\n", duration);
    printf("\tKdTree: search time: %f ms, visited: %d of %d\n", duration, visited, storeCount);
    delete store;

    printf("Finished test for file \'%s\'!\n\n", fileName);
}

void testRandomGenerator() {
//    const unsigned int count = 1000000, dimension = 3, testsCount = 100;
    unsigned int count = 0, dimension = 0, testsCount = 0;
    printf("Input vectors count:\n");
    scanf("%d", &count);
    printf("Input vector dimension:\n");
    scanf("%d", &dimension);
    printf("Input tests count:\n");
    scanf("%d", &testsCount);

    unsigned int failedTestsCount = 0;
    double vvDuration = 0.0, kdDuration = 0.0, kdConstructionDuration = 0.0;
    unsigned int vvVisited = 0, kdVisited = 0;
    RandomVectorGenerator vectorGenerator;
    VectorStore *store;
    for (int i = 0; i < testsCount; i++) {
        // Generating list and vector to test search
        printf("Starting test %d...\n", i);
        try {
            vector<double> *searchResult, vvSearchResult, kdTreeSearchResult = vvSearchResult;
            vector<vector<double>> generatedList = vectorGenerator.generateList(count, dimension);
            vector<double> match = vectorGenerator.generate(dimension);

            // Testing vector of vectors
            const unsigned int storeCount = generatedList.size(), storeDimension = match.size();
            store = new VectorOfVectors(generatedList, storeCount, storeDimension);
            printf("\tVectorOfVectors: count = %d, dimension = %d\n", storeCount, storeDimension);
            clock_t start = clock();
            unsigned int visited = 0;
            searchResult = store->search(match, &visited);
            if (searchResult) {
                vvSearchResult = vector<double>(*searchResult);
            }
            double duration = (clock() - start) / (double) CLOCKS_PER_SEC * 1e3;
            printf("\tVectorOfVectors: search time: %f ms, visited: %d of %d\n", duration, visited, storeCount);
            vvVisited += visited;
            vvDuration += duration;
            delete store;

            // Testing K-d tree
            double kdConstruction = 0.0;
            store = new KdTree(generatedList, storeCount, storeDimension, &kdConstruction);
            printf("\tKdTree: count = %d, dimension = %d\n", storeCount, storeDimension);
            start = clock();
            visited = 0;
            searchResult = store->search(match, &visited);
            if (searchResult) {
                kdTreeSearchResult = vector<double>(*searchResult);
            }
            duration = (clock() - start) / (double) CLOCKS_PER_SEC * 1e3;
            printf("\tKdTree: construction time: %f ms\n", duration);
            printf("\tKdTree: search time: %f ms, visited: %d of %d\n", duration, visited, storeCount);
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
        } catch (const exception &ex) {
            printf("Error while testing: %s, so skipping test..\n", ex.what());
            failedTestsCount++;
        }
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
}
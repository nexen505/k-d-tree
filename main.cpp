#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include <vector>
#include "store/vector/VectorOfVectors.h"

using namespace std;

int main(int argc, char *argv[]) {
    setlocale(LC_ALL, "Rus");
    VectorOfVectors store;
    int VArr_size;
    printf("Input vectors count: ");
    scanf("%d", &VArr_size);
    int v_size;
    printf("Input vector dimension: ");
    scanf("%d", &v_size);
    for (int i = 0; i < VArr_size; i++) {
        vector<double> v;
        printf("Input coordinates of vector %d: \n", i);
        for (int j = 0; j < v_size; j++) {
            double data;
            printf("[%d] = ", j);
            scanf("%lf", &data);
            v.push_back(data);
        }
        store.add(v);
    }
    vector<double> match;
    printf("Input coordinates of vector to search: \n");
    for (int i = 0; i < v_size; i++) {
        double data;
        printf("[%d] = ", i);
        scanf("%lf", &data);
        match.push_back(data);
    }
    store.search(match);
    printf("\n");
    return 0;
}
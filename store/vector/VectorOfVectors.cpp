//
// Created by Ilia on 03.12.2018.
//

#include <cstdio>
#include <ctime>
#include "VectorOfVectors.h"

void VectorOfVectors::add(vector<double> a) {
    v_arr.push_back(a);
}

void VectorOfVectors::search(vector<double> match) {
    clock_t start = clock();
    double duration;

    int ind = -1;
    for (int i = 0; i < v_arr.size(); i++) {
        if (v_arr[i] == match) {
            ind = i;
            break;
        }
    }

    duration = (clock() - start) / (double) CLOCKS_PER_SEC;
    printf("Search calculation time: %f\n", duration);
    if (ind != -1) {
        printf("Element was found at index %d\n", ind);
    } else
        printf("Element was not found.\n");
}
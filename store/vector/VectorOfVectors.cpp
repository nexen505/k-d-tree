//
// Created by Ilia on 03.12.2018.
//

#include <cstdio>
#include <ctime>
#include <sstream>
#include <iterator>
#include "VectorOfVectors.h"

void VectorOfVectors::add(vector<double> a) {
    v_arr.push_back(a);
}

void VectorOfVectors::search(vector<double> match) {
    clock_t start = clock();
    double duration;

    int ind = -1;
    ostringstream vts;
    for (int i = 0; i < v_arr.size(); i++) {
        vector<double> &vector = v_arr[i];
        /*copy(vector.begin(), vector.end() - 1, ostream_iterator<int>(vts, ", "));
        vts << vector.back();
        cout << vts.str() << endl;
        vts.clear();*/
        if (vector == match) {
            ind = i;
            break;
        }
    }

    duration = (clock() - start) / (double) CLOCKS_PER_SEC * 1e3;
    printf("Search calculation time: %f ms\n", duration);
    if (ind != -1) {
        printf("Element was found at index %d\n", ind);
    } else
        printf("Element was not found.\n");
}

void VectorOfVectors::add(vector<vector<double>> vv) {
    VectorStore::add(vv);
}

#ifndef CPP_K_D_TREE_FILEGENERATOR_H
#define CPP_K_D_TREE_FILEGENERATOR_H

#include <string>
#include <fstream>
#include <vector>

using namespace std;

class FileGenerator {
private:
    vector<vector<double>> storeContent;

    vector<double> vectorToSearch;
public:
    ~FileGenerator() = default;

    explicit FileGenerator(string fileName);

    vector<double> getVectorToSearch();

    vector<vector<double>> getStoreContent();
};


#endif //CPP_K_D_TREE_FILEGENERATOR_H

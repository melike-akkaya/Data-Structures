#include <iostream>
#include "Utility.h"
#include "MapOperations.h"

using namespace std;

int main(int argc, char** argv) {
    // obtaining necessary information from the user
    string mapSizeString = argv[1];
    string keySizeString = argv[2];
    string mapMatrixPath = argv[3];
    string keyMatrixPath = argv[4];
    string outputMatrixPath = argv[5];

    // converting keySize value to integer
    stringstream stringToInteger;
    stringToInteger << keySizeString;
    int keySize;
    stringToInteger >> keySize;

    // converting mapSize value to integer
    int *mapSizeList = Utility::split(mapSizeString, 2, 'x');

    int **keyMatrix = Utility::readFile(keyMatrixPath , keySize,keySize);
    int **mapMatrix = Utility::readFile(mapMatrixPath,mapSizeList[0],mapSizeList[1]);

    int firstCoords[] = {0, 0};

    int firstMod = (MapOperations::multiplicationCalculator(mapMatrix, keyMatrix, keySize, firstCoords)) % 5;

    // to create output file
    fstream file;
    file.open(outputMatrixPath, ios::out);

    MapOperations::move(firstMod, mapMatrix, keyMatrix, firstCoords, keySize, mapSizeList[0],mapSizeList[1], file);

    file.close();

    // to clear the memory
    for (int i = 0; i < keySize; i++) {
        delete[] keyMatrix[i];
    }
    delete[] keyMatrix;

    for (int i = 0; i < mapSizeList[0]; i++) {
        delete[] mapMatrix[i];
    }
    delete[] mapMatrix;

    return 0;
}
//
// Created by melik on 28.10.2022.
//

#ifndef ASSIGNMENT1_MAPOPERATIONS_H
#define ASSIGNMENT1_MAPOPERATIONS_H

#include <string>
#include <fstream>

using namespace std;


class MapOperations {
    public:
        static int multiplicationCalculator(int **map, int **key, int keySize, int firstCoords[]);

        static void move(int mod, int **map, int **key, int firstCoords[], int keySize, int maxRow, int maxColumn, fstream &file);
};


#endif //ASSIGNMENT1_MAPOPERATIONS_H

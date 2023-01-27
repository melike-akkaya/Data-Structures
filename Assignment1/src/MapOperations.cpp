//
// In this class, map operations were done.
//

#include <iostream>
#include "MapOperations.h"

// In this method, the product of the key has been calculated matrix and the map matrix has been calculated.
int MapOperations::multiplicationCalculator(int **map, int **key, int keySize, int *firstCoords) {
    int result = 0;


    for (int row = 0; row < keySize; row++) {
        for (int column = 0; column < keySize; column++) {
            result += map[firstCoords[0] + row][firstCoords[1] + column] * key[row][column];
        }
    }

    while (result < 0) {
        result += 5;
    }

    return result;
}

// In this method, the key matrix has been moved according to the mode value of the product.
void MapOperations::move(int mod, int **map, int **key, int *firstCoords, int keySize, int maxRow, int maxColumn,
                         fstream &file) {
    // go up
    if (mod == 1) {
        if (firstCoords[0] - keySize < 0) {
            move (2, map, key, firstCoords, keySize, maxRow, maxColumn, file);
        }
        else {
            file << firstCoords[0] + keySize/2 <<"," <<firstCoords[1] + keySize/2 << ":" <<
                    multiplicationCalculator(map, key, keySize, firstCoords) << "\n";

            firstCoords[0] -= keySize;
            move ((multiplicationCalculator(map, key, keySize, firstCoords)) % 5, map, key, firstCoords, keySize, maxRow, maxColumn, file);
        }
    }

        // go down
    else if (mod == 2) {
        if ((firstCoords[0] + 2*keySize - 1) > maxRow) {
            move (1, map, key, firstCoords, keySize, maxRow, maxColumn, file);
        }
        else {
            file << firstCoords[0] + keySize/2 <<"," <<firstCoords[1] + keySize/2 << ":" <<
                 multiplicationCalculator(map, key, keySize, firstCoords) << "\n";

            firstCoords[0] += keySize;

            move ((multiplicationCalculator(map, key, keySize, firstCoords)) % 5, map, key, firstCoords, keySize, maxRow, maxColumn, file);
        }
    }

        // go right
    else if (mod == 3) {
        if ((firstCoords[1] + 2*keySize - 1) > (maxColumn - 1)) {
            move (4, map, key, firstCoords, keySize, maxRow, maxColumn, file);
        }
        else {
            file << firstCoords[0] + keySize/2 <<"," <<firstCoords[1] + keySize/2 << ":" <<
                 multiplicationCalculator(map, key, keySize, firstCoords) << "\n";

            firstCoords[1] += keySize;
            move ((multiplicationCalculator(map, key, keySize, firstCoords)) % 5, map, key, firstCoords, keySize, maxRow, maxColumn, file);
        }
    }

        // go left
    else if (mod == 4) {
        if ((firstCoords[1] - keySize) < 0) {
            move (3, map, key, firstCoords, keySize, maxRow, maxColumn, file);
        }
        else {
            file << firstCoords[0] + keySize/2 <<"," <<firstCoords[1] + keySize/2 << ":" <<
                 multiplicationCalculator(map, key, keySize, firstCoords) << "\n";

            firstCoords[1] -= keySize;
            move ((multiplicationCalculator(map, key, keySize, firstCoords)) % 5, map, key, firstCoords, keySize, maxRow, maxColumn, file);
        }
    }

        //found treasure
    else if (mod == 0) {
        file << firstCoords[0] + keySize/2 <<"," <<firstCoords[1] + keySize/2 << ":" <<
             multiplicationCalculator(map, key, keySize, firstCoords);
    }

}

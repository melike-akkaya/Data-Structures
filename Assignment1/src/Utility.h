//
// Created by melik on 28.10.2022.
//

#ifndef ASSIGNMENT1_UTILITY_H
#define ASSIGNMENT1_UTILITY_H

#include <string>
#include <fstream>
#include <sstream>

using namespace std;



class Utility {
    public:
        static int* split(string str, int size, char separator);
        static int **readFile(string fileName, int row, int column);
};


#endif //ASSIGNMENT1_UTILITY_H

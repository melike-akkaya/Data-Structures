//
// Created by melik on 19.12.2022.
//

#ifndef ASS4_UTILITY_H
#define ASS4_UTILITY_H

#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

class Utility {
    public:
        static vector<string> split(string str, char brace);
        static int stringToInteger (string str);
        static vector<vector<string>> readFile(string fileName);
};


#endif //ASS4_UTILITY_H

#ifndef ASS2_UTILITY_H
#define ASS2_UTILITY_H

#include <string>
#include <sstream>
#include <vector>
using namespace std;

class Utility {
public:
    static vector<string> split(string str, char brace);
    static int toInt (string stringValue);
};


#endif //ASS2_UTILITY_H
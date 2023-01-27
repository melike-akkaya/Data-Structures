//
// In this class, I have functions that I use frequently in assignment and that I can use in my next assignments.
//

#include "Utility.h"
#include <iostream>

// to make a list by splitting a string
vector<string> Utility::split(string str, char brace) {
    vector<string> list;

    // declaring temp store upto brace
    string temp = "";

    for(char i : str){
        if(i != brace){
            temp += i;
        }
        else{
            list.push_back(temp);
            temp = "";
        }
    }

    list.push_back(temp);

    return list;
}

int Utility::toInt(string stringValue) {
    stringstream stringToInteger;
    int integerValue = 0;
    //string stream takes the string
    stringToInteger << stringValue;
    //string stream gives the integer
    stringToInteger >> integerValue;

    return integerValue;
}
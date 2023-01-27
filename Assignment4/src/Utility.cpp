//
// Created by melik on 19.12.2022.
//

#include "Utility.h"

// to make a list by splitting a string
vector<string> Utility::split(string str, char brace) {
    vector<string> list;

    // declaring temp store upto brace
    string temp = "";

    for (char i : str){
        if (i != brace){
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

vector<vector<string>> Utility::readFile(string fileName) {
    vector<vector<string>> returnVector;

    ifstream inputFile(fileName);
    string line;

    while (getline(inputFile, line)) {
        vector<string> lineVector = split(line, '\t');
        returnVector.push_back(lineVector);
    }
    inputFile.close();

    return returnVector;
}

int Utility::stringToInteger(string str) {
    // creating a string stream in order to convert string to int
    stringstream stringToInt;
    // to give string value to string stream object
    stringToInt << str;
    // to find the int value from string
    int temp = 0;
    stringToInt >> temp;
    return temp;
}

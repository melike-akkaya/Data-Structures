#include <iostream>
#include "Utility.h"

// to make a list by splitting a string
vector<double> Utility::split(string str, char brace) {
    vector<double> list;

    // declaring temp store upto brace
    string temp = "";

    for (char i : str){
        if (i != brace){
            temp += i;
        }
        else{
            double tempDouble = toDouble(temp);
            list.push_back(tempDouble);
            temp = "";
        }
    }

    double tempDouble = toDouble(temp);
    list.push_back(tempDouble);

    return list;
}

double Utility::toDouble(string temp) {
    double tempDouble = 0.0;

    // creating a string stream in order to convert string to double
    stringstream ss;
    // to give string value to string stream object
    ss << temp;
    // to find the double value from string
    ss >> tempDouble;

    return tempDouble;
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

void Utility::readFile(vector<Order> *orders, vector<Barista> *baristas, vector<Cashier> *cashiers, vector<Order> *orders2, vector <Barista> *baristas2, vector<Cashier> *cashiers2, string fileName) {
    // to read file
    ifstream inputFile(fileName);
    string line;

    // first 2 lines are representing the number of baristas and cashiers
    int index = 0;
    while (getline(inputFile, line)) {
        if (index == 0) {
            int cashierNumber = toInt(line);
            // to create a given number of cashier objects
            for (int i = 0; i < cashierNumber; i++) {
                Cashier* c = new Cashier(i);
                cashiers->push_back(*c);
                cashiers2->push_back(*c);
            }
            int baristaNumber = cashierNumber/3;
            // to create a given number of cashier objects
            for (int i = 0; i < baristaNumber; i++) {
                Barista* b = new Barista(i);
                baristas->push_back(*b);
                baristas2->push_back(*b);
            }
        }

        else if (index != 1) {
            // constValues have the values that an order needs
            vector<double> constValues = Utility::split(line, ' ');
            Order* o = new Order (constValues.at(0), constValues.at(1), constValues.at(2), constValues.at(3));
            orders->push_back(*o);
            orders2->push_back(*o);
        }
        index++;
    }
    inputFile.close();
}

double Utility::round(double var) {
    double value = (int)(var * 100 + .5);
    value = value / 100;

    // in order to write 0 in doubles with 0 after the dot:


    return value;

}




#ifndef ASSIGNMENT3_UTILITY_H
#define ASSIGNMENT3_UTILITY_H

#include <string>
#include <vector>
#include <sstream>
#include "Order.h"
#include "Barista.h"
#include "Cashier.h"
#include <fstream>
#include <iostream>

using namespace std;

class Utility {
    public:
        static vector<double> split(string str, char brace);
        static double toDouble (string temp);
        static int toInt(string stringValue);
        static void readFile(vector<Order> *orders, vector <Barista> *baristas, vector<Cashier> *cashiers, vector<Order> *orders2, vector <Barista> *baristas2, vector<Cashier> *cashiers2, string fileName);
        static double round(double var);
};


#endif //ASSIGNMENT3_UTILITY_H

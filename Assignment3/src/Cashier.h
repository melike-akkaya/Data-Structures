#ifndef ASSIGNMENT3_CASHIER_H
#define ASSIGNMENT3_CASHIER_H

#include "Barista.h"
#include "Order.h"

using namespace std;

class Cashier {
public:
    Cashier(int ID);

    int cashierID;
    bool isAvailable;
    double totalWorkingTime;
    Order* order;
};



#endif //ASSIGNMENT3_CASHIER_H
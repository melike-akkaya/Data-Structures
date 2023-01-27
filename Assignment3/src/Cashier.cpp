// in this class, properties of Cashier objects are determined with the help of a constructor

#include "Cashier.h"

Cashier::Cashier(int ID) {
    this->cashierID = ID;
    this->isAvailable = true;
    this->totalWorkingTime = 0;
    this->order = 0;
}
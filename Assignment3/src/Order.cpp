// in this class, properties of Order objects are determined with the help of a constructor

#include "Order.h"

Order::Order(double arrival, double order, double brew, double price) {
    this->arrivalTime = arrival;
    this->orderTime = order;
    this->brewTime = brew;
    this->price = price;
    this->cashierID = -1;
    this->baristaID = -1;
    this->isOrderTaken = false;
    this->isBrewTaken = false;
    this->turnAroundTime = -1;
}

Order::Order() {}
#ifndef ASSIGNMENT3_ORDER_H
#define ASSIGNMENT3_ORDER_H


class Order {
public:
    double arrivalTime;
    double orderTime;
    double brewTime;
    double price;
    double turnAroundTime;

    int cashierID;
    int baristaID;

    bool isOrderTaken;
    bool isBrewTaken;

    Order(double arrival, double order, double brew, double price);
    Order();

};


#endif //ASSIGNMENT3_ORDER_H
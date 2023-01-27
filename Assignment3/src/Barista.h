#ifndef ASSIGNMENT3_BARISTA_H
#define ASSIGNMENT3_BARISTA_H


#include "Order.h"
#include "Queue.h"

class Barista {
public:
    Barista(int ID);
    bool isAvailable;
    double totalWorkingTime;
    Order* order;
    int baristaID;

    Queue* brewQueueForSecondModel = new Queue();
};


#endif //ASSIGNMENT3_BARISTA_H
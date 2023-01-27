#ifndef ASSIGNMENT3_DISCRETEEVENTLIST_H
#define ASSIGNMENT3_DISCRETEEVENTLIST_H

#include "Order.h"

struct discreteEvent {
    discreteEvent* next;

    double time;
    Order* order;
};

class DiscreteEventList {
public:
    discreteEvent* head;

    DiscreteEventList();

    void add (double time, Order* order);
    void pop();
};


#endif //ASSIGNMENT3_DISCRETEEVENTLIST_H

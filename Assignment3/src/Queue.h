//
// Created by melik on 30.11.2022.
//

#ifndef ASSIGNMENT3_QUEUE_H
#define ASSIGNMENT3_QUEUE_H

#include "Order.h"

struct Node {
    Order* order;
    Node* nextNode;
};

class Queue {
public:
    Node* head;
    Node* tail;

    int size;
    int maxSize; //a variable that is used to hold the largest size value obtained while processing the object

    void addOrder (Order* newOrder);
    Order* removeOrder ();
    bool isEmpty();
    void sort();

    Queue();
};

#endif //ASSIGNMENT3_QUEUE_H

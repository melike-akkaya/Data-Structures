#include "Queue.h"
#include <iostream>
using namespace std;
Queue::Queue() {
    this->head = 0;
    this->tail = 0;
    this->size = 0;
    this->maxSize = 0;
}

bool Queue:: isEmpty()  {
    return this->size == 0;
}

void Queue::addOrder(Order* newOrder) {
    // creating node
    Node * newOrderNode = new Node;
    newOrderNode->order = newOrder;

    // to control if queue is empty
    if (isEmpty()) {
        this->head = newOrderNode;
        this->tail = newOrderNode;
        newOrderNode->nextNode = 0;
    }
        // if the queue is not empty, it is enough the add the node as tail
    else {
        this->tail->nextNode = newOrderNode;
        newOrderNode->nextNode = 0;
        this->tail = newOrderNode;
    }
    size ++;

    // to control if the queue has its max size
    if (size > maxSize) {
        maxSize = size;
    }
}

Order* Queue::removeOrder() {
    Order* returnValue = new Order;

    // to control if the queue is not empty
    if (this->head != 0) {
        returnValue = this->head->order;

        // to control if there is only one node
        if (this->head->nextNode == 0) {
            this->tail = 0;
            this->head = 0;
        }
        else {
            this->head = head->nextNode;
        }
        size--;
    }
    return returnValue;
}

// This function enables sorting by price on brew queue
void Queue::sort(){
    Node* temp = this->head;
    Node* tempNext = 0;

    if (size != 0) {
        while (temp != 0) {
            tempNext = temp->nextNode;

            while (tempNext != 0) {
                if (temp->order->price < tempNext->order->price) {
                    Order* tempOrder = temp->order;
                    temp->order = tempNext->order;
                    tempNext->order = tempOrder;
                }
                tempNext = tempNext->nextNode;
            }
            temp = temp->nextNode;
        }
    }
}

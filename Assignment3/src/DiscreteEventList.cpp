// Since we use discrete events in assignment, only certain times of the work are important.
// For example, when we evaluate the time of preparing the given order, we do not care about the mishaps
// that happened to the barita while preparing the order. Whether it was an earthquake or not, we're only
// interested in the brew time of the order. The design for the assignment needed a list to hold discrete events.
// This class was created for this reason.

#include "DiscreteEventList.h"

// Initially head is set to null to create an empty list.
DiscreteEventList::DiscreteEventList() {
    this->head = 0;
}

// This function constantly compares the times and finds the appropriate place in the list and adds it.
void DiscreteEventList::add(double time, Order *order) {
    discreteEvent* eventToBeAdded = new discreteEvent;
    eventToBeAdded->time = time;
    eventToBeAdded->order = order;


    if (this->head != 0) {
        discreteEvent* tempEvent = this->head;
        // If the duration of the inserted event is shorter than the duration of the first element in the list,
        // it adds to the top of the list.
        if (tempEvent->time > time) {
            eventToBeAdded->next = this->head;
            this->head = eventToBeAdded;
        }
        else {
            while (tempEvent != 0) {
                if (tempEvent->time < time) {
                    if ((tempEvent->next != 0) and (tempEvent->next->time > time)) {
                        eventToBeAdded->next = tempEvent->next;
                        tempEvent->next = eventToBeAdded;
                    }
                    else if (tempEvent->next == 0) {
                        eventToBeAdded->next = tempEvent->next;
                        tempEvent->next = eventToBeAdded;
                    }
                }
                tempEvent = tempEvent->next;
            }
        }
    }
    else { // if list is empty
        this->head = eventToBeAdded;
        eventToBeAdded->next = 0;
    }
}

// Since head is the first task in the list to be completed,
// this function is used to delete a task from the list when it is completed.
void DiscreteEventList::pop() {
    if (this->head != 0) {
        this->head = this->head->next;
    }
}
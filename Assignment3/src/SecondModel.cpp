#include "SecondModel.h"

// This function is used to match the order with the cashier.
void SecondModel::connectOrderToCashier(Cashier *processCashier, Order *processOrder) {
    processCashier->order = processOrder;
    processCashier->isAvailable = false;
    processCashier->totalWorkingTime += processOrder->orderTime;
    processOrder->cashierID = processCashier->cashierID;
    processOrder->isOrderTaken = true;
}

// This function is used to match the order with the barista.
void SecondModel::connectOrderToBarista(Barista *processBarista, Order *processOrder) {
    processBarista->order = processOrder;
    processBarista->isAvailable = false;
    processBarista->totalWorkingTime += processOrder->brewTime;
    processOrder->baristaID = processBarista->baristaID;
    processOrder->isBrewTaken = true;
}


void SecondModel::shoppingSystem(vector<Order> *orders, vector<Barista> *baristas, vector<Cashier> *cashiers) {

    for (Order &order:*orders) {
        this->discreteEvents->add(order.arrivalTime, &order);
    }

    while (discreteEvents->head != 0) {
        bool availableCashier = false;
        // This part ensures that if the order has not been received and there is an available cashier the order is taken,
        // and if there is no available cashier, order enters the queue.
        if (!(discreteEvents->head->order->isOrderTaken)) {
            for (Cashier &cashier : *cashiers) {
                if (cashier.isAvailable) {
                    connectOrderToCashier(&cashier, discreteEvents->head->order);
                    discreteEvents->add((discreteEvents->head->time + discreteEvents->head->order->orderTime),
                                        discreteEvents->head->order);
                    availableCashier = true;
                    discreteEvents->pop();
                    break;
                }
            }
            if (!availableCashier) {
                this->orderQueue->addOrder(discreteEvents->head->order);
                discreteEvents->pop();
            }
        }
        // This part initiates the execution of completed orders. For this, it constantly checks
        // whether there is a barista available for incoming orders, and if it cannot find a suitable barista,
        // it puts the order in the queue.
        else if (!(discreteEvents->head->order->isBrewTaken)) {
            Cashier *processCashier = &(cashiers->at(discreteEvents->head->order->cashierID));
            Order *orderToBrew = discreteEvents->head->order;
            if (orderQueue->isEmpty()) {
                processCashier->isAvailable = true;
                processCashier->order = 0;
            }
            else {
                Order* tempOrder = orderQueue->removeOrder();
                connectOrderToCashier(processCashier, tempOrder);
                discreteEvents->add(discreteEvents->head->time + tempOrder->orderTime, tempOrder);
            }

            Barista* responsibleBarista = &(baristas->at((discreteEvents->head->order->cashierID) / 3));
            if (responsibleBarista->isAvailable) {
                connectOrderToBarista(responsibleBarista, orderToBrew);
                discreteEvents->add((discreteEvents->head->time + discreteEvents->head->order->brewTime),orderToBrew);
                discreteEvents->pop();
            }

            else {
                Queue* brewQueue = responsibleBarista->brewQueueForSecondModel;
                brewQueue->addOrder(discreteEvents->head->order);
                brewQueue->sort();
                discreteEvents->pop();
            }
        }
        // This part follows the completion of the preparation of the incoming orders for preparation.
        // The last dicrete event takes place here, so the operating time of the system is determined here.
        // In addition, this is the last part of all orders, so the turn around times of orders are determined here.
        else {
            Barista *processBarista = &(baristas->at(discreteEvents->head->order->baristaID));
            discreteEvents->head->order->turnAroundTime = discreteEvents->head->time - discreteEvents->head->order->arrivalTime;

            Barista* responsibleBarista = &(baristas->at((discreteEvents->head->order->cashierID) / 3));
            Queue* brewQueue = responsibleBarista->brewQueueForSecondModel;
            if (brewQueue->isEmpty()) {
                processBarista->isAvailable = true;
                processBarista->order = 0;
                discreteEvents->pop();
            }
            else {
                Order* tempOrder = brewQueue->removeOrder();
                connectOrderToBarista(processBarista, tempOrder);
                discreteEvents->add(discreteEvents->head->time +tempOrder->brewTime, tempOrder);

                this->runningTime = (discreteEvents->head->time) + tempOrder->brewTime;

                discreteEvents->pop();
            }
        }
    }
}
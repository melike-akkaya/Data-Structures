#ifndef ASSIGNMENT3_SECONDMODEL_H
#define ASSIGNMENT3_SECONDMODEL_H

#include "Queue.h"
#include "Order.h"
#include "Barista.h"
#include "Cashier.h"
#include "DiscreteEventList.h"
#include <vector>


class SecondModel {
    public:
        double runningTime = 0;
        Queue* orderQueue = new Queue();
        // brew queue will be accessed from vector of baristas given as parameters to functions
        DiscreteEventList* discreteEvents = new DiscreteEventList();

        void shoppingSystem(vector<Order> *orders, vector<Barista> *baristas, vector<Cashier> *cashiers);
        static void connectOrderToCashier(Cashier *processCashier, Order *processOrder);
        static void connectOrderToBarista(Barista *processBarista, Order *processOrder);

};


#endif //ASSIGNMENT3_SECONDMODEL_H

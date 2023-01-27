#ifndef ASSIGNMENT3_FIRSTMODEL_H
#define ASSIGNMENT3_FIRSTMODEL_H

#include "Queue.h"
#include "Order.h"
#include "Barista.h"
#include "Cashier.h"
#include <vector>
#include "DiscreteEventList.h"

class FirstModel {
    public:
        double runningTime = 0;
        Queue* orderQueue = new Queue();
        Queue* brewQueue = new Queue();
        DiscreteEventList* discreteEvents = new DiscreteEventList();

        void shoppingSystem(vector<Order> *orders, vector<Barista> *baristas, vector<Cashier> *cashiers);
        static void connectOrderToCashier(Cashier *processCashier, Order *processOrder);
        static void connectOrderToBarista(Barista *processBarista, Order *processOrder);
};


#endif //ASSIGNMENT3_FIRSTMODEL_H
#include <iostream>
#include "Utility.h"
#include "FirstModel.h"
#include "SecondModel.h"

using namespace std;

int main(int argc, char** argv) {
    //Two co-vectors were created for Order, Barista and Cashier.
    // One is used for the first model and the other for the second model.

    // order objects were created and kept in this vector to track orders properly
    vector<Order> orders;
    vector<Order> orders2;

    // barista objects were created and kept in this vector
    vector <Barista> baristas;
    vector <Barista> baristas2;

    // cashier objects were created and kept in this vector
    vector <Cashier> cashiers;
    vector <Cashier> cashiers2;

    // to read file and add objects of vectors
    Utility::readFile(&orders,&baristas,&cashiers, &orders2,&baristas2,&cashiers2, argv[1]);

    // to create output file
    fstream outputFile;
    outputFile.open(argv[2], ios::out);

    //output printing part for the first model:
    FirstModel fm;
    fm.shoppingSystem(&orders, &baristas, &cashiers);

    outputFile<<fm.runningTime<<endl; //total running time of first model
    outputFile<<fm.orderQueue->maxSize<<endl<<fm.brewQueue->maxSize<<endl; // number of people in longest queues
    for (Cashier &cashier : cashiers) { //utilization for cashier
        outputFile<<Utility::round((cashier.totalWorkingTime)/fm.runningTime)<<endl;
    }
    for (Barista &barista: baristas) { // utilization for barista
        outputFile<<Utility::round((barista.totalWorkingTime)/fm.runningTime)<<endl;
    }
    for (Order &order : orders) { //orders' turnaround time
        outputFile<<order.turnAroundTime<<endl;
    }

    outputFile<<endl;

    //output printing part for the second model:
    SecondModel sm;
    sm.shoppingSystem(&orders2, &baristas2, &cashiers2);

    outputFile<<sm.runningTime<<endl; //total running time of second model
    outputFile<<sm.orderQueue->maxSize<<endl; // number of people in longest order queue
    for (Barista &barista : baristas2) { // number of people in longest brew queue
        outputFile<<barista.brewQueueForSecondModel->maxSize<<endl;
    }
    for (Cashier &cashier : cashiers2) { //utilization for cashier
        outputFile<<Utility::round((cashier.totalWorkingTime)/sm.runningTime)<<endl;
    }

    for (Barista &barista: baristas2) { //utilization for barista
        outputFile<<Utility::round((barista.totalWorkingTime)/sm.runningTime)<<endl;
    }
    for (Order &order : orders2) { //orders' turnaround time
        outputFile<<order.turnAroundTime<<endl;
    }

    outputFile.close();

    return 0;
}
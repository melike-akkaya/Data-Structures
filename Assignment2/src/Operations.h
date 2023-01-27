#ifndef ASS2_OPERATIONS_H
#define ASS2_OPERATIONS_H

#include "ApartmentLinkedList.h"
#include "FlatLinkedList.h"
#include "Utility.h"
#include <iostream>
#include <fstream>


class Operations {
public:
    static void addApartment(Apartment mustAdd, ApartmentLinkedList* apartments, string command);
    static bool addFlat(ApartmentNode* tempApartment, vector<string> command);
    static ApartmentLinkedList * removeApartment(ApartmentLinkedList* apartments, string name, fstream &outputFile);
    static void makeFlatEmpty (ApartmentLinkedList* apartments, vector<string> command, fstream &outputFile);
    static int findSumOfMaxBandwidth (ApartmentLinkedList* apartments);
    static ApartmentLinkedList * mergeApartments (ApartmentLinkedList* apartments, vector<string> names, fstream &outputFile);
    static void relocate(ApartmentLinkedList *apartments, vector<string> temp);
};


#endif //ASS2_OPERATIONS_H
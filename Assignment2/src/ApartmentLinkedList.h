#ifndef ASS2_APARTMENTLINKEDLIST_H
#define ASS2_APARTMENTLINKEDLIST_H

#include "Apartment.h"
#include <string>

struct ApartmentNode {
    Apartment data = *new Apartment;
    ApartmentNode* nextApartment;
};

// it is a circular linked list
class ApartmentLinkedList {
public:
    ApartmentNode* head;
    ApartmentNode* tail;

    ApartmentLinkedList();


    static void add (ApartmentLinkedList* apartments, const Apartment& prevApartment, Apartment newApartment);
    static void addHead (ApartmentLinkedList* apartments, Apartment newApartment);
    static void remove (ApartmentLinkedList* apartments, Apartment deleteApartment);
};


#endif //ASS2_APARTMENTLINKEDLIST_H
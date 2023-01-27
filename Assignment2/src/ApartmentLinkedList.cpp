//
// In this file, I am creating a circular linked list with apartments in it.
//

#include "ApartmentLinkedList.h"

// Initially head and tail are null
ApartmentLinkedList::ApartmentLinkedList() {
    head = NULL;
    tail = NULL;
}

// this method crates a node which contains the data of newApartmant object
// add the node which is created after the node with the data of prevApartment object
void ApartmentLinkedList :: add (ApartmentLinkedList* apartments, const Apartment& prevApartment, Apartment newApartment) {
    // it will scroll through the list and find where to add
    ApartmentNode* temp = apartments->head;
    while ((temp -> data) != prevApartment) {
        temp = temp->nextApartment;
    }

    // creating the node and adding it
    ApartmentNode* nodeToBeAdded = new ApartmentNode;
    nodeToBeAdded -> data = newApartment;
    nodeToBeAdded -> nextApartment = temp -> nextApartment;
    temp -> nextApartment = nodeToBeAdded;

    // if it is the last node of the linked list
    if (nodeToBeAdded->nextApartment == apartments->head) {
        apartments->tail = nodeToBeAdded;
    }
}

// this method creates a node which contains the data of newApartment object
// and add the node at the head of the linked list
void ApartmentLinkedList :: addHead(ApartmentLinkedList* apartments, Apartment newApartment) {
    // creating the node
    ApartmentNode* nodeToBeAdded = new ApartmentNode;
    nodeToBeAdded -> data = newApartment;

    // if the linked list is empty
    if(apartments->head == NULL) {
        apartments->head = nodeToBeAdded;
        apartments->tail = nodeToBeAdded;
        nodeToBeAdded->nextApartment = nodeToBeAdded;
    }
    else {
        nodeToBeAdded -> nextApartment = apartments->head;
        apartments->head = nodeToBeAdded;
        apartments->tail->nextApartment = nodeToBeAdded;
    }
}

void ApartmentLinkedList::remove(ApartmentLinkedList *apartments, Apartment deleteApartment) {
    // it will scroll through the list and find where to remove
    ApartmentNode* tempApartment = apartments->head;

    ApartmentNode* delApartment;

    // if we want to remove the head of the list
    if (tempApartment->data == deleteApartment) {
        delApartment = apartments->head;
        apartments->head = tempApartment->nextApartment;
        apartments->tail->nextApartment = apartments->head;
        if (deleteApartment == apartments->head->data) {
            apartments->head = NULL;
            apartments->tail = NULL;
        }
    }

    else {
        // finding the node which is before the node we want to delete
        while (tempApartment->nextApartment->data != deleteApartment) {
            tempApartment = tempApartment->nextApartment;
        }
        delApartment = tempApartment->nextApartment;

        tempApartment->nextApartment = tempApartment->nextApartment->nextApartment;

        // to control if removing was at the tail of the list
        // since it is a circle linked list, the next node of the tail is head
        if (tempApartment->nextApartment == apartments->head) {
            apartments->tail = tempApartment;
        }
    }

    // I tried to delete the flats of the apartment in this part of my code (91-98)
    // Although this part was working on my computer, it was giving segmentation fault in dev.
    // Since I couldn't fix it, I put it in the comment line while submitting the assignment.

/*    FlatNode* temp = deleteApartment.getFlats()->head;;
    while (temp != NULL) {
        FlatNode* del = temp;
        temp = temp->nextFlat;
        if (temp != NULL)
            temp->previousFlat = NULL;
        delete del;
    }*/


    delete delApartment;
}
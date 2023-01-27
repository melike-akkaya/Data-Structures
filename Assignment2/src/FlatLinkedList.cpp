//
// In this file, I am creating a doubly linked list with flats in it.
//

#include "FlatLinkedList.h"

FlatLinkedList::FlatLinkedList() {
    head = NULL;
    tail = NULL;
}

// this method creates a node and add it to the linked list
void FlatLinkedList::add(FlatLinkedList* flats, int index, Flat newFlat) {
    // creating the node
    FlatNode *nodeToBeAdded = new FlatNode;
    nodeToBeAdded->data = newFlat;

    // if we want to add as the head of the list
    if (index == 0) {
        // if the list is empty
        if (flats->head == NULL) {
            flats->head = nodeToBeAdded;
            flats->tail = nodeToBeAdded;
            nodeToBeAdded->nextFlat = NULL;
            nodeToBeAdded->previousFlat = NULL;
        } else {
            (flats->head)->previousFlat = nodeToBeAdded;
            nodeToBeAdded->previousFlat = NULL;
            nodeToBeAdded->nextFlat = flats->head;
            flats->head = nodeToBeAdded;
        }
    } else {
        // to find the index which we want to add new node
        int counter = 0;
        FlatNode *temp = flats->head;
        while (counter != index - 1) {
            temp = temp->nextFlat;
            counter++;
        }
        FlatNode *tempNext = temp->nextFlat;

        nodeToBeAdded->previousFlat = temp;
        nodeToBeAdded->nextFlat = tempNext;
        temp->nextFlat = nodeToBeAdded;
        if (tempNext != NULL)
            tempNext->previousFlat = nodeToBeAdded;

        // if we added as the tail of the list
        if (nodeToBeAdded->nextFlat == NULL) {
            flats->tail = nodeToBeAdded;
        }
    }

}
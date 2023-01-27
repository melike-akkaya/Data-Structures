#ifndef ASS2_FLATLINKEDLIST_H
#define ASS2_FLATLINKEDLIST_H

#include "Flat.h"

struct FlatNode {
    FlatNode* nextFlat;
    FlatNode* previousFlat;

    Flat data;
};

// it is a doubly linked list
class FlatLinkedList {
public:
    FlatNode* head;
    FlatNode* tail;

    FlatLinkedList();

    static void add (FlatLinkedList* flats, int index, Flat newFlat);
};


#endif //ASS2_FLATLINKEDLIST_H
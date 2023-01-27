#ifndef ASS2_APARTMENT_H
#define ASS2_APARTMENT_H

#include <string>
#include "FlatLinkedList.h"

using namespace std;

class Apartment {
public:
    Apartment();
    Apartment(string name, int maxBandWidth);

    bool operator != (Apartment a);
    bool operator == (Apartment a);

    //getter
    string getName();
    FlatLinkedList * getFlats (); //define it as a pointer in order to make changes
    int getMaxBandWidth();
    int getUsedBandWidth();

    //setter
    void setMaxBandWidth(int m);

    void increaseBandWidth (int b);
    void decreaseBandWidth (int b);


private:
    string name;
    int maxBandWidth;
    FlatLinkedList flats;
    int usedBandWidth;
};


#endif //ASS2_APARTMENT_H
//
// In this file, I aim to produce objects that will carry the data of the nodes of my apartment list.
//

#include "Apartment.h"

Apartment::Apartment(string name, int maxBandWidth) {
    this -> name = name;
    this -> maxBandWidth = maxBandWidth;
    this -> usedBandWidth = 0;
}

Apartment::Apartment() {}

bool Apartment::operator != (Apartment a) {
    return (this -> name != a.name);
}

bool Apartment::operator == (Apartment a) {
    return (this -> name == a.name);
}


string Apartment::getName() {
    return this->name;
}

FlatLinkedList * Apartment::getFlats() {
    FlatLinkedList* f = &this->flats;
    return f;
}

int Apartment::getUsedBandWidth() {
    return this->usedBandWidth;
}

int Apartment::getMaxBandWidth() {
    return this->maxBandWidth;
}

void Apartment::increaseBandWidth(int b) {
    this->usedBandWidth += b;
}

void Apartment::decreaseBandWidth(int b) {
    this->usedBandWidth -= b;
}

void Apartment::setMaxBandWidth(int m) {
    this->maxBandWidth = m;
}
//
// In this file, I aim to produce objects that will carry the data of the nodes of my flat list.
//

#include "Flat.h"

Flat::Flat() {}

Flat::Flat(int id, int initialBandwitdh, int isEmpty) {
    this -> id = id;
    this -> initialBandwidth = initialBandwitdh;
    this -> isEmpty = isEmpty;
}

bool Flat::operator!=(Flat f) {
    return (this -> id != f.id);
}

int Flat::getID() {
    return this->id;
}

int Flat::getInitialBandWidth() {
    return this->initialBandwidth;
}

void Flat::setInitialBandWidth(int initialBandWidth) {
    this->initialBandwidth = initialBandWidth;
}

void Flat::setIsEmpty(int isEmpty) {
    this->isEmpty = isEmpty;
}
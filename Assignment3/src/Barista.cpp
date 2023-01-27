// in this class, properties of Barista objects are determined with the help of a constructor

#include "Barista.h"

Barista::Barista(int ID) {
    this->isAvailable = true;
    this->baristaID = ID;
    this->totalWorkingTime = 0;
    this->order = 0;
}

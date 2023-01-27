//
// I opened this class because I don't want my main class to be too full. I am doing operations in this class.
//

#include "Operations.h"

void Operations::addApartment(Apartment mustAdd, ApartmentLinkedList *apartments, string position) {
    if (position == "head") {
        ApartmentLinkedList::addHead(apartments, mustAdd);
    }
    else {
        vector<string> positionList = Utility::split(position, '_');
        ApartmentNode *apartmentTemp = apartments->head;
        if (positionList.at(0) == "after") {
            while (apartmentTemp->data.getName() != positionList.at(1)) {
                apartmentTemp = apartmentTemp->nextApartment;
            }
            ApartmentLinkedList::add(apartments, (apartmentTemp->data), mustAdd);
        }
        else {
            if (positionList.at(1) == apartments->head->data.getName()) {
                ApartmentLinkedList::addHead(apartments, mustAdd);
            }
            else {
                while ((apartmentTemp->nextApartment)->data.getName() != positionList.at(1)) {
                    apartmentTemp = apartmentTemp->nextApartment;
                }
                ApartmentLinkedList::add(apartments, (apartmentTemp->data), mustAdd);
            }
        }
    }
}

bool Operations::addFlat(ApartmentNode* tempApartment, vector<string> command) {
    // 1 = apartment, 2 = index, 3 = band with, 4 = id
    if (tempApartment != NULL) {
        while (tempApartment->data.getName() != command.at(1)) {
            tempApartment = tempApartment->nextApartment;

            if (tempApartment == NULL)
                return false;
        }

        int initialBandWith = Utility::toInt(command.at(3));
        int emptyBandWith = tempApartment->data.getMaxBandWidth() - tempApartment->data.getUsedBandWidth();

        int isEmpty = 1;

        if (initialBandWith > emptyBandWith) {
            initialBandWith = emptyBandWith;
        }
        if (initialBandWith == 0) {
            isEmpty = 0;
        }

        Flat newFlat = *new Flat(Utility::toInt(command.at(4)), initialBandWith, isEmpty);
        FlatLinkedList::add((tempApartment->data).getFlats(), Utility::toInt(command.at(2)), newFlat);

        tempApartment->data.increaseBandWidth(initialBandWith);

        return true;
    }
    else {
        return false;
    }
}

ApartmentLinkedList* Operations::removeApartment(ApartmentLinkedList *apartments, string name, fstream &outputFile) {
    ApartmentNode* apartmentTemp = apartments->head;
    if (apartmentTemp != NULL) {
        while (apartmentTemp->data.getName() != name) {
            apartmentTemp = apartmentTemp->nextApartment;

            if (apartmentTemp == NULL)
                break;
        }

        if (apartmentTemp != NULL)
            ApartmentLinkedList::remove(apartments, (apartmentTemp->data));
        else
            outputFile << "There is no such apartment";
    }

    return apartments;
}

void Operations::makeFlatEmpty(ApartmentLinkedList *apartments, vector<string> command, fstream &outputFile) {
    // 1 = apartment name, 2 = flat id

    ApartmentNode* apartmentTemp = apartments->head;

    bool ifContinue = true;

    if (apartmentTemp != NULL) {
        while (apartmentTemp->data.getName() != command.at(1)) {
            apartmentTemp = apartmentTemp->nextApartment;
            if (apartmentTemp == NULL){
                ifContinue = false;
                break;
            }
        }

        if (ifContinue) {
            FlatNode* flatTemp = apartmentTemp->data.getFlats()->head;

            if (flatTemp == NULL)
                ifContinue = false;
            else {
                while (flatTemp->data.getID() != Utility::toInt(command.at(2))) {
                    flatTemp = flatTemp->nextFlat;
                    if (flatTemp == NULL) {
                        ifContinue = false;
                        break;
                    }
                }

                if (ifContinue) {
                    apartmentTemp->data.decreaseBandWidth(flatTemp->data.getInitialBandWidth());

                    flatTemp->data.setInitialBandWidth(0);
                    flatTemp->data.setIsEmpty(1);
                }
            }
        }
    }
    else {
        ifContinue = false;
    }

    if (!ifContinue) {
        outputFile << "Such flat doesn't exists";
    }
}

int Operations::findSumOfMaxBandwidth(ApartmentLinkedList *apartments) {
    ApartmentNode* tempNode = apartments->head;

    int total = 0;
    if (tempNode != NULL) {
        while(tempNode->nextApartment != apartments->head) {
            total += tempNode->data.getMaxBandWidth();
            tempNode = tempNode->nextApartment;
        }
        total += tempNode->data.getMaxBandWidth();
    }

    return total;
}

ApartmentLinkedList* Operations::mergeApartments(ApartmentLinkedList *apartments, vector<string> names, fstream &outputFile) {
    // 1 = apartment name 1 (the addition will be made to the end of the flat list of this apartment)
    // 2 = apartment name 2

    ApartmentNode* firstApartment = apartments->head;
    if (firstApartment != NULL) {
        while (firstApartment->data.getName() != names.at(1)) {
            firstApartment = firstApartment->nextApartment;
            if (firstApartment == NULL)
                break;
        }
        ApartmentNode* secondApartment = apartments->head;
        while (secondApartment->data.getName() != names.at(2)) {
            secondApartment = secondApartment->nextApartment;
            if (secondApartment == NULL)
                break;
        }

        // if there are no first apartments flats but there are second apartments flats
        if (firstApartment->data.getFlats()->head == NULL && secondApartment->data.getFlats()->head != NULL) {
            firstApartment -> data.getFlats()->head = secondApartment->data.getFlats()->head;
            firstApartment->data.getFlats()->tail = secondApartment->data.getFlats()->tail;
        }

        // if there are both first apartments flats and second apartments flats
        if (firstApartment->data.getFlats()->head != NULL && secondApartment->data.getFlats()->head != NULL) {
            FlatNode* firstApartmentsTail = firstApartment->data.getFlats()->tail;
            FlatNode* secondApartmentsHead = secondApartment->data.getFlats()->head;
            FlatNode* secondApartmentsTail = secondApartment->data.getFlats()->tail;

            firstApartmentsTail->nextFlat = secondApartmentsHead;
            secondApartmentsHead->previousFlat  = firstApartmentsTail;

            firstApartment->data.getFlats()->tail = secondApartmentsTail;
            firstApartment->data.getFlats()->tail->nextFlat = NULL;
        }

        firstApartment->data.setMaxBandWidth(firstApartment->data.getMaxBandWidth() + secondApartment->data.getMaxBandWidth());

        ApartmentLinkedList::remove(apartments, (secondApartment->data));
    }
    else {
        outputFile << "ERROR: cannot merge"<<endl;
    }

    return apartments;

}

void Operations::relocate(ApartmentLinkedList* apartments, vector<string> temp) {
    // to find process apartment
    ApartmentNode *processApartment = apartments->head;
    while (processApartment->data.getName() != temp.at(1)) {
        processApartment = processApartment->nextApartment;
    }
    //to find process flat
    FlatNode *processFlat = processApartment->data.getFlats()->head;
    while (processFlat->data.getID() != Utility::toInt(temp[2])) {
        processFlat = processFlat->nextFlat;
    }

    // to create a list which contains the id of the flats which will be relocated
    // fist I need to get rid of the [ and ]
    temp.at(3).erase(0, 1);
    temp.at(3).erase(temp[3].length() - 1, 1);
    vector<string> flatsToRelocateIDs = Utility::split(temp.at(3), ',');

    for (int index = flatsToRelocateIDs.size() - 1 ; index >= 0; index--) {
        int ID = Utility::toInt(flatsToRelocateIDs.at(index));
        ApartmentNode* tempApartment = apartments->head;
        bool ifBreak = false;
        while ((tempApartment->nextApartment != apartments->head) or (tempApartment == apartments->tail)) {
            FlatNode* tempFlat = tempApartment->data.getFlats()->head;
            while (tempFlat != NULL) {
                if (tempFlat->data.getID() == ID) {
                    // to seperate tempFlat from its apartment
                    // firstly control if tempFlat is head or tail
                    if (tempApartment->data.getFlats()->tail == tempFlat)
                        tempApartment->data.getFlats()->tail = tempFlat->previousFlat;
                    if (tempApartment->data.getFlats()->head == tempFlat)
                        tempApartment->data.getFlats()->head = tempFlat->nextFlat;

                    if (tempFlat->nextFlat != NULL)
                        (tempFlat->nextFlat)->previousFlat = tempFlat->previousFlat;
                    if (tempFlat->previousFlat != NULL)
                        (tempFlat->previousFlat)->nextFlat = tempFlat->nextFlat;

                    // to make a connection
                    tempFlat->previousFlat = processFlat->previousFlat;
                    processFlat->previousFlat = tempFlat;
                    tempFlat->nextFlat = processFlat;

                    // to control if we will add a flat as a head
                    if (processFlat == processApartment->data.getFlats()->head) {
                        processApartment->data.getFlats()->head = tempFlat;
                    }

                    // to decrease used band width in order to use that space when we want to add new flat
                    tempApartment->data.decreaseBandWidth(tempFlat->data.getInitialBandWidth());

                    // to change max band width values
                    tempApartment->data.setMaxBandWidth(tempApartment->data.getMaxBandWidth() - tempFlat->data.getInitialBandWidth());
                    processApartment->data.setMaxBandWidth(processApartment->data.getMaxBandWidth() + tempFlat->data.getInitialBandWidth());

                    ifBreak = true;
                    break;
                }
                else {
                    tempFlat = tempFlat->nextFlat;
                }
            }
            if (ifBreak) {
                processFlat = tempFlat;
                break;
            }
            else {
                tempApartment = tempApartment->nextApartment;
            }
        }
    }
}

#include "ApartmentLinkedList.h"
#include "FlatLinkedList.h"
#include "Utility.h"
#include "Operations.h"

int main(int argc, char** argv) {
    ApartmentLinkedList *apartments = new ApartmentLinkedList();

    // to create output file
    fstream outputFile;
    outputFile.open(argv[2], ios::out);

    // to read file
    ifstream file(argv[1]);
    string line;

    while (getline(file, line)) {
        if (!line.empty() && line[line.size() - 1] == '\r')
            line.erase(line.size() - 1);

        vector<string> temp = (Utility::split(line, '\t'));

        if (temp.at(0) == "add_apartment") {
            // 1 = name, 2 = position, 3 = bandWith

            // every member of temp is a string. to make band with an integer:
            stringstream stringToInteger;
            int bandWith = Utility::toInt(temp.at(3));

            Apartment mustAdd = *new Apartment(temp.at(1), bandWith);

            Operations::addApartment(mustAdd, apartments, temp.at(2));
        }
        else if (temp.at(0) == "add_flat") {
            // to find out which apartment the flat belongs to
            ApartmentNode *tempApartment = apartments->head;

            bool flatExists = Operations::addFlat(tempApartment, temp);

            if (!flatExists)
                outputFile << "Such flat cannot be added. " <<endl;
        }
        else if (temp.at(0) == "remove_apartment") {
            // 1 = name
            apartments = Operations::removeApartment(apartments, temp.at(1), outputFile);
        }
        else if (temp.at(0) == "make_flat_empty") {
            Operations::makeFlatEmpty(apartments, temp,outputFile);
        }
        else if (temp.at(0) == "find_sum_of_max_bandwidths") {
            int total = Operations::findSumOfMaxBandwidth(apartments);
            outputFile << "sum of bandwidth: " << total<<endl<<endl;
        }
        else if (temp.at(0) == "list_apartments") {
            ApartmentNode* tempApartment = apartments->head;

            if (tempApartment != NULL) {
                while (tempApartment->nextApartment != apartments->head) {
                    outputFile <<tempApartment->data.getName()<<"("<<tempApartment->data.getMaxBandWidth()<<")\t";

                    FlatNode* tempFlat = tempApartment->data.getFlats()->head;
                    while(tempFlat!= NULL) {
                        outputFile <<"Flat"<<tempFlat->data.getID()<<"("<<tempFlat->data.getInitialBandWidth()<<")\t";
                        tempFlat = tempFlat->nextFlat;
                    }
                    outputFile <<endl;
                    tempApartment = tempApartment->nextApartment;
                }
                outputFile<<tempApartment->data.getName()<<"("<<tempApartment->data.getMaxBandWidth()<<")\t";

                FlatNode* tempFlat = tempApartment->data.getFlats()->head;
                while(tempFlat!= NULL) {
                    outputFile <<"Flat"<<tempFlat->data.getID()<<"("<<tempFlat->data.getInitialBandWidth()<<")\t";
                    tempFlat = tempFlat->nextFlat;
                }
                outputFile <<endl;
            }

            else {
                outputFile << "There is no apartment in the street yet." << endl;
            }

            outputFile<<endl;
        }
        else if (temp.at(0) == "merge_two_apartments") {
            apartments = Operations::mergeApartments(apartments, temp, outputFile);
        }
        else if (temp.at(0) == "relocate_flats_to_same_apartment") {
            Operations::relocate(apartments,temp);
        }
    }

    outputFile.close();
    file.close();

    return 0;
}
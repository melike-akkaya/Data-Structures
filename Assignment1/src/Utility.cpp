//
// In this class, basically methods were written to read the input files and create a matrix.
//

#include "Utility.h"

// In this method, the lines were seperated while reading the files according to the spaces.
// The returned lists form the rows in our matrix structure.
int *Utility::split(string str, int size, char separator) {
    // the list that will hold the words we have separated
    int* list = new int[size];

    string temp;

    // to add list
    int index = 0;

    for(char i : str){
        if(i != separator){
            temp += i;
        }
        else{
            stringstream stringToInteger;

            int tempInteger;
            //stringstream takes the string
            stringToInteger << temp;
            //stringstream gives the integer
            stringToInteger >> tempInteger;

            list[index] = tempInteger;
            if (index < size - 2) {
                index++;
            }
            temp = "";
        }
    }

    // to add last word
    int tempInteger;
    stringstream stringToInteger;

    stringToInteger << temp;
    stringToInteger >> tempInteger;

    list[size - 1] = tempInteger;

    return list;
}


int **Utility::readFile(string fileName, int row, int column) {
    ifstream file (fileName);

    string line;

    int **matrix = new int*[row];

    int index = 0;
    while(getline(file, line)) {
        matrix[index] = split(line, column, ' ');
        index++;
    }

    file.close();

    return matrix;
}
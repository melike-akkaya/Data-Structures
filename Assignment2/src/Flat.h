#ifndef ASS2_FLAT_H
#define ASS2_FLAT_H

#include <string>

class Flat {
public:
    Flat();
    Flat(int id, int initialBandwitdh, int isEmpty);

    bool operator != (Flat f);

    //getter
    int getID();
    int getInitialBandWidth();

    //setter
    void setInitialBandWidth(int initialBandWidth);
    void setIsEmpty (int isEmpty);

private:
    int id;
    int initialBandwidth;
    int isEmpty;
};


#endif //ASS2_FLAT_H
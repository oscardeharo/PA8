#ifndef BOMB_H
#define BOMB_H
#include "Cell.h"

class Bomb: public Cell{
    bool isDisplayed;

public:
    Bomb();
    Bomb(int, int );
    void onClick();

};


#endif
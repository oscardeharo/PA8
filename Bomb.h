#ifndef BOMB_H
#define BOMB_H
#include "Cell.h"

class Bomb: public Cell{

public:
    Bomb();
    Bomb(string, int, int,sf::Font&,int);
    void reveal();

};


#endif
#ifndef BOMB_H
#define BOMB_H
#include "Cell.h"

class Bomb: public Cell{
    bool isDisplayed;

public:
    Bomb();
    Bomb(string, int, int,sf::Font,int);
    void onClick();
    virtual void print() const;

};


#endif
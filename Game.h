#ifndef SOURCE_H
#define SOURCE_H
#include"Bomb.h"
#include"Number.h"
#include "Game.h"
#include "Cell.h"

// int BOMBNUMBER =10;
// int CELLSIZE = 10;
// int GRIDSIZE = 10;
// int WINX = 400;
// int WINY = 400;

class Game{
private:
    Cell cells[10][10];
    Bomb bombs[10];

    int getRandomNumber(int,int);    
    void setup();
public:
    Game();
    const static int CELLSIZE = 10;
    void print() const;

};

#endif
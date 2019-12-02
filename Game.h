#ifndef SOURCE_H
#define SOURCE_H
#include"Bomb.h"
#include"Number.h"
#include "Game.h"
#include "Cell.h"


const int BOMBNUMBER =10;
const int GRIDSIZE = 10;
const int CELLSIZE = 10;
// int WINX = 400;
// int WINY = 400;

class Game{
private:
    Cell *cells[GRIDSIZE][GRIDSIZE];
    Bomb *bombs[BOMBNUMBER];
    int minesLeft;

    int getRandomNumber(int,int);   
    void checkAdjMines(Cell); 
    void setup();
    bool isValid(int,int);
public:
    Game();
    void print() const;

};

#endif
#ifndef SOURCE_H
#define SOURCE_H
#include"Bomb.h"
#include"Number.h"
#include "Game.h"
#include "Cell.h"
#include <SFML/Graphics.hpp>





class Game{
private:
    sf::RenderWindow window;
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
    void start();
    void drawAll();
    void displayAll();

};

#endif
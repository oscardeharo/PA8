#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>
using namespace std;

const int BOMBNUMBER =10;
const int GRIDSIZE = 10;
const int CELLSIZE = 80;
const int WINX = 1500;
const int WINY = 1500;
const int WINXOFFSET = 500;
const int WINYOFFSET = 500;

class Cell{

private:
    int x, y,xInd,yInd;
    bool Flagged;
    bool isActive;
    bool revealed;
    int adjMines;
    string type;
    sf::RectangleShape body;
    sf::Text text;
    bool isValid(int,int);
    //static sf::Font arial;
    

public:
    //bool isRevealed;
    void setType(string);
    void drawB(sf::RenderWindow& window);
    void drawT(sf::RenderWindow& window);
  
    sf::RectangleShape getBody();
    sf::Text getText();
    string getType();
    int getX() const;
    int getY() const;
    int getXInd() const;
    int getYInd() const;
    Cell();
    Cell(string, int, int,sf::Font&,int);
    virtual void onClick();
    void onRightClick();
    virtual void print() const;
    void draw(sf::RenderWindow&);
    void setBodyColor(const sf::Color&);
    void setTextColor(sf::Color&);
    void setTextPosition(int, int);
    void setAdjMines(int);
    void setUpAdjMines(Cell * cells[][GRIDSIZE]);
    void update(int,int);
    bool isHover(int,int);
    void setText(string);
    void flag();
    void unflag();
    string getString();
    int getAdjMines();
    virtual void reveal();
    void revealRecursive(Cell * cells[][GRIDSIZE],Cell* cell);
    void setReveal(bool);
    bool isRevealed();
    bool isFlagged();

};


#endif
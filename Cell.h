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
    bool isFlagged;
    bool isActive;
    int adjMines;
    string type;
    sf::RectangleShape body;
    sf::Text text;
    bool isValid(int,int);
    //static sf::Font arial;
    

public:
    void setType(string);
    void drawB(sf::RenderWindow& window);
    void drawT(sf::RenderWindow& window);
    void display(sf::RenderWindow& window);
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
    void setBodyColor(sf::Color&);
    void setTextColor(sf::Color&);
    void setTextPosition(int, int);
    void setAdjMines(int);
    void setUpAdjMines(Cell * cells[][GRIDSIZE]);

};


#endif
#ifndef CELL_H
#define CELL_H

#include <SFML/Graphics.hpp>
#include<iostream>
using namespace std;

class Cell{

private:
    int x, y;
    bool isFlagged;
    bool isActive;
    int adjMines;
    string type;
    bool isValid(int,int);
    sf::RectangleShape body;
    sf::Text text;
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
    Cell();
    Cell(int, int);
    virtual void onClick();
    void onRightClick();
    virtual void print() const;
    void setAdjMines(int);

};


#endif
#ifndef CELL_H
#define CELL_H


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

public:
    void setType(string);
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
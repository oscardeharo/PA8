#ifndef CELL_H
#define CELL_H


#include<iostream>
using namespace std;

class Cell{

private:
    int x, y;
    bool isFlagged;
    bool isActive;

public:
    int getX() const;
    int getY() const;
    Cell();
    Cell(int, int);
    virtual void onClick();
    void print() const;
};

#endif
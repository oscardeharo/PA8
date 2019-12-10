#include "Number.h"

/****************************************************
 * Overloaded constructor                           *
 ***************************************************/
Number::Number(string s,int X, int Y, sf::Font &font,int size):Cell(s,X,Y,font,size){
    setType("number");
}

/****************************************************
 * Reveals number cell by changing color to green   *
 ***************************************************/
void Number::reveal(){
    Cell::reveal();
    setBodyColor(sf::Color(220,220,220));
    setReveal(true);
    if(getAdjMines()>0){
        setText(to_string(getAdjMines()));
    }
}
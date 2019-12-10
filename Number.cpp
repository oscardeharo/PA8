#include "Number.h"

Number::Number(string s,int X, int Y, sf::Font &font,int size):Cell(s,X,Y,font,size){
    setType("number");
}

void Number::onClick(){
    
}

void Number::reveal(){
    Cell::reveal();
    setBodyColor(sf::Color(220,220,220));
    setReveal(true);
    if(getAdjMines()>0){
        setText(to_string(getAdjMines()));
    }
}
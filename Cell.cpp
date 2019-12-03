#include "Cell.h"
#include "Game.h"
Cell::Cell(){
    x=0;
    y=0;
    adjMines=0;
    type="";
    isActive = false;
    isFlagged = false;
    sf::RectangleShape body(sf::Vector2f(0,0));
}

Cell::Cell(int X, int Y){
    x = X;
    y = Y;
    adjMines=0;
    type="";
    isActive = false;
    isFlagged = false;
    //Body
    sf::RectangleShape body(sf::Vector2f(CELLSIZE,CELLSIZE));
    body.setFillColor(sf::Color::White);
    body.setOutlineThickness(10);
    body.setOutlineColor(sf::Color(155,155,155));
    body.setPosition(X*CELLSIZE,Y*CELLSIZE);

    
}

void Cell::print() const{
    cout<<"PosX "<<getX()<<"\t"<<"PosY "<<getY()<<endl;
}


void Cell::onRightClick(){
    //Flag cell
    //TODO: figure out how to decrease minesLeft when right clic on a cell
    //minesLeft--;


}

void Cell::onClick(){
    
}

int Cell::getX() const{
    return x;
}

int Cell::getY() const{
    return y;
}

void Cell::setAdjMines(int i){
    adjMines = i;

}

void Cell::setType(string s){
    type =s;
}

string Cell::getType(){
    return type;
}

void Cell::draw(sf::RenderWindow window){
    window.draw(body);
} 
#include <SFML/Graphics.hpp>
#include "Bomb.h"

/****************************************************
 * Default constructor                              *
 ***************************************************/
Bomb::Bomb(){
    Cell();
    setType("bomb");
}

/****************************************************
 * Overloaded constructor                           *
 ***************************************************/
Bomb::Bomb(string s,int X, int Y, sf::Font& font, int size):Cell(s,X,Y,font,size){
    setType("bomb");
    //setTextColor(sf::Color::Red);

}

/****************************************************
 * Changes color of bomb to red                     *
 ***************************************************/
void Bomb::reveal(){
    Cell::reveal();
    setBodyColor(sf::Color::Red);
}
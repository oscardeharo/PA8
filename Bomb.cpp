#include "Bomb.h"
Bomb::Bomb(){
    Cell();
    setType("bomb");
    isDisplayed=false;
}

Bomb::Bomb(string s,int X, int Y, sf::Font font, int size):Cell(s,X,Y,font,size){
    setType("bomb");
    isDisplayed=false;
}
void Bomb::onClick(){

}

void Bomb::print() const{
    cout<<"PosX "<<getX()<<"\t"<<"PosY "<<getY()<<" Bomb"<<endl;
}
#include "Bomb.h"
Bomb::Bomb(){
    Cell();
    setType("bomb");
    isDisplayed=false;
}

Bomb::Bomb(int X, int Y):Cell(X,Y){
    setType("bomb");
    isDisplayed=false;
}
void Bomb::onClick(){

}

void Bomb::print() const{
    cout<<"PosX "<<getX()<<"\t"<<"PosY "<<getY()<<" Bomb"<<endl;
}
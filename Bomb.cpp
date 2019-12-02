#include "Bomb.h"
Bomb::Bomb(){
    Cell();
    isDisplayed=false;
}

Bomb::Bomb(int X, int Y):Cell(X,Y){
    isDisplayed=false;
}
void Bomb::onClick(){

}


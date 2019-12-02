#include "Cell.h"
Cell::Cell(){
    x=0;
    y=0;
    isActive = false;
    isFlagged = false;
}

Cell::Cell(int X, int Y){
    x = X;
    y = Y;
    isActive = false;
    isFlagged = false;
}

void Cell::print() const{
    cout<<"PosX "<<getX()<<"\t"<<"PosY "<<getY()<<endl;
}
void Cell::onClick(){
    
}

int Cell::getX() const{
    return x;
}

int Cell::getY() const{
    return y;
}
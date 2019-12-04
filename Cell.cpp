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
    sf::Text text;
    
}

Cell::Cell(string s,int X, int Y, sf::Font &font, int size){
    x = X;
    y = Y;
    adjMines=0;
    type="";
    isActive = false;
    isFlagged = false;

    //Text
    text.setString(s);
    text.setFont(font);
    text.setCharacterSize(20);
    text.setPosition(X,Y);
    text.setFillColor(sf::Color::Red);

    //Body
    body.setSize(sf::Vector2f(size,size));
    body.setFillColor(sf::Color::White);
    body.setOutlineThickness(10);
    body.setOutlineColor(sf::Color(155,155,155));
    body.setPosition(X,Y);


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

void Cell::drawB(sf::RenderWindow& window){
    window.draw(body);
    
    window.draw(text);
    //cout<<"here\n";
} 
void Cell::drawT(sf::RenderWindow& window){
    
    window.draw(text);
    string s = text.getString();
        cout<<s<<endl;
        exit(0);
    
    //window.draw(text);
    //cout<<"here\n";
}

// void Cell::display(sf::RenderWindow& window){
//     window.display(body);
// } 

sf::RectangleShape Cell::getBody(){
    return body;
}
sf::Text Cell::getText(){
    return text;
}

void Cell::draw(sf::RenderWindow& window){
    window.draw(body);
    window.draw(text);
}
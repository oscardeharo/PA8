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

Cell::Cell(int X, int Y){
    x = X;
    y = Y;
    adjMines=0;
    type="";
    isActive = false;
    isFlagged = false;


    //Text
    text.setString("A");
    sf::Font arial;
    arial.loadFromFile("30431287674.ttf");
    text.setFont(arial);
    text.setPosition(X*CELLSIZE,Y*CELLSIZE);
    text.setFillColor(sf::Color::Red);

    //Body
    body.setSize(sf::Vector2f(CELLSIZE,CELLSIZE));
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
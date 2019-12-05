#include "Cell.h"


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
    xInd = X/size;
    yInd = Y/size;
    adjMines=0;
    type="";
    isActive = false;
    isFlagged = false;

    //Text
    text.setString(s);
    text.setFont(font);
    text.setCharacterSize(30);
    text.setPosition(X,Y);
    text.setFillColor(sf::Color::Black);

    //Body
    body.setSize(sf::Vector2f(size,size));
    body.setFillColor(sf::Color::White);
    body.setOutlineThickness(2);
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

int Cell::getXInd() const{
    return xInd;
}

int Cell::getYInd() const{
    return yInd;
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

void Cell::setTextColor(sf::Color& c){
    text.setFillColor(c);
}

void Cell::setTextPosition(int x, int y){
    text.setPosition(x,y);
}

void Cell::setBodyColor(sf::Color& color){
    body.setFillColor(color);
}

void Cell::setUpAdjMines(Cell *cells[][GRIDSIZE]){
    //a++;
    
    int total = 0;
    int x=getXInd();
    int y=getYInd();

    //cout<<x<<endl;
    //cout<<y<<endl;

    //DownLeft
    if(isValid(x-1,y+1)){
        cout<<"down-left is valid\n";
        //if it is a bomb
        if(cells[x-1][y+1]->getType().compare("bomb")==0){
            cout<<"up-left"<<endl;
            total++;
        }
    } 
    
    //Down
    if(isValid(x,y+1)){
        cout<<"down is valid\n";
        //if it is a bomb
        if(cells[x][y+1]->getType().compare("bomb")==0){
            
            cout<<"Down"<<endl;
            total++;
        }
    }
    
    //DownRight
    if(isValid(x+1,y+1)){
        cout<<"down-right is valid\n";
        //if it is a bomb
        if(cells[x+1][y+1]->getType().compare("bomb")==0){
            cout<<"Down-right"<<endl;
            total++;
        }
    } 

    

    //Left
    if(isValid(x-1,y)){
        cout<<"left is valid\n";
        if(cells[x-1][y]->getType().compare("bomb")==0){
            cout<<"left"<<endl;
            total++;
        }
    } 

    
    
    //Right
    if(isValid(x+1,y)){
        cout<<"right is valid\n";
        //if it is a bomb
        if(cells[x+1][y]->getType().compare("bomb")==0){
            cout<<"right"<<endl;
            total++;
        }
    } 
    
    //UpperLeft
    if(isValid(x-1,y-1)){
        cout<<"Up-left is valid\n";
        //if it is a bomb
        if(cells[x-1][y-1]->getType().compare("bomb")==0){
            cout<<"up-left"<<endl;
            total++;
        }
    } 

   

    //Up
    if(isValid(x,y-1)){
        cout<<"Up is valid\n";
        //if it is a bomb
        if(cells[x][y-1]->getType().compare("bomb")==0){
            cout<<"up"<<endl;
            total++;
        }
    } 

     
    //UpperRight
    if(isValid(x+1,y-1)){
        cout<<"Up-right is valid\n";
        //if it is a bomb
        if(cells[x+1][y-1]->getType().compare("bomb")==0){
            cout<<"up-right"<<endl;
            total++;
        }
    } 

    //Set number of adjacent mines
    setAdjMines(total);
    text.setString(to_string(total));

    cout<<total<<endl;
    
    
  
}

bool Cell::isValid(int x,int y){
    bool xIsValid = (x>=0 && x<GRIDSIZE);
    bool yIsValid = (y>=0 && y<GRIDSIZE);

    if(xIsValid)
        cout<<"x is valid\n";
    if(yIsValid)
        cout<<"y is valid\n";
    if ( xIsValid && yIsValid){
        return true;
    }
    else{
       return false;
    }
}



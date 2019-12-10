#include "Cell.h"

/****************************************************
 * Default constructor                              *
 ***************************************************/
Cell::Cell(){
    x=0;
    y=0;
    adjMines=0;
    type="";
    revealed = false;
    isActive = false;
    Flagged = false;
    sf::RectangleShape body(sf::Vector2f(0,0));
    sf::Text text;
    
}

/****************************************************
 * Overloaded constructor                           *
 ***************************************************/
Cell::Cell(string s,int X, int Y, sf::Font &font, int size){
    x = X;
    y = Y;
    xInd = X/size;
    yInd = Y/size;
    adjMines=0;
    type="";
    isActive = false;
    Flagged = false;

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
    body.setOutlineColor(sf::Color(100,100,100));
    body.setPosition(X,Y);


}

/****************************************************
 * Sets text in the cell                            *
 ***************************************************/
void Cell::setText(string s){
    text.setString(s);

}

/****************************************************
 * Gets X coordinate                                *
 ***************************************************/
int Cell::getX() const{
    return x;
}

/****************************************************
 * Gets Y coordinate                                *
 ***************************************************/
int Cell::getY() const{
    return y;
}

/****************************************************
 * Gets X index within grid                         *
 ***************************************************/
int Cell::getXInd() const{
    return xInd;
}

/****************************************************
 * Gets Y index within grid                         *
 ***************************************************/
int Cell::getYInd() const{
    return yInd;
}

/****************************************************
 * Sets total number of surrounding mines           *
 ***************************************************/
void Cell::setAdjMines(int i){
    adjMines = i;

}

/****************************************************
 * Sets type of the cell (bomb or number)           *
 ***************************************************/
void Cell::setType(string s){
    type =s;
}

/****************************************************
 * Gets type of cell (bomb or number                *
 ***************************************************/
string Cell::getType(){
    return type;
}

/****************************************************
 * Draws the cell                                   *
 ***************************************************/
void Cell::draw(sf::RenderWindow& window){
    window.draw(body);
    window.draw(text);
}

/****************************************************
 * Sets color of the text                           *
 ***************************************************/
void Cell::setTextColor(sf::Color& c){
    text.setFillColor(c);
}

/****************************************************
 * Sets pixel coordinate of cell                    *
 ***************************************************/
void Cell::setTextPosition(int x, int y){
    text.setPosition(x,y);
}

/****************************************************
 * Sets body color of cell                          *
 ***************************************************/
void Cell::setBodyColor(const sf::Color& color){
    body.setFillColor(color);
}

/****************************************************
 * Counts surrounding mines and assigns it to       *
 * adjMines                                         *
 ***************************************************/
void Cell::setUpAdjMines(Cell *cells[][GRIDSIZE]){

    //Initialize total 
    int total = 0;

    //Get cell indeces
    int x=getXInd();
    int y=getYInd();

    //DownLeft
    if(isValid(x-1,y+1)){

        if(cells[x-1][y+1]->getType().compare("bomb")==0){
            total++;
        }
    } 
    
    //Down
    if(isValid(x,y+1)){
        if(cells[x][y+1]->getType().compare("bomb")==0){
            total++;
        }
    }
    
    //DownRight
    if(isValid(x+1,y+1)){
        if(cells[x+1][y+1]->getType().compare("bomb")==0){
            total++;
        }
    } 
    
    //Left
    if(isValid(x-1,y)){
        if(cells[x-1][y]->getType().compare("bomb")==0){
            total++;
        }
    } 

    //Right
    if(isValid(x+1,y)){
        if(cells[x+1][y]->getType().compare("bomb")==0){
            total++;
        }
    } 
    
    //UpperLeft
    if(isValid(x-1,y-1)){
        if(cells[x-1][y-1]->getType().compare("bomb")==0){
            total++;
        }
    } 

    //Up
    if(isValid(x,y-1)){
        if(cells[x][y-1]->getType().compare("bomb")==0){
            total++;
        }
    } 

    //UpperRight
    if(isValid(x+1,y-1)){
        if(cells[x+1][y-1]->getType().compare("bomb")==0){
            total++;
        }
    } 

    //Set number of adjacent mines
    setAdjMines(total);
}

/****************************************************
 * Returns true if a given pair of X and Y indeces  *
 * are valid on the grid. Returns false otherwise.  *
 ***************************************************/
bool Cell::isValid(int x,int y){
    bool xIsValid = (x>=0 && x<GRIDSIZE);
    bool yIsValid = (y>=0 && y<GRIDSIZE);

    if ( xIsValid && yIsValid){ 
        return true;
    }
    else {
       return false;
    }
}

/****************************************************
 * Returns true if mouse coordinates are within     *
 * the area of the cell                             *
 ***************************************************/
bool Cell::isHover(int mouseX, int mouseY){
    if (body.getGlobalBounds().contains(mouseX,mouseY)){
        return true;
    }
    return false;
}

/****************************************************
 * Flags a cell and turns it blue                   *
 ***************************************************/
void Cell::flag(){
    //if its already flagged
    setBodyColor(sf::Color::Blue);
    Flagged = true;
}

/****************************************************
 * Unflags a cell and returns to the origianl       *
 * properties                                       *
 ***************************************************/
void Cell::unflag(){
    setBodyColor(sf::Color::White);
    Flagged = false;
}

/****************************************************
 * Gets total number of surrounding mines           *
 ***************************************************/
int Cell::getAdjMines(){
    return adjMines;
}

/****************************************************
 * Recursively reveals cells around a non-bomb cell *
 ***************************************************/
void Cell::revealRecursive(Cell *cells[][GRIDSIZE],Cell* cell){

    //Check if there are mines around
    int x=getXInd();
    int y=getYInd();
    

    //DownLeft
    //Down
    //DownRight
    //Left
    //Right
    //UpperLeft
    //Up  
    //UpperRight

    // if there is at least one valid mine surrounding the cell
    reveal();
    if((isValid(x-1,y+1)&&cells[x-1][y+1]->getType().compare("bomb")==0)||//Downleft
    (isValid(x,y+1)&&cells[x][y+1]->getType().compare("bomb")==0)||//Down
    (isValid(x+1,y+1)&&cells[x+1][y+1]->getType().compare("bomb")==0)||//Downright
    (isValid(x-1,y)&&cells[x-1][y]->getType().compare("bomb")==0)||//Left
    (isValid(x+1,y)&&cells[x+1][y]->getType().compare("bomb")==0)||//Right
    (isValid(x-1,y-1)&&cells[x-1][y-1]->getType().compare("bomb")==0)||//Upper left
    (isValid(x,y-1)&&cells[x][y-1]->getType().compare("bomb")==0)||//Up
    (isValid(x+1,y-1)&&cells[x+1][y-1]->getType().compare("bomb")==0))//upright
    {
        return;
    }
    else{


        //Reveal recursively
        if(isValid(x-1,y+1))//Down left
            cells[x-1][y+1]->revealRecursive(cells,cells[x-1][y+1]);
        if(isValid(x,y+1)) //down
            cells[x][y+1]->revealRecursive(cells,cells[x][y+1]);
        if(isValid(x+1,y+1) )//downright
            cells[x+1][y+1]->revealRecursive(cells,cells[x+1][y+1]);
        if(isValid(x-1,y))//right
            cells[x-1][y]->revealRecursive(cells,cells[x-1][y]);
        if(isValid(x+1,y))
            cells[x+1][y]->reveal();
        if(isValid(x-1,y-1))
            cells[x-1][y-1]->reveal();
        if(isValid(x,y-1))
            cells[x][y-1]->reveal();
        if(isValid(x+1,y-1))
            cells[x+1][y-1]->reveal();

    }


}

/****************************************************
 * Reveals a cell. Overwritten method for Number    *
 * and Bomb classes                                 *
 ***************************************************/
void Cell::reveal(){
    //Overwritten function 
    revealed =true;
return;
}

/****************************************************
 * Sets revealed status according to parameter      *
 ***************************************************/
void Cell::setReveal(bool b){
    revealed = b;
}

/****************************************************
 * Returns revealed value                           *
 ***************************************************/
bool Cell::isRevealed(){
    return revealed;
}

/****************************************************
 * Returns flag status                              *
 ***************************************************/
bool Cell::isFlagged(){
    return Flagged;
}
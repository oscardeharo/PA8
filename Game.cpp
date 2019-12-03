#include"Game.h"
#include <random>
#include <typeinfo>

Game::Game(){
    sf::RenderWindow window(sf::VideoMode(WINX,WINY), "SMFL Tutorial",sf::Style::Close|sf::Style::Resize);    
    window.clear(sf::Color::Black);  //window background color

    setup();
}
void Game::setup(){
    minesLeft = BOMBNUMBER;
    
    //Build Grid
    //int x=0;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            //x++;
            //cout<<i<<"\t"<<j<<endl;
            //Number temp(i,j);
            cells[i][j] = new Number(i,j);
            //cout<<typeid(*cells[i][j]).name()<<endl;

        }
    }
    
    // Randomize Bombs
    srand( time(0) );
    for (int i=0;i<BOMBNUMBER;i++){
        int ranColumn=getRandomNumber(0,GRIDSIZE-1);
        int ranRow=getRandomNumber(0,GRIDSIZE-1);
        //Bomb b(ranRow,ranColumn);
        //b.print();

        cells[ranRow][ranColumn]=new Bomb(ranRow,ranColumn);
        //cout<<typeid(*cells[ranRow][ranColumn]).name()<<endl;
        //cout<<cells[ranRow][ranColumn]->getType()<<endl;
        //cells[ranRow][ranColumn]->print();
    }
    
    //Get number of adyacent mines
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            checkAdjMines(*(cells[i][j]));
        }
    }
    
}

int Game::getRandomNumber(int min, int max){
    //srand( time(NULL) );
    return min + rand() % (( max + 1 ) - min);
}

void Game::print() const{
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            cells[i][j]->print();
        }
    }
}

void Game::checkAdjMines(Cell cell){
    
    int total = 0;
    int x=cell.getX();
    int y=cell.getY();
    
    //UpperLeft
    if(isValid(x-1,y+1)){
        
        //if it is a bomb
        if(cells[x-1][y+1]->getType().compare("bomb")==0){
            total++;
        }
    } 
    //exit(0);

    //Up
    if(isValid(x,y+1)){
        //if it is a bomb
        if(cells[x][y+1]->getType().compare("bomb")==0){
            total++;
        }
    }

    //UpperRight
    if(isValid(x+1,y+1)){
        //if it is a bomb
        if(cells[x+1][y+1]->getType().compare("bomb")==0){
            total++;
        }
    } 

    //Left
    if(isValid(x-1,y)){
        //if it is a bomb
        if(cells[x-1][y]->getType().compare("bomb")==0){
            total++;
        }
    } 

    //Right
    if(isValid(x,y+1)){
        //if it is a bomb
        if(cells[x][y+1]->getType().compare("bomb")==0){
            total++;
        }
    } 

    //LowerRight
    if(isValid(x-1,y-1)){
        //if it is a bomb
        if(cells[x-1][y-1]->getType().compare("bomb")==0){
            total++;
        }
    } 

    //Low
    if(isValid(x,y-1)){
        //if it is a bomb
        if(cells[x][y-1]->getType().compare("bomb")==0){
            total++;
        }
    } 

    //LowerRight
    if(isValid(x+1,y-1)){
        //if it is a bomb
        if(cells[x+1][y-1]->getType().compare("bomb")==0){
            total++;
        }
    } 

    //Set number of adjacent mines
    cells[x][y]->setAdjMines(total);
}

bool Game::isValid(int x,int y){
    if ((x>=0 && x<GRIDSIZE) && (y>=0 && y<GRIDSIZE)){
        return true;
    }
    else{
       return false;
    }
}

void Game::start(){
    while(window.isOpen()){
        sf::Event evnt;
        while(window.pollEvent(evnt)){

            switch (evnt.type){
                case sf::Event::Closed:
                    window.close();
                    break; 
                case sf::Event::Resized:
                    cout<<evnt.size.width<<endl;
                    break; 
                default:
                
                    break;
            }
        }
        
        //window.draw();
        //window.draw(c2);

        window.display();
    }
}
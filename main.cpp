
#include"Number.h"
#include "Bomb.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <typeinfo>


const int BOMBNUMBER =10;
const int GRIDSIZE = 10;
const int CELLSIZE = 80;
const int WINX = 1500;
const int WINY = 1500;

int getRandomNumber(int min, int max){
    //srand( time(NULL) );
    return min + rand() % (( max + 1 ) - min);
}
bool isValid(int x,int y){
    if ((x>=0 && x<GRIDSIZE) && (y>=0 && y<GRIDSIZE)){
        return true;
    }
    else{
       return false;
    }
}

// void checkAdjMines(Cell cell, Cell cells){
    
//     int total = 0;
//     int x=cell.getX()
//     int y=cell.getY();
    
//     //UpperLeft
//     if(isValid(x-1,y+1)){
        
//         //if it is a bomb
//         if(cells[x-1][y+1]->getType().compare("bomb")==0){
//             total++;
//         }
//     } 
//     //exit(0);

//     //Up
//     if(isValid(x,y+1)){
//         //if it is a bomb
//         if(cells[x][y+1]->getType().compare("bomb")==0){
//             total++;
//         }
//     }

//     //UpperRight
//     if(isValid(x+1,y+1)){
//         //if it is a bomb
//         if(cells[x+1][y+1]->getType().compare("bomb")==0){
//             total++;
//         }
//     } 

//     //Left
//     if(isValid(x-1,y)){
//         //if it is a bomb
//         if(cells[x-1][y]->getType().compare("bomb")==0){
//             total++;
//         }
//     } 

//     //Right
//     if(isValid(x,y+1)){
//         //if it is a bomb
//         if(cells[x][y+1]->getType().compare("bomb")==0){
//             total++;
//         }
//     } 

//     //LowerRight
//     if(isValid(x-1,y-1)){
//         //if it is a bomb
//         if(cells[x-1][y-1]->getType().compare("bomb")==0){
//             total++;
//         }
//     } 

//     //Low
//     if(isValid(x,y-1)){
//         //if it is a bomb
//         if(cells[x][y-1]->getType().compare("bomb")==0){
//             total++;
//         }
//     } 

//     //LowerRight
//     if(isValid(x+1,y-1)){
//         //if it is a bomb
//         if(cells[x+1][y-1]->getType().compare("bomb")==0){
//             total++;
//         }
//     } 

//     //Set number of adjacent mines
//     cells[x][y]->setAdjMines(total);
// }

int main(){

    Cell *cells[GRIDSIZE][GRIDSIZE];
    Bomb bombs[BOMBNUMBER];
    int minesLeft = BOMBNUMBER;;

   
    //Font
    sf::Font arial;
    arial.loadFromFile("30431287674.ttf");
    sf::Text text;
    text.setString("a");
    text.setFont(arial);
    text.setPosition(GRIDSIZE,GRIDSIZE);
    text.setFillColor(sf::Color::Red);
    string s="aaaaaaaa";
    Cell c1(s,CELLSIZE+1000,CELLSIZE+1000,arial,CELLSIZE);

    //Build Grid
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            //x++;
            //cout<<i<<"\t"<<j<<endl;
            //Number temp(i,j);
            cells[j][i] = new Number(s,i*CELLSIZE,j*CELLSIZE,arial,CELLSIZE); //cells is [j][i] to keep cells[row][column] convention
            //cout<<typeid(*cells[i][j]).name()<<endl;
            // cout<<"Given pos: ";
            // cout<<i;
            // cout<<" Pos from body :";
            // cout<<cells[i][j]->getBody().getPosition().y<<endl;

        }
    }
    
    // Randomize Bombs
    srand( time(0) );
    for (int i=0;i<BOMBNUMBER;i++){
        int ranColumn=getRandomNumber(0,GRIDSIZE-1);
        int ranRow=getRandomNumber(0,GRIDSIZE-1);

        cells[ranColumn][ranRow]=new Bomb("hola",ranRow*CELLSIZE,ranColumn*CELLSIZE,arial,CELLSIZE);
  
    }
    


    sf::RenderWindow window(sf::VideoMode(WINX,WINY), "SMFL Tutorial",sf::Style::Close|sf::Style::Resize);    


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
        window.clear(sf::Color::Black);  //window background color

        cells[0][0]->draw(window);
        //window.draw(c1.getText());
        //c1.draw(window);
        //window.draw(c1);
        //window.draw(text);
        //window.draw(c2);
        //cout<<"here"<<endl;
        window.display();
    }

    return 0;
}



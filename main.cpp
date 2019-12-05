
#include"Number.h"
#include "Bomb.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <typeinfo>



int getRandomNumber(int min, int max){
    //srand( time(NULL) );
    return min + rand() % (( max + 1 ) - min);
}


int main(){
    
    Cell *cells[GRIDSIZE][GRIDSIZE];    //Create Cell Grid Data Matrix
    Bomb bombs[BOMBNUMBER];             // Create Bombs array
    int minesLeft = BOMBNUMBER;;        //keeps track of found bombs

    //Font for Text
    sf::Font arial;
    arial.loadFromFile("30431287674.ttf");
    
    //Build Grid
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            //Create Cells
            cells[i][j] = new Number("N",i*CELLSIZE,j*CELLSIZE,arial,CELLSIZE); //cells is [j][i] to keep cells[row][column] convention

            //Set offset position of text
            cells[i][j]->setTextPosition(i*CELLSIZE+CELLSIZE/4,j*CELLSIZE+CELLSIZE/4);
            //cout<<cells[j][i]->getType().compare("bomb")<<endl;
        }
    }
    
    // Randomize Bombs
    srand( time(0) );

    sf::Color redColor;
    redColor = sf::Color::Red;
    sf::Color blueColor;
    blueColor = sf::Color::Blue;

    int xx[]={9,5,2,3,4,5,6,4,8,9};
    int yy[]={9,5,3,2,4,8,4,7,1,9};
    
    for (int i=0;i<BOMBNUMBER;i++){
        int x=getRandomNumber(0,GRIDSIZE-1);
        int y=getRandomNumber(0,GRIDSIZE-1);
        //x=xx[i];
        //y=yy[i];
        cells[x][y]=new Bomb("B",x*CELLSIZE,y*CELLSIZE,arial,CELLSIZE);
        cells[x][y]->setTextPosition(x*CELLSIZE+CELLSIZE/4,y*CELLSIZE+CELLSIZE/4);
        cells[x][y]->setBodyColor(redColor);

        cout<<"Bomb- X: "<<cells[x][y]->getXInd();
        cout<<" Y: "<<cells[x][y]->getYInd()<<endl;
        //cout<<cells[ranColumn][ranRow]->getType().compare("bomb")<<endl;

        
    }

    //exit(0);
    //X is row
    //Y is column


    //int xx =1; // row
    //int yy= 1; // column
    //

    // cells[xx][yy]=new Bomb("B",xx*CELLSIZE,yy*CELLSIZE,arial,CELLSIZE);
    // cells[xx][yy]->setBodyColor(blueColor);

    // xx =1;
    // yy= 0;
    // cells[xx][yy]=new Bomb("B",xx*CELLSIZE,yy*CELLSIZE,arial,CELLSIZE);
    // cells[xx][yy]->setBodyColor(blueColor);

    // xx =0;
    // yy= 1;
    // cells[xx][yy]=new Bomb("B",xx*CELLSIZE,yy*CELLSIZE,arial,CELLSIZE);
    // cells[xx][yy]->setBodyColor(blueColor);

    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            cells[i][j]->setUpAdjMines(cells);
            cout<<"X = "<<i<<" Y = "<<j<<endl;
                if (i==7 && j==2){
                    //exit(0);
                }
            //exit(0);
        }
    }

    //Window
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

        for (int i=0;i<10;i++){
            for (int j=0;j<10;j++){
                cells[i][j]->draw(window);
            }
        }
        
        window.display();
    }

    return 0;
}



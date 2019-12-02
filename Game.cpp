#include"Game.h"
#include <random>
Game::Game(){
    setup();
}
void Game::setup(){
    
    //Build Grid
    //int x=0;
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            //x++;
            //cout<<i<<"\t"<<j<<endl;
            cells[i][j] =  Number(i,j);

        }
    }
    
    // Randomize Bombs

    srand( time(0) );
    for (int i=0;i<10;i++){
        cout<<getRandomNumber(0,CELLSIZE-1)<<endl;
        cout<<getRandomNumber(0,CELLSIZE-1)<<endl;
    }
    
    
}

int Game::getRandomNumber(int min, int max){
    //srand( time(NULL) );
    return min + rand() % (( max + 1 ) - min);
}

void Game::print() const{
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            cells[i][j].print();
        }
    }
}
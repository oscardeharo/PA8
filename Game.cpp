#include"Game.h"
#include <random>
#include <typeinfo>

Game::Game(){
    

    setup();
}
void Game::setup(){
    minesLeft = BOMBNUMBER;
    
    //Build Grid
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            //x++;
            //cout<<i<<"\t"<<j<<endl;
            //Number temp(i,j);
            cells[j][i] = new Number(i,j); //cells is [j][i] to keep cells[row][column] convention
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
        //Bomb b(ranRow,ranColumn);
        //b.print();

        cells[ranColumn][ranRow]=new Bomb(ranRow,ranColumn);
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
    //cout<<"here"<<endl;
    sf::RectangleShape c1(sf::Vector2f(CELLSIZE,CELLSIZE));
    c1.setPosition(0*CELLSIZE,0*CELLSIZE);
    c1.setFillColor(sf::Color::White);
    c1.setOutlineThickness(10);
    c1.setOutlineColor(sf::Color(155,155,155));
    //cout<<cells[3][3]->getBody().getPosition().x<<endl;
    //cout<<c1.getPosition().x<<endl;
    //exit(0);
    //Window
    sf::RenderWindow window(sf::VideoMode(WINX,WINY), "SMFL Tutorial",sf::Style::Close|sf::Style::Resize);    
    //Font
    //sf::Font arial;
    //arial.loadFromFile("font/30431287674.ttf");

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
        cells[0][0]->drawB(window);
        //cells[0][0]->drawT(window);
        


        //TODO: figure out why the drawAll doesnt work
        // for (int i=0;i<10;i++){
        //     for (int j=0;j<10;j++){
        //         cells[i][j]->drawB(window);
        //     }
        // }
        // for (int i=0;i<10;i++){
        //     for (int j=0;j<10;j++){
        //         cells[i][j]->drawT(window);
        //     }
        // }
        window.display();
    }
}

void Game::drawAll(){
    
    //cells[4][6]->draw(window);
    // for (int i=0;i<10;i++){
    //     for (int j=0;j<10;j++){
    //         cells[i][j]->draw(window);
    //     }
    // }
}

// void Game::displayAll(){
//     for (int i=0;i<10;i++){
//         for (int j=0;j<10;j++){
//             //cells[i][j]->display(window);
//         }
//     }
// }

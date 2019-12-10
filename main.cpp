
#include"Number.h"
#include "Bomb.h"
#include <SFML/Graphics.hpp>
#include <random>
#include <typeinfo>



int getRandomNumber(int, int);


int main(){
    
    Cell *cells[GRIDSIZE][GRIDSIZE];    //Create Cell Grid Data Matrix
    Bomb *bombs[BOMBNUMBER];             // Create Bombs array
    int minesLeft = BOMBNUMBER;        //keeps track of found bombs
    int flagsPlaced = BOMBNUMBER;
    bool gameOver = false;
    bool isPressed = false;

    //Mouse Position Variables
    int mouseX, mouseY;

    // Initizlize text box
    sf::Font arial;
    arial.loadFromFile("30431287674.ttf");
    sf::Text msg("",arial,100);
    msg.setFillColor(sf::Color::Green);
    msg.setPosition(50,850);

    //Build Grid
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            //Create Cells
            cells[i][j] = new Number("",i*CELLSIZE,j*CELLSIZE,arial,CELLSIZE); //cells is [j][i] to keep cells[row][column] convention

            //Set offset position of text
            cells[i][j]->setTextPosition(i*CELLSIZE+CELLSIZE/4,j*CELLSIZE+CELLSIZE/4);
 
        }
    }
    
    
    // Colors
    sf::Color redColor;
    redColor = sf::Color::Red;
    sf::Color blueColor;
    blueColor = sf::Color::Blue;

    //int xx[]={9,5,2,3,4,5,6,4,8,9};
    //int yy[]={9,5,3,2,4,8,4,7,1,9};
    
    //Create bombs in random positions
    srand( time(0) );
    for (int i=0;i<BOMBNUMBER;i++){

        //Random positions
        int x=getRandomNumber(0,GRIDSIZE-1);
        int y=getRandomNumber(0,GRIDSIZE-1);

        //Instantiate bomb objects
        bombs[i]=new Bomb("b",x*CELLSIZE,y*CELLSIZE,arial,CELLSIZE);
        cells[x][y]=bombs[i];
        cells[x][y]->setTextPosition(x*CELLSIZE+CELLSIZE/4,y*CELLSIZE+CELLSIZE/4);

    }

    //Count bombs around the cells
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            cells[i][j]->setUpAdjMines(cells);
        }
    }

    //Window
    sf::RenderWindow window(sf::VideoMode(WINX,WINY), "SMFL Tutorial",sf::Style::Close);    
    while(window.isOpen()){
        sf::Event evnt;
        while(window.pollEvent(evnt)){
            
            switch (evnt.type){
                
                //Closing the window
                case sf::Event::Closed: 
                    window.close();
                    break;  

                default:
                    break;
            }
        }

        //Set black window background
        window.clear(sf::Color::Black);  
        
        // While not all bomb cells have been flagged
        if(minesLeft>0&&!gameOver){

            //Display how many mines are left

            //Get cursos positions
            mouseX=sf::Mouse::getPosition(window).x;
            mouseY=sf::Mouse::getPosition(window).y;

            //Draw number of mines left
            string str = "Number of flags: " + to_string(flagsPlaced);
            msg.setString(str);
        
            //Draw all buttons
            for (int i=0;i<10;i++){
                for (int j=0;j<10;j++){

                    //Draw
                    cells[i][j]->draw(window);


                    //if cursor is on a cell
                    if(cells[i][j]->isHover(mouseX,mouseY)){
 
                        //if pressed with left
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Left)){

                            //if its not flagged
                            if(!cells[i][j]->isFlagged()){       
                                  
                                //if you click on a bomb
                                if (cells[i][j]->getType().compare("bomb")==0){

                                    //reveal all cells
                                    for (int i=0;i<10;i++){
                                        for (int j=0;j<10;j++){
                                            cells[i][j]->reveal();
                                        }
                                    }

                                    //Game over
                                    gameOver=true;

                                }

                                //if you click on a non-bomb,
                                else{
                                    //Reveal cells around clicked cell
                                    cells[i][j]->revealRecursive(cells,cells[i][j]);
                                }
                            }
                        }

                        //If cell is clicked with right button
                        if(sf::Mouse::isButtonPressed(sf::Mouse::Right)&&!isPressed){
                            isPressed=true;
                            //cout<<"Here"<<endl;
                            //if cell is not revealed and not flagged
                            if(!cells[i][j]->isRevealed()&&!cells[i][j]->isFlagged()){
                                
                                // flag cell
                                cells[i][j]->flag();
                                flagsPlaced--;
                                //if bomb cell is flagged
                                if(cells[i][j]->getType().compare("bomb")==0){

                                    //Decreace numnber of mines found
                                    minesLeft--;
                                }
                            }
                            else{

                                if(cells[i][j]->getType().compare("bomb")==0){
                                    minesLeft++;
                                }

                                cells[i][j]->unflag();
                                flagsPlaced++;
                            }
                            cout<<minesLeft<<endl;
                        }
                        if(!sf::Mouse::isButtonPressed(sf::Mouse::Right)){
                            isPressed=false;
                        }
                        
                        
                    }
                }
            }

        }


        else {

            //Draw all cells for the last time
            for (int i=0;i<10;i++){
                for (int j=0;j<10;j++){
                    cells[i][j]->draw(window);
                }
            }

            // If game is over
            if(gameOver){

                // Set message
                msg.setString("You Lose");
            }

            //If all mines are flagged
            if(minesLeft<=0){  

                // Set message
                msg.setString("You Win");
            }
        }

        //Draw message
        window.draw(msg);    

        //Display everything
        window.display();
    }

    return 0;
}

int getRandomNumber(int min, int max){

    return min + rand() % (( max + 1 ) - min);
}
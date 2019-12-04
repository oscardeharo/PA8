#include"Game.h"
#include <SFML/Graphics.hpp>





int main(){
    Game g;
    g.start();
    //g.print();
    //exit(0);

    // //while all non bombs cells are inacvite
    // //or a bomb has not exploded
    // sf::RenderWindow window(sf::VideoMode(WINX,WINY), "SMFL Tutorial",sf::Style::Close|sf::Style::Resize);    

    // sf::RectangleShape c1(sf::Vector2f(CELLSIZE,CELLSIZE));
    // c1.setPosition(0*CELLSIZE,0*CELLSIZE);
    // c1.setFillColor(sf::Color::White);
    // c1.setOutlineThickness(10);
    // c1.setOutlineColor(sf::Color(155,155,155));

    // sf::RectangleShape c2(sf::Vector2f(CELLSIZE,CELLSIZE));
    // c2.setPosition(1*CELLSIZE,0*CELLSIZE);
    // c2.setFillColor(sf::Color::White);
    // c2.setOutlineThickness(10);
    // c2.setOutlineColor(sf::Color(155,155,155));

    // sf::Text text;
    // text.setString("A");
    // sf::Font arial;
    // arial.loadFromFile("30431287674.ttf");
    // text.setFont(arial);
    // text.setPosition(0*CELLSIZE,0*CELLSIZE);
    
    // text.setFillColor(sf::Color::Black);

    // while(window.isOpen()){
    //     sf::Event evnt;
    //     while(window.pollEvent(evnt)){

    //         switch (evnt.type){
    //             case sf::Event::Closed:
    //                 window.close();
    //                 break; 
    //             case sf::Event::Resized:
    //                 cout<<evnt.size.width<<endl;
    //                 break; 
    //             default:
                
    //                 break;
    //         }
    //     }
    //     window.clear(sf::Color::Black);  //window background color
    //     //window.draw(c1);
    //     //window.draw(text);
    //     //window.draw(c2);
    //     //cout<<"here"<<endl;
    //     window.display();
    // }

    // return 0;
}


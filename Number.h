#ifndef NUMBER_H
#define NUMBER_H
#include "Cell.h"

class Number: public Cell{

public:
    void onClick();
    Number(string, int, int,sf::Font&,int);

};


#endif
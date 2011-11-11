#ifndef CUBE_H
#define CUBE_H

#include "define.h"
#include <iostream>
#include <QString>

class Cube
{
public:
    Cube();
    ~Cube();
    int getColor(int i) {return cube[i];}
    unsigned int* getCube() {return cube;}
    void mixture(QString s);

private:
    unsigned int cube[54];
    unsigned int rotationCount;

};

#endif // CUBE_H

#ifndef CUBE_H
#define CUBE_H

#include "define.h"
#include "liste.h"
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
    bool rotation(QChar r);
    bool rotation(liste l);

private:
    unsigned int cube[54];
    unsigned int rotationCount;

};

#endif // CUBE_H

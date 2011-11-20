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
    Cube(unsigned int* tab);
    ~Cube();
    int getColor(int i) {return cube[i];}
    //void setColor(int i, int c) {cube[i] = c;}
    unsigned int* getCube() {return cube;}
    bool rotation(QChar r);
    bool rotation(liste l);
    unsigned int getRotationCount() {return rotationCount;}
    void restartRotationCount() {rotationCount = 0;}
    /*QChar getFace(int i);
    QChar getAxe(int i);*/
    Cube genRotation(QChar c);

    bool resolveFirstFace();
    bool resolveFirstEdge();
    bool resolveFirstCross();
    bool isResolveFirstEdge();
    bool isResolveFirstCross();

private:
    unsigned int cube[54];
    unsigned int rotationCount;


};

#endif // CUBE_H

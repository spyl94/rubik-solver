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
    int getColor(int i) {return cube[i];}
    unsigned int* getCube() {return cube;}
    bool rotation(QChar r);
    unsigned int getRotationCount() {return rotationCount;}
    void restartRotationCount() {rotationCount = 0;}

Cube genRotation(QChar c);
    bool resolveFirstFace(QString* solution);
    bool resolveFirstEdge(QString* solution);
    bool resolveFirstCross(QString* solution);
    bool resolveFirst1Cross(QString* solution);
    bool resolveFirst2Cross(QString* solution);
    bool resolveFirst3Cross(QString* solution);


private:
    unsigned int cube[54];
    unsigned int rotationCount;

    bool isResolveFirstEdge();
    bool isResolveFirstCross();
    bool isResolveFirstFace();
    bool isResolveFirst1Cross();
    bool isResolveFirst2Cross();
    bool isResolveFirst3Cross();
    bool is35Orange45White42GREEN();
    bool rotation(liste l);



};

#endif // CUBE_H

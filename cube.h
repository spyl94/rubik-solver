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
    void setCube(unsigned int *t) {for(int i=0; i <54; i++) cube[i] = t[i];}
    bool rotation(QChar r);
    bool rotation(QString str);
    unsigned int getRotationCount() {return rotationCount;}
    void restartRotationCount() {rotationCount = 0;}

    Cube genRotation(QChar c);
    bool resolveFirstCross(QString* solution);
    bool resolveFirst1Cross(QString* solution);
    bool resolveFirst2Cross(QString* solution);
    bool resolveFirst3Cross(QString* solution);
    bool resolveFirstFace(QString* solution);
    bool resolveSecondEdge(QString* solution);
    bool resolveThirdCross(QString* solution);
    bool resolveThirdEdge(QString* solution);
    bool resolveThirdEdgeCorner(QString* solution);
    bool resolveCube(QString* solution);




private:
    unsigned int cube[54];
    unsigned int rotationCount;
    bool rotation(liste l);

    bool isResolveFirstCross();
    bool isResolveFirstFace();
    bool isResolveFirst1Cross();
    bool isResolveFirst2Cross();
    bool isResolveFirst3Cross();
    bool is8Corner();
    bool is6Corner();
    bool is0Corner();
    bool is2Corner();
    bool is8CornerBottom();
    bool is6CornerBottom();
    bool is0CornerBottom();
    bool is2CornerBottom();
    bool isEdgeOrange();
    bool isEdgeBlue();
    bool isEdgeGreen();
    bool isEdgeRed();
    bool isResolveSecondEdgeOrange();
    bool isResolveSecondEdgeGreen();
    bool isResolveSecondEdgeRed();
    bool isResolveSecondEdgeBlue();
    bool isResolveSecondEdge();
    bool isResolveThirdCross();
    bool isResolveThirdEdge();
    bool is2CornerThirdEdge();
    bool isResolveThirdEdgeCorner();
    bool isResolve();

};
int solutionOptimizer(QString* str);
#endif // CUBE_H

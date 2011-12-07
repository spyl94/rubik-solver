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
    Cube(Cube const& pred);
    unsigned int* getCube() {return cube;}
    unsigned int getRotationCount() {return rotationCount;}
    int getColor(int i) {return cube[i];}
    int getPermuMax() {return permuMax;}
    QString getRotationList() {return rotationList;}
    void restart();
    bool rotation(QChar r);
    bool rotation(QString str);
    void restartRotationCount() {rotationCount = 0;}
    void setPermuMax(int i) {permuMax = i;}
    void setRotationList(QString l) {rotationList = l;}

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
    int permuMax;
    QString rotationList;
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

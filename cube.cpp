#include "cube.h"
#include <QDebug>

Cube::Cube() {
    int i = 0;
    for(; i<9; i++){
        cube[i] = WHITE;
    }
    for(; i<18; i++){
        cube[i] = BLUE;
    }
    for(; i<27; i++){
        cube[i] = RED;
    }
    for(; i<36; i++){
        cube[i] = ORANGE;
    }
    for(; i<45; i++){
        cube[i] = GREEN;
    }
    for(; i<54; i++){
        cube[i] = YELLOW;
    }
}

Cube::~Cube(){

}

void Cube::mixture(QString s){

}

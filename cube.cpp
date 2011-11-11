#include "cube.h"
#include "liste.h"
#include <QDebug>

using namespace std;

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
    /*
    for(; i<54; i++){
        cube[i] = rand() %6;
    }*/
    rotationCount = 0;
}

Cube::~Cube(){

}

bool Cube::rotation(QChar r){
    liste l = NULL;
    if(r == QChar('A'))
        l = listePermutations(5,(int[]){8,35,47,20},(int[]){5,32,46,19},(int[]){2,29,45,18},(int[]){36,42,44,38},(int[]){37,39,43,41});
    else if(r == QChar('B'))
        l = listePermutations(3,(int[]){7,34,50,23},(int[]){4,31,49,22},(int[]){1,28,48,21});
    else if(r == QChar('C'))
        l = listePermutations(5,(int[]){6,33,53,26},(int[]){3,30,52,25},(int[]){0,27,51,24},(int[]){17,15,9,11},(int[]){14,16,12,10});
    else if(r == QChar('D'))
        l = listePermutations(5,(int[]){8,2,0,6},(int[]){7,5,1,3},(int[]){29,38,26,17},(int[]){28,37,23,14},(int[]){27,36,20,11});
    else if(r == QChar('E'))
        l = listePermutations(3,(int[]){32,41,25,16},(int[]){31,40,22,13},(int[]){30,39,19,10});
    else if(r == QChar('F'))
        l = listePermutations(5,(int[]){35,44,24,15},(int[]){34,43,21,12},(int[]){33,42,18,9},(int[]){45,51,53,47},(int[]){48,52,50,46});
    else if(r == QChar('G'))
        l = listePermutations(5,(int[]){8,20,47,35},(int[]){5,19,46,32},(int[]){2,18,45,29},(int[]){36,38,44,42},(int[]){37,41,43,39});
    else if(r == QChar('H'))
        l = listePermutations(3,(int[]){7,23,50,34},(int[]){4,22,49,31},(int[]){1,21,48,28});
    else if(r == QChar('I'))
        l = listePermutations(5,(int[]){6,26,53,33},(int[]){3,25,52,30},(int[]){0,24,51,27},(int[]){17,11,9,15},(int[]){14,10,12,16});
    else if(r == QChar('J'))
        l = listePermutations(5,(int[]){8,6,0,2},(int[]){7,3,1,5},(int[]){29,17,26,38},(int[]){28,14,23,37},(int[]){27,11,20,36});
    else if(r == QChar('K'))
        l = listePermutations(3,(int[]){32,16,25,41},(int[]){31,13,22,40},(int[]){30,10,19,39});
    else if(r == QChar('L'))
        l = listePermutations(5,(int[]){35,15,24,44},(int[]){34,12,21,43},(int[]){33,9,18,42},(int[]){45,47,53,51},(int[]){48,46,50,52});
    else if(r == QChar('M'))
        return rotation(QChar('A')) && rotation(QChar('A'));
    else if(r == QChar('N'))
        return rotation(QChar('B')) && rotation(QChar('B'));
    else if(r == QChar('O'))
        return rotation(QChar('C')) && rotation(QChar('C'));
    else if(r == QChar('P'))
        return rotation(QChar('D')) && rotation(QChar('D'));
    else if(r == QChar('Q'))
        return rotation(QChar('E')) && rotation(QChar('E'));
    else if(r == QChar('R'))
        return rotation(QChar('F')) && rotation(QChar('F'));
    else if(r == QChar('S'))
        return rotation(QChar('G')) && rotation(QChar('D'));
    else if(r == QChar('T'))
        return rotation(QChar('H')) && rotation(QChar('E'));
    else if(r == QChar('U'))
        return rotation(QChar('I')) && rotation(QChar('F'));
    else if(r == QChar('V'))
        return rotation(QChar('A')) && rotation(QChar('J'));
    else if(r == QChar('W'))
        return rotation(QChar('B')) && rotation(QChar('K'));
    else if(r == QChar('X'))
        return rotation(QChar('C')) && rotation(QChar('L'));
    else if(r == QChar('Y'))
        return rotation(QChar('S')) && rotation(QChar('S'));
    else if(r == QChar('Z'))
        return rotation(QChar('T')) && rotation(QChar('T'));
    else if(r == QChar('@'))
        return rotation(QChar('U')) && rotation(QChar('U'));

    return rotation(l);
}
bool Cube::rotation(liste l) {
    if(l==NULL) return false;
    while(l != NULL) {
        noeud* c = l->info;
        swap(cube[c->info],cube[c->succ->info]);
        c = c->succ->succ;
        swap(cube[c->info],cube[c->succ->info]);
        swap(cube[c->info],cube[c->succ->succ->info]);
        l = l->succ;
    }
    return true;
}

void Cube::mixture(QString str){
    for (int i = 0; i < str.size(); ++i) {
        rotation(str.at(i));
    }
}

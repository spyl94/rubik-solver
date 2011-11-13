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
    rotationCount = 0;
}

Cube::~Cube(){

}

bool Cube::rotation(QChar r){
    liste l = NULL;
    if(r == QChar('A'))
        l = listePermutations(5,(int[]){8,35,47,20},(int[]){5,32,46,19},(int[]){2,29,45,18},(int[]){36,42,44,38},(int[]){37,39,43,41});
    else if(r == QChar('B'))
        //l = listePermutations(3,(int[]){7,34,50,23},(int[]){4,31,49,22},(int[]){1,28,48,21});
        l = listePermutations(5,(int[]){0,6,8,2},(int[]){1,3,7,5},(int[]){26,17,29,38},(int[]){23,14,28,37},(int[]){20,11,27,36});
    else if(r == QChar('C'))
       // l = listePermutations(5,(int[]){6,33,53,26},(int[]){3,30,52,25},(int[]){0,27,51,24},(int[]){17,15,9,11},(int[]){14,16,12,10});
       l = listePermutations(5,(int[]){24,18,20,26},(int[]){21,19,23,25},(int[]){53,44,2,11},(int[]){50,41,1,10},(int[]){47,38,0,9});
    else if(r == QChar('D'))
        //l = listePermutations(5,(int[]){8,2,0,6},(int[]){7,5,1,3},(int[]){29,38,26,17},(int[]){28,37,23,14},(int[]){27,36,20,11});
        l = listePermutations(5,(int[]){6,33,53,26},(int[]){3,30,52,25},(int[]){0,27,51,24},(int[]){17,15,9,11},(int[]){14,16,12,10});
    else if(r == QChar('E'))
        //l = listePermutations(3,(int[]){32,41,25,16},(int[]){31,40,22,13},(int[]){30,39,19,10});
        l = listePermutations(5,(int[]){35,44,24,15},(int[]){34,43,21,12},(int[]){33,42,18,9},(int[]){45,51,53,47},(int[]){48,52,50,46});
    else if(r == QChar('F'))
        //l = listePermutations(5,(int[]){35,44,24,15},(int[]){34,43,21,12},(int[]){33,42,18,9},(int[]){45,51,53,47},(int[]){48,52,50,46});
        l = listePermutations(5,(int[]){27,29,35,33},(int[]){28,32,34,30},(int[]){6,36,45,15},(int[]){7,39,48,16},(int[]){8,42,51,17});
    else if(r == QChar('G'))
        l = listePermutations(5,(int[]){8,20,47,35},(int[]){5,19,46,32},(int[]){2,18,45,29},(int[]){36,38,44,42},(int[]){37,41,43,39});
    else if(r == QChar('H'))
        //l = listePermutations(3,(int[]){7,23,50,34},(int[]){4,22,49,31},(int[]){1,21,48,28});
        l = listePermutations(5,(int[]){0,2,8,6},(int[]){1,5,7,3},(int[]){26,38,29,17},(int[]){23,37,28,14},(int[]){20,36,27,11});
    else if(r == QChar('I'))
        //l = listePermutations(5,(int[]){6,26,53,33},(int[]){3,25,52,30},(int[]){0,24,51,27},(int[]){17,11,9,15},(int[]){14,10,12,16});
        l = listePermutations(5,(int[]){24,26,20,18},(int[]){21,25,23,19},(int[]){53,11,2,44},(int[]){50,10,1,41},(int[]){47,9,0,38});
    else if(r == QChar('J'))
        //l = listePermutations(5,(int[]){8,6,0,2},(int[]){7,3,1,5},(int[]){29,17,26,38},(int[]){28,14,23,37},(int[]){27,11,20,36});
        l = listePermutations(5,(int[]){6,26,53,33},(int[]){3,25,52,30},(int[]){0,24,51,27},(int[]){17,11,9,15},(int[]){14,10,12,16});
    else if(r == QChar('K'))
        //l = listePermutations(3,(int[]){32,16,25,41},(int[]){31,13,22,40},(int[]){30,10,19,39});
        l = listePermutations(5,(int[]){35,15,24,44},(int[]){34,12,21,43},(int[]){33,9,18,42},(int[]){45,47,53,51},(int[]){48,46,50,52});
    else if(r == QChar('L'))
        //l = listePermutations(5,(int[]){35,15,24,44},(int[]){34,12,21,43},(int[]){33,9,18,42},(int[]){45,47,53,51},(int[]){48,46,50,52});
        l = listePermutations(5,(int[]){27,33,35,29},(int[]){28,30,34,32},(int[]){6,15,45,36},(int[]){7,16,48,39},(int[]){8,17,51,42});
    else if(r == QChar('M'))
        return rotation(QChar('A')) && rotation(QChar('A')) && rotationCount--;
    else if(r == QChar('N'))
        return rotation(QChar('B')) && rotation(QChar('B')) && rotationCount--;
    else if(r == QChar('O'))
        return rotation(QChar('C')) && rotation(QChar('C')) && rotationCount--;
    else if(r == QChar('P'))
        return rotation(QChar('D')) && rotation(QChar('D')) && rotationCount--;
    else if(r == QChar('Q'))
        return rotation(QChar('E')) && rotation(QChar('E')) && rotationCount--;
    else if(r == QChar('R'))
        return rotation(QChar('F')) && rotation(QChar('F')) && rotationCount--;
    else if(r == QChar('S'))
        return rotation(QChar('G')) && rotation(QChar('D')) && rotationCount--;
    else if(r == QChar('T'))
        return rotation(QChar('H')) && rotation(QChar('E')) && rotationCount--;
    else if(r == QChar('U'))
        return rotation(QChar('I')) && rotation(QChar('F')) && rotationCount--;
    else if(r == QChar('V'))
        return rotation(QChar('A')) && rotation(QChar('J')) && rotationCount--;
    else if(r == QChar('W'))
        return rotation(QChar('B')) && rotation(QChar('K')) && rotationCount--;
    else if(r == QChar('X'))
        return rotation(QChar('C')) && rotation(QChar('L')) && rotationCount--;
    else if(r == QChar('Y'))
        return rotation(QChar('S')) && rotation(QChar('S')) && rotationCount--;
    else if(r == QChar('Z'))
        return rotation(QChar('T')) && rotation(QChar('T')) && rotationCount--;
    else if(r == QChar('@'))
        return rotation(QChar('U')) && rotation(QChar('U')) && rotationCount--;

    return rotation(l) && deleteListePermutations(&l);
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
    rotationCount++;
    return true;
}
QChar Cube::getFace(int i) {
    if(i <= 8) return QChar('H');
    if(i <= 17) return QChar('G');
    if(i <= 26) return QChar('C');
    if(i <= 35) return QChar('H');
    if(i <= 42) return QChar('D');
    return QChar('B');
}
bool Cube::resolveFirstFace() {
    for(int i =0; i < 9 ;) {
        if(cube[i] == WHITE) i++;
        else i = 9;
        if (i==8) return true;
    }
    if(!resolveFirstEdge()) resolveFirstEdge();


    return false;
    //return resolveFirstFace();
}
bool Cube::resolveFirstEdge() {
    if(cube[1] == WHITE && cube[3] == WHITE && cube[5] == WHITE && cube[7] == WHITE){
        return true;
    }
    /*do {
        int ran = rand()%26 +64;
        rotation(QChar(ran));
        qDebug() << ran;
    }while(!resolveFirstEdge());*/

    if(cube[3] != WHITE) {
        if(cube[30] == WHITE) rotation(QChar('J'));
        else if(cube[52] == WHITE) rotation(QChar('Y'));
        else if(cube[25] == WHITE) rotation(QChar('D'));
        else if(cube[32] == WHITE) rotation(QChar('A')) && rotation(QChar('Z')) && rotation(QChar('G'));
        else if(cube[19] == WHITE) rotation(QChar('G')) && rotation(QChar('G')) && rotation(QChar('A')) && rotation(QChar('Z')) && rotation(QChar('G'));
        else qDebug() << "impossible";
    }

    return false;

}
QChar Cube::getAxe(int i){
    switch(i) {
    case 1:
    case 4:
    case 7:
    case 21:
    case 22:
    case 23:
    case 28:
    case 31:
    case 34:
    case 48:
    case 49:
    case 50:
    case 41:
    case 40:
    case 39:
    case 10:
    case 13:
    case 16:
        return QChar('Y');
    case 18:
    case 19:
    case 20:
    case 2:
    case 5:
    case 8:
    case 29:
    case 32:
    case 35:
    case 45:
    case 46:
    case 47:
    case 36:
    case 37:
    case 38:
    case 11:
    case 14:
    case 17:
        return QChar('X');
    default:
        return QChar('Z');
    }
}

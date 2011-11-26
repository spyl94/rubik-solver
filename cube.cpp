#include "cube.h"
#include "liste.h"
#include <QDebug>

using namespace std;

/**
 * Constructeur d'un cube à l'état initial.
 *
 */
Cube::Cube() {
    int i = 0;
    for(; i<9;  i++)cube[i] = WHITE;
    for(; i<18; i++)cube[i] = BLUE;
    for(; i<27; i++)cube[i] = RED;
    for(; i<36; i++)cube[i] = ORANGE;
    for(; i<45; i++)cube[i] = GREEN;
    for(; i<54; i++)cube[i] = YELLOW;
    rotationCount = 0;
}

/**
 * Constructeur d'un cube à un état donné.
 *
 * Parametre tab : le tableau déterminant l'état du nouveau cube.
 */
Cube::Cube(unsigned int* tab) {
    for(int i =0; i < 54; i++)cube[i] = tab[i];
    rotationCount = 0;
}

/**
 * Applique une rotation selon la lettre reçu en paramètre.
 *
 * Parametre r : la lettre déterminant la rotation.
 *
 * Retourne : vrai si la rotation et la suppression de la liste c'est bien passé, faux sinon.
 */
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
        //return rotation(QChar('A')) && rotation(QChar('A')) &&  rotation(QChar('A'));
    else if(r == QChar('H'))
       //return rotation(QChar('B')) && rotation(QChar('B')) &&  rotation(QChar('B'));
       l = listePermutations(5,(int[]){0,2,8,6},(int[]){1,5,7,3},(int[]){26,38,29,17},(int[]){23,37,28,14},(int[]){20,36,27,11});
    else if(r == QChar('I'))
        //return rotation(QChar('C')) && rotation(QChar('C')) &&  rotation(QChar('C'));
       l = listePermutations(5,(int[]){24,26,20,18},(int[]){21,25,23,19},(int[]){53,11,2,44},(int[]){50,10,1,41},(int[]){47,9,0,38});
    else if(r == QChar('J'))
       // return rotation(QChar('D')) && rotation(QChar('D')) &&  rotation(QChar('D'));
       l = listePermutations(5,(int[]){6,26,53,33},(int[]){3,25,52,30},(int[]){0,24,51,27},(int[]){17,11,9,15},(int[]){14,10,12,16});
    else if(r == QChar('K'))
       // return rotation(QChar('E')) && rotation(QChar('E')) &&  rotation(QChar('E'));
       l = listePermutations(5,(int[]){35,15,24,44},(int[]){34,12,21,43},(int[]){33,9,18,42},(int[]){45,47,53,51},(int[]){48,46,50,52});
    else if(r == QChar('L'))
       // return rotation(QChar('F')) && rotation(QChar('F')) &&  rotation(QChar('F'));
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

/**
 * Applique la rotation au cube selon la liste reçu en paramètre.
 *
 * Parametre l : lsc de lcc déterminant les rotations à appliquer.
 *
 * Retourne : faux si la liste reçu est vide, vrai sinon.
 */
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
/**
 * Crée un nouveau cube auquel on applique la rotation reçu en paramètre.
 *
 * Parametre c : la lettre correspondant à la rotation.
 *
 * Retourne : le nouveau cube.
 */
Cube Cube::genRotation(QChar c) {
    Cube gen(this->getCube());
    gen.rotation(c);
    return gen;
}

/**
 * Convertit une QString de rotations élementaires en une liste de rotations de A à @.
 *
 * Parametre str : la QString a convertir.
 *
 * Retourne : la taille de la nouvelle liste.
 */
int solutionOptimizer(QString* str) {
    str->replace("AAA","G");
    str->replace("BBB","H");
    str->replace("CCC","I");
    str->replace("DDD","J");
    str->replace("EEE","K");
    str->replace("FFF","L");
    str->replace("AA","M");
    str->replace("BB","N");
    str->replace("CC","O");
    str->replace("DD","P");
    str->replace("EE","Q");
    str->replace("FF","R");
    str->replace("GD","S");
    str->replace("HE","T");
    str->replace("IF","U");
    str->replace("AJ","V");
    str->replace("BK","W");
    str->replace("CL","X");
    str->replace("SS","Y");
    str->replace("TT","Z");
    str->replace("UU","@");
    return str->size();
}

/**
 * Simule des rotations élementaires afin de résoudre un état du cube.
 *
 * Parametre c : le cube à résoudre.
 * Parametre str : QString des rotations effectuées pour atteindre cet état.
 * Parametre i : nombre de rotations élementaires effectuées pour atteindre cet état.
 * Parametre min : le nombre de rotations minimums effectuées pour résoudre l'état recherché.
 * Parametre pt2Member : pointeur sur la méthode testant l'état du cube recherché.
 *
 * Retourne : QString contenant la solution, "" si pas de solution trouvée.
 */
QString gen(Cube c, QString str, int i, int* min,bool (Cube::*pt2Member)() ){
    if((c.*pt2Member)()){
        qDebug() << "Résolu avec" << str;
        return str.append(QChar('1'));
    }
    if(i==nbPermuMax) return 0;
    QString bestSol = "";
   // qDebug() << str << i;
    if(i <= *min && !str.endsWith("AAA")) {
        QString strCopy = str;
        QString isDone = gen(c.genRotation(QChar('A')), strCopy.append(QChar('A')),i+1,min, pt2Member);
        if(isDone.endsWith("1")){
            if(solutionOptimizer(&isDone) <= *min) {
                bestSol = isDone;
                *min = isDone.size();
            }
            if(i!=0) return bestSol;
        }
    }
    if(i <= *min && !str.endsWith("BBB")) {
        QString strCopy = str;
        QString isDone = gen(c.genRotation(QChar('B')), strCopy.append(QChar('B')),i+1,min, pt2Member);
        if(isDone.endsWith("1")){
            if(solutionOptimizer(&isDone) <= *min) {
                bestSol = isDone;
                *min = isDone.size();
            }
            if(i!=0) return bestSol;
        }
    }
    if(i <= *min && !str.endsWith("CCC")) {
        QString strCopy = str;
        QString isDone = gen(c.genRotation(QChar('C')), strCopy.append(QChar('C')),i+1,min, pt2Member);
        if(isDone.endsWith("1")){
            if(solutionOptimizer(&isDone) <= *min) {
                bestSol = isDone;
                *min = isDone.size();
            }
            if(i!=0) return bestSol;
        }
    }
    if(i <= *min && !str.endsWith("DDD")) {
        QString strCopy = str;
        QString isDone = gen(c.genRotation(QChar('D')), strCopy.append(QChar('D')),i+1,min, pt2Member);
        if(isDone.endsWith("1")){
            if(solutionOptimizer(&isDone) <= *min) {
                bestSol = isDone;
                *min = isDone.size();
            }
            if(i!=0) return bestSol;
        }
    }
    if(i <= *min && !str.endsWith("EEE")) {
        QString strCopy = str;
        QString isDone = gen(c.genRotation(QChar('E')), strCopy.append(QChar('E')),i+1,min, pt2Member);
        if(isDone.endsWith("1")){
            if(solutionOptimizer(&isDone) <= *min) {
                bestSol = isDone;
                *min = isDone.size();
            }
            if(i!=0) return bestSol;
        }
    }
    if(i <= *min && !str.endsWith("FFF")) {
        QString strCopy = str;
        QString isDone = gen(c.genRotation(QChar('F')), strCopy.append(QChar('F')),i+1,min, pt2Member);
        if(isDone.endsWith("1")){
            if(solutionOptimizer(&isDone) <= *min) {
                bestSol = isDone;
                *min = isDone.size();
            }
            if(i!=0) return bestSol;
        }
    }
    return bestSol;
}

bool Cube::isResolveFirstEdge(){
    if(cube[1] == WHITE && cube[3] == WHITE && cube[5] == WHITE && cube[7] == WHITE) return true;
    return false;
}

bool Cube::isResolveFirstCross(){
    if(cube[1] == WHITE && cube[3] == WHITE && cube[5] == WHITE && cube[7] == WHITE && cube[28] == ORANGE
    && cube[23] == RED && cube[14] == BLUE && cube[37]==GREEN) return true;
    return false;
}

bool Cube::isResolveFirst1Cross(){
    if(cube[1] == WHITE && cube[23] == RED ) return true;
    return false;
}

bool Cube::isResolveFirst2Cross(){
    if(cube[1] == WHITE && cube[23] == RED && cube[7] == WHITE && cube[28] == ORANGE) return true;
    return false;
}

bool Cube::isResolveFirst3Cross(){
    if(cube[1] == WHITE && cube[23] == RED && cube[7] == WHITE && cube[28] == ORANGE && cube[5] == WHITE && cube[37] == GREEN) return true;
    return false;
}

bool Cube::isResolveFirstFace() {
    for(int i=0; i <=8; i++){
        if(cube[i] != WHITE) return false;
    }
    if(cube[26] != RED || cube[23] != RED || cube[20] != RED) return false;
    if(cube[11] != BLUE || cube[14] != BLUE || cube[17] != BLUE) return false;
    if(cube[27] != ORANGE || cube[28] != ORANGE || cube[29] != ORANGE) return false;
    if(cube[36] != GREEN || cube[37] != GREEN || cube[38] != GREEN) return false;
    return true;
}

bool Cube::resolveFirstFace(QString* solution) {
     if(isResolveFirstFace()) return true;
     int min = nbPermuMax;
     *solution = gen(*this, "", 0, &min, &Cube::isResolveFirstFace).replace("1","");
     qDebug() << "genFirstFace()" << *solution;
     if(*solution=="") return false; // On a pas trouvé de solution
    return true;
}

bool Cube::resolveFirstEdge(QString* solution) {
     if(isResolveFirstEdge()) return true;
     int min = nbPermuMax;
     *solution = gen(*this, "", 0, &min, &Cube::isResolveFirstEdge).replace("1","");
     qDebug() << "genFirstEdge()" << *solution;
     if(*solution=="") return false; // On a pas trouvé de solution
    return true;
}

bool Cube::resolveFirstCross(QString* solution) {
     if(isResolveFirstCross()) return true;
     int min = nbPermuMax;
     *solution = gen(*this, "", 0, &min, &Cube::isResolveFirstCross).replace("1","");
     qDebug() << "genFirstCross()" << *solution;
     if(*solution=="") return false; // On a pas trouvé de solution
    return true;
}

bool Cube::resolveFirst1Cross(QString* solution) {
     if(isResolveFirst1Cross()) return true;
     int min = nbPermuMax;
     *solution = gen(*this, "", 0, &min, &Cube::isResolveFirst1Cross).replace("1","");
     qDebug() << "genFirstCross()" << *solution;
     if(*solution=="") return false; // On a pas trouvé de solution
    return true;
}
bool Cube::resolveFirst2Cross(QString* solution) {
     if(isResolveFirst2Cross()) return true;
     int min = nbPermuMax;
     *solution = gen(*this, "", 0, &min, &Cube::isResolveFirst2Cross).replace("1","");
     qDebug() << "genFirstCross()" << *solution;
     if(*solution=="") return false; // On a pas trouvé de solution
    return true;
}
bool Cube::resolveFirst3Cross(QString* solution) {
     if(isResolveFirst3Cross()) return true;
     int min = nbPermuMax;
     *solution = gen(*this, "", 0, &min, &Cube::isResolveFirst3Cross).replace("1","");
     qDebug() << "genFirstCross()" << *solution;
     if(*solution=="") return false; // On a pas trouvé de solution
    return true;
}

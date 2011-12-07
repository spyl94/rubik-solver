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
    //Pour afficher les indices:
    //for(int i=0; i <54; i++) cube[i] = i;
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
 * Constructeur d'un cube à partir d'un autre cube.
 *
 * Parametre pred : le cube à copier.
 */
Cube::Cube(Cube const& pred) {
    for(int i =0; i < 54; i++)cube[i] = pred.cube[i];
    rotationCount = 0;
    permuMax = pred.permuMax;
    rotationList = pred.rotationList;
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
        l = listePermutations(5,(int[]){0,6,8,2},(int[]){1,3,7,5},(int[]){26,17,29,38},(int[]){23,14,28,37},(int[]){20,11,27,36});
    else if(r == QChar('C'))
        l = listePermutations(5,(int[]){24,26,20,18},(int[]){21,25,23,19},(int[]){53,11,2,44},(int[]){50,10,1,41},(int[]){47,9,0,38});
    else if(r == QChar('D'))
        l = listePermutations(5,(int[]){6,26,53,33},(int[]){3,25,52,30},(int[]){0,24,51,27},(int[]){17,11,9,15},(int[]){14,10,12,16});
    else if(r == QChar('E'))
        l = listePermutations(5,(int[]){35,15,24,44},(int[]){34,12,21,43},(int[]){33,9,18,42},(int[]){45,51,53,47},(int[]){48,52,50,46});
    else if(r == QChar('F'))
        l = listePermutations(5,(int[]){27,33,35,29},(int[]){28,30,34,32},(int[]){6,15,45,36},(int[]){7,16,48,39},(int[]){8,17,51,42});
    else if(r == QChar('G'))
        l = listePermutations(5,(int[]){8,20,47,35},(int[]){5,19,46,32},(int[]){2,18,45,29},(int[]){36,38,44,42},(int[]){37,41,43,39});
    else if(r == QChar('H'))
        l = listePermutations(5,(int[]){0,2,8,6},(int[]){1,5,7,3},(int[]){26,38,29,17},(int[]){23,37,28,14},(int[]){20,36,27,11});
    else if(r == QChar('I'))
        l = listePermutations(5,(int[]){24,18,20,26},(int[]){21,19,23,25},(int[]){53,44,2,11},(int[]){50,41,1,10},(int[]){47,38,0,9});
    else if(r == QChar('J'))
        l = listePermutations(5,(int[]){6,33,53,26},(int[]){3,30,52,25},(int[]){0,27,51,24},(int[]){17,15,9,11},(int[]){14,16,12,10});
    else if(r == QChar('K'))
        l = listePermutations(5,(int[]){35,44,24,15},(int[]){34,43,21,12},(int[]){33,42,18,9},(int[]){45,47,53,51},(int[]){48,46,50,52});
    else if(r == QChar('L'))
        l = listePermutations(5,(int[]){27,29,35,33},(int[]){28,32,34,30},(int[]){6,36,45,15},(int[]){7,39,48,16},(int[]){8,42,51,17});
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

bool Cube::rotation(QString str){
    for(int i =0; i < str.length(); i++) if(!rotation(str.at(i)))return false;
    return true;
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
    Cube gen(*this);
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
    str->replace("GG","M");
    str->replace("BB","N");
    str->replace("HH","N");
    str->replace("CC","O");
    str->replace("II","O");
    str->replace("DD","P");
    str->replace("JJ","P");
    str->replace("EE","Q");
    str->replace("KK","Q");
    str->replace("FF","R");
    str->replace("LL","R");
    str->replace("GD","S");
    str->replace("HE","T");
    str->replace("IF","U");
    str->replace("AJ","V");
    str->replace("BK","W");
    str->replace("CL","X");
    str->replace("SS","Y");
    str->replace("TT","Z");
    str->replace("UU","@");
    str->replace("EEEE","");
    return str->length();
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
    if(i == c.getPermuMax()) return 0;
    QString bestSol = "";

    QString rotations = c.getRotationList();
    for(int j =0; j < rotations.length(); j++){
        QChar current = rotations.at(j);
        QString s = current;
        s+= current;
        s+= current; // s contient 3fois la lettre: condition de sortie on retourne à un état par lequel on est déjà passé.

        if(i < *min -2 && !str.endsWith(s)) {
            QString strCopy = str;
            QString isDone = gen(c.genRotation(current), strCopy.append(current),i+1,min, pt2Member);
            if(isDone.endsWith("1")){ //si on a résolu
                if(solutionOptimizer(&isDone) <= *min) {
                    bestSol = isDone;
                    *min = isDone.length();
                }
                if(i!=0) return bestSol;
            }
        }
    }
    return bestSol;
}

/**
 * Résout la croix de la première face du cube.
 *
 * Parametre solution : contient la liste des opération pour résoudre la face en sortie de la fonction.
 * Retourne : vrai si réussi, faux sinon
 */
bool Cube::resolveFirstCross(QString* solution) {
    if(isResolveFirstCross()) return true;
    int min = nbPermuMax;
    *solution = gen(*this, "", 0, &min, &Cube::isResolveFirstCross).replace("1","");
    qDebug() << "genFirstCross()" << *solution;
    if(*solution=="") return false; // On a pas trouvé de solution
    return true;
}

/**
 * Résout la première face du cube.
 *
 * Parametre solution : contient la liste des opération pour résoudre la face en sortie de la fonction.
 * Retourne : vrai si réussi, faux sinon
 */
bool Cube::resolveFirstFace(QString* solution) {
    if(isResolveFirstFace()) return true;
    QString tmp;
    Cube copy(*this);
    int min = nbPermuMax;
    if(solution->size() > 100) return false;

    if(!copy.is8Corner() && copy.is8CornerBottom()) {
        copy.rotation("AKG");
        return copy.resolveFirstFace(&(solution->append("AKG")));
    }
    if(!copy.is6Corner() && copy.is6CornerBottom()) {
        copy.rotation("FKL");
        return copy.resolveFirstFace(&(solution->append("FKL")));
    }
    if(!copy.is0Corner() && copy.is0CornerBottom()) {
        copy.rotation("DKJ");
        return copy.resolveFirstFace(&(solution->append("DKJ")));
    }
    if(!copy.is2Corner() && copy.is2CornerBottom()) {
        copy.rotation("CKI");
        return copy.resolveFirstFace(&(solution->append("CKI")));
    }
    // on a aucun cube de bien placé pour devenir un coin... on génère leur placement
    if(!copy.is8Corner()){
        tmp = gen(copy, "", 0, &min, &Cube::is8CornerBottom).replace("1","");
        qDebug() << "gen8()" << tmp;
        if(tmp == "" && !copy.is8CornerBottom()) return false;
        copy.rotation(tmp);
        return copy.resolveFirstFace(&(solution->append(tmp)));
    }
    if(!copy.is0Corner()){
        tmp = gen(copy, "", 0, &min, &Cube::is0CornerBottom).replace("1","");
        qDebug() << "gen0()" << tmp;
        if(tmp == "" && !copy.is0CornerBottom()) return false;
        copy.rotation(tmp);
        return copy.resolveFirstFace(&(solution->append(tmp)));
    }
    if(!copy.is2Corner()){
        tmp = gen(copy, "", 0, &min, &Cube::is2CornerBottom).replace("1","");
        qDebug() << "gen2()" << tmp;
        if(tmp == "" && !copy.is2CornerBottom()) return false;
        copy.rotation(tmp);
        return copy.resolveFirstFace(&(solution->append(tmp)));
    }
    if(!copy.is6Corner()){
        tmp = gen(copy, "", 0, &min, &Cube::is6CornerBottom).replace("1","");
        qDebug() << "gen6()" << tmp;
        if(tmp == "" && !copy.is6CornerBottom()) return false;
        copy.rotation(tmp);
        return copy.resolveFirstFace(&(solution->append(tmp)));
    }
    return false;
}
/**
 * Résout le deuxième étage du cube.
 *
 * Parametre solution : contient la liste des opération pour résoudre la face en sortie de la fonction.
 * Retourne : vrai si réussi, faux sinon
 */
bool Cube::resolveSecondEdge(QString* solution) {
    if(isResolveSecondEdge()) return true;
    QString tmp = "";
    Cube copy(getCube());
    if(copy.getColor(34) == ORANGE){
        if(copy.getColor(48) == BLUE){
            copy.rotation("KJEDEFKL");
            tmp+="KJEDEFKL";
        } if(copy.getColor(48) == GREEN){
            copy.rotation("EAKGKLEF");
            tmp+="EAKGKLEF";
        }
    }
    if(copy.getColor(43) == GREEN){
        if(copy.getColor(46)== ORANGE){
            copy.rotation("KLEFEAKG");
            tmp+="KLEFEAKG";
        } if(copy.getColor(46)== RED){
            copy.rotation("ECKIKGEA");
            tmp+="ECKIKGEA";
        }
    }
    if(copy.getColor(21) == RED){
        if(copy.getColor(50)== GREEN){
            copy.rotation("KGEAECKI");
            tmp+="KGEAECKI";
        } if(copy.getColor(50)== BLUE){
            copy.rotation("EDKJKIEC");
            tmp+="EDKJKIEC";
        }
    }
    if(copy.getColor(12) == BLUE){
        if(copy.getColor(52)== RED){
            copy.rotation("KIECEDKJ");
            tmp+="KIECEDKJ";
        } if(copy.getColor(52)== ORANGE){
            copy.rotation("EFKLKJED");
            tmp+="EFKLKJED";
        }
    }
    *solution += tmp;
    if(copy.isResolveSecondEdge()) return true;
    tmp = "";
    if(solution->endsWith("EEEE")){
        if(cube[10]!=BLUE && cube[25]!=RED){
            copy.rotation("EDKJKIEC");
            tmp+="EDKJKIEC";
        }
        else if(cube[30]!=ORANGE && cube[16]!=BLUE){
            copy.rotation("KJEDEFKL");
            tmp+="KJEDEFKL";
        }
        else if(cube[19]!=RED && cube[41]!=GREEN){
            copy.rotation("KGEAECKI");
            tmp+="KGEAECKI";
        }
        else if(cube[39]!=GREEN && cube[32]!=ORANGE){
            copy.rotation("KLEFEAKG");
            tmp+="KLEFEAKG";
        }
        else return true;
        *solution += tmp;
    }
    copy.rotation("E");
    *solution += "E";
    return copy.resolveSecondEdge(solution);
}

/**
 * Résout la croix sur la dernière face du cube.
 *
 * Parametre solution : contient la liste des opération pour résoudre la face en sortie de la fonction.
 * Retourne : vrai si réussi, faux sinon
 */
bool Cube::resolveThirdCross(QString* solution) {
    if(isResolveThirdCross()) return true;
    if(solution->size() > 100) return false;
    Cube copy(getCube());

    if((cube[48]!=YELLOW && cube[46]!=YELLOW && cube[50]!=YELLOW && cube[52]!=YELLOW)||(cube[46]==YELLOW && cube[48]==YELLOW)){
        copy.rotation("GKLEFA");
        return copy.resolveThirdCross(&(solution->append("GKLEFA")));
    }
    if(cube[48]==YELLOW && cube[50]==YELLOW) {
        copy.rotation("GLKFEA");
        return copy.resolveThirdCross(&(solution->append("GLKFEA")));
    }
    if(solution->endsWith("EEE")) return false;
    copy.rotation("E");
    return copy.resolveThirdCross(&(solution->append("E")));
}

/**
 * Résout la troisième face du cube.
 *
 * Parametre solution : contient la liste des opération pour résoudre la face en sortie de la fonction.
 * Retourne : vrai si réussi, faux sinon
 */
bool Cube::resolveThirdEdge(QString* solution){
    if(isResolveThirdEdge()) return true;
    Cube copy(getCube());
    if(solution->size() > 100) return false;

    if((copy.getColor(47)==YELLOW && copy.getColor(51)!=YELLOW && copy.getColor(45) !=YELLOW && copy.getColor(53)!= YELLOW) ||
            (copy.is2CornerThirdEdge() && copy.getColor(44)==YELLOW) ||
            (copy.getColor(51)!=YELLOW && copy.getColor(45)!=YELLOW && copy.getColor(47) != YELLOW && copy.getColor(53)!= YELLOW && copy.getColor(18)==YELLOW)
            ){
        copy.rotation("LKFKLKKF");
        return copy.resolveThirdEdge(&(solution->append("LKFKLKKF")));
    }
    if((copy.getColor(51)==YELLOW && copy.getColor(47)!=YELLOW && copy.getColor(45) !=YELLOW && copy.getColor(53)!= YELLOW) ||
            (copy.is2CornerThirdEdge() && copy.getColor(15)==YELLOW) ||
            (copy.getColor(51)!=YELLOW && copy.getColor(45)!=YELLOW && copy.getColor(47) != YELLOW && copy.getColor(53)!= YELLOW && copy.getColor(33)==YELLOW)
            ){
        copy.rotation("IKCKIKKC");
        return copy.resolveThirdEdge(&(solution->append("IKCKIKKC")));
    }
    if((copy.getColor(45)==YELLOW && copy.getColor(47)!=YELLOW && copy.getColor(51) !=YELLOW && copy.getColor(53)!= YELLOW) ||
            (copy.is2CornerThirdEdge() && copy.getColor(24)==YELLOW) ||
            (copy.getColor(51)!=YELLOW && copy.getColor(45)!=YELLOW && copy.getColor(47) != YELLOW && copy.getColor(53)!= YELLOW && copy.getColor(9)==YELLOW)
            ){
        copy.rotation("GKAKGKKA");
        return copy.resolveThirdEdge(&(solution->append("GKAKGKKA")));
    }
    if((copy.getColor(53)==YELLOW && copy.getColor(47)!=YELLOW && copy.getColor(51) !=YELLOW && copy.getColor(45)!= YELLOW) ||
            (copy.is2CornerThirdEdge() && copy.getColor(35)==YELLOW) ||
            (copy.getColor(51)!=YELLOW && copy.getColor(45)!=YELLOW && copy.getColor(47) != YELLOW && copy.getColor(53)!= YELLOW && copy.getColor(42)==YELLOW)
            ){
        copy.rotation("JKDKJKKD");
        return copy.resolveThirdEdge(&(solution->append("JKDKJKKD")));
    }
    return false;
}

/**
 * Oriente les coins de la troisième face du cube.
 *
 * Parametre solution : contient la liste des opération pour résoudre la face en sortie de la fonction.
 * Retourne : vrai si réussi, faux sinon
 */
bool Cube::resolveThirdEdgeCorner(QString* solution){
    if(isResolveThirdEdgeCorner()) return true;
    Cube copy(getCube());

    if(cube[9]==BLUE && cube[24]==RED && cube[18]==RED && cube[44]==GREEN) {
        copy.rotation("DLDCCJFDCCJJE");
        return copy.resolveThirdEdgeCorner(&(solution->append("DLDCCJFDCCJJE")));
    }
    if(cube[9]==BLUE && cube[24]==RED && cube[15]==BLUE && cube[33]==ORANGE){
        copy.rotation("FGFDDLAFDDLLE");
        return copy.resolveThirdEdgeCorner(&(solution->append("FGFDDLAFDDLLE")));
    }
    if(cube[35]==ORANGE && cube[42]==GREEN && cube[15]==BLUE && cube[33]==ORANGE){
        copy.rotation("AIAFFGCAFFGGE");
        return copy.resolveThirdEdgeCorner(&(solution->append("AIAFFGCAFFGGE")));
    }
    if(cube[35]==ORANGE && cube[42]==GREEN && cube[18]==RED && cube[44]==GREEN){
        copy.rotation("CJCAAIDCAAIIE");
        return copy.resolveThirdEdgeCorner(&(solution->append("CJCAAIDCAAIIE")));
    }
    if(solution->endsWith("EEEE")) {
        copy.rotation("DLDCCJFDCCJJE");
        return copy.resolveThirdEdgeCorner(&(solution->append("DLDCCJFDCCJJE")));
    }
    copy.rotation("E");
    return copy.resolveThirdEdgeCorner(&(solution->append("E")));
}
/**
 * Oriente les arrètes de la troisième face du cube pour le résoudre.
 *
 * Parametre solution : contient la liste des opération pour résoudre la face en sortie de la fonction.
 * Retourne : vrai si réussi, faux sinon
 */
bool Cube::resolveCube(QString* solution){
    if(isResolve())return true;
    Cube copy(getCube());
    if(cube[12]==BLUE && cube[43]==ORANGE){
        solution->append("GGEIFGGCLEGG");
        return copy.rotation("GGEIFGGCLEGG");
    }
    if(cube[12]==BLUE && cube[43]==RED){
        solution->append("GGKIFGGCLKGG");
        return copy.rotation("GGKIFGGCLKGG");
    }
    if(cube[34]==ORANGE && cube[21]==BLUE){
        solution->append("IIKJAIIDGKII");
        return copy.rotation("IIKJAIIDGKII");
    }
    if(cube[34]==ORANGE && cube[21]==GREEN){
        solution->append("IIEJAIIDGEII");
        return copy.rotation("IIEJAIIDGEII");
    }
    if(cube[21]==RED && cube[34]==BLUE){
        solution->append("LLEGDLLAJELL");
        return copy.rotation("LLEGDLLAJELL");
    }
    if(cube[21]==RED && cube[34]==GREEN){
        solution->append("LLKGDLLAJKLL");
        return copy.rotation("LLKGDLLAJKLL");
    }
    if(cube[43]==GREEN && cube[12]==ORANGE){
        solution->append("JJKLCJJFIKJJ");
        return copy.rotation("JJKLCJJFIKJJ");
    }
    if(cube[43]==GREEN && cube[34]==RED){
        solution->append("JJELCJJFIEJJ");
        return copy.rotation("JJELCJJFIEJJ");
    }
    copy.rotation("GGEIFGGCLEGG"); //sinon les 4 sont mal placées rotation aléatoire
    return copy.resolveCube(&(solution->append("GGEIFGGCLEGG")));
}

/* Algorithme Helper pour rendre plus rapide le brute force */
bool Cube::resolveFirst1Cross(QString* solution) {
    if(isResolveFirst1Cross()) return true;
    int min = nbPermuMax;
    *solution = gen(*this, "", 0, &min, &Cube::isResolveFirst1Cross).replace("1","");
    qDebug() << "genFirst1Cross()" << *solution;
    if(*solution=="") return false; // On a pas trouvé de solution
    return true;
}
bool Cube::resolveFirst2Cross(QString* solution) {
    if(isResolveFirst2Cross()) return true;
    int min = nbPermuMax;
    *solution = gen(*this, "", 0, &min, &Cube::isResolveFirst2Cross).replace("1","");
    qDebug() << "genFirst2Cross()" << *solution;
    if(*solution=="") return false; // On a pas trouvé de solution
    return true;
}
bool Cube::resolveFirst3Cross(QString* solution) {
    if(isResolveFirst3Cross()) return true;
    int min = nbPermuMax;
    *solution = gen(*this, "", 0, &min, &Cube::isResolveFirst3Cross).replace("1","");
    qDebug() << "genFirst3Cross()" << *solution;
    if(*solution=="") return false; // On a pas trouvé de solution
    return true;
}

/* Tests pour vérifier certaines conditions du cube */
bool Cube::isResolveFirstCross(){
    return (cube[1] == WHITE && cube[3] == WHITE && cube[5] == WHITE && cube[7] == WHITE && cube[28] == ORANGE
            && cube[23] == RED && cube[14] == BLUE && cube[37]==GREEN);
}

bool Cube::isResolveFirst1Cross(){
    if(cube[1] == WHITE && cube[23] == RED ) return true;
    if(cube[7] == WHITE && cube[28] == ORANGE) return true;
    if(cube[3] == WHITE && cube[14] == BLUE) return true;
    if(cube[5] == WHITE && cube[37] == GREEN) return true;
    return false;
}

bool Cube::isResolveFirst2Cross(){
    if(cube[1] == WHITE && cube[23] == RED && cube[7] == WHITE && cube[28] == ORANGE) return true;
    if(cube[1] == WHITE && cube[23] == RED && cube[3] == WHITE && cube[14] == BLUE) return true;
    if(cube[1] == WHITE && cube[23] == RED && cube[5] == WHITE && cube[37] == GREEN) return true;
    if(cube[7] == WHITE && cube[28] == ORANGE && cube[3] == WHITE && cube[14] == BLUE) return true;
    if(cube[7] == WHITE && cube[28] == ORANGE && cube[5] == WHITE && cube[37] == GREEN) return true;
    if(cube[3] == WHITE && cube[14] == BLUE && cube[5] == WHITE && cube[37] == GREEN ) return true;
    return false;
}

bool Cube::isResolveFirst3Cross(){
    if(cube[1] == WHITE && cube[23] == RED && cube[7] == WHITE && cube[28] == ORANGE && cube[5] == WHITE && cube[37] == GREEN) return true;
    if(cube[1] == WHITE && cube[23] == RED && cube[7] == WHITE && cube[28] == ORANGE && cube[3] == WHITE && cube[14] == BLUE) return true;
    if(cube[1] == WHITE && cube[23] == RED && cube[5] == WHITE && cube[37] == GREEN && cube[3] == WHITE && cube[14] == BLUE) return true;
    if(cube[3] == WHITE && cube[14] == BLUE && cube[5] == WHITE && cube[37] == GREEN && cube[7] == WHITE && cube[28] == ORANGE) return true;
    if(cube[3] == WHITE && cube[14] == BLUE && cube[5] == WHITE && cube[37] == GREEN && cube[1] == WHITE && cube[23] == RED) return true;
    if(cube[3] == WHITE && cube[14] == BLUE && cube[7] == WHITE && cube[28] == ORANGE && cube[1] == WHITE && cube[23] == RED) return true;
    if(cube[28] == ORANGE && cube[1] == WHITE && cube[3] == WHITE && cube[14] == BLUE && cube[1] == WHITE && cube[23] == RED) return true;
    return false;
}

bool Cube::is8Corner() {
    return (cube[8]==WHITE && cube[36]==GREEN && cube[29] == ORANGE && isResolveFirstCross());
}

bool Cube::is6Corner() {
    return (cube[6]==WHITE && cube[27] == ORANGE && cube[17]==BLUE && isResolveFirstCross());
}

bool Cube::is0Corner() {
    return (cube[0] == WHITE && cube[11] == BLUE && cube[26] == RED && isResolveFirstCross());
}

bool Cube::is2Corner() {
    return (cube[2]==WHITE && cube[38] == GREEN && cube[20]==RED && isResolveFirstCross());
}
bool Cube::is8CornerBottom(){
    return (cube[15]==WHITE && cube[33]==GREEN && cube[51] == ORANGE && isResolveFirstCross());
}
bool Cube::is6CornerBottom(){
    return (cube[24]==WHITE && cube[9] == ORANGE && cube[53]==BLUE && isResolveFirstCross());
}
bool Cube::is0CornerBottom(){
    return (cube[44] == WHITE && cube[18] == BLUE && cube[47] == RED && isResolveFirstCross());
}
bool Cube::is2CornerBottom(){
    return (cube[35]==WHITE && cube[45] == GREEN && cube[42]==RED && isResolveFirstCross());
}

bool Cube::isResolveFirstFace() {
    for(int i=0; i <=8; i++) if(cube[i] != WHITE) return false;
    if(cube[26] != RED || cube[23] != RED || cube[20] != RED) return false;
    if(cube[11] != BLUE || cube[14] != BLUE || cube[17] != BLUE) return false;
    if(cube[27] != ORANGE || cube[28] != ORANGE || cube[29] != ORANGE) return false;
    if(cube[36] != GREEN || cube[37] != GREEN || cube[38] != GREEN) return false;
    return true;
}

bool Cube::isEdgeOrange(){
    if(cube[34]==ORANGE && cube[48] == BLUE && isResolveFirstFace()) return true;
    if(cube[34]==ORANGE && cube[48] == GREEN && isResolveFirstFace()) return true;
    return false;
}

bool Cube::isEdgeGreen(){
    if(cube[43]==GREEN && cube[46] == ORANGE && isResolveFirstFace()) return true;
    if(cube[43]==GREEN && cube[46] == RED && isResolveFirstFace()) return true;
    return false;
}

bool Cube::isEdgeRed(){
    if(cube[21]==RED && cube[50] == GREEN && isResolveFirstFace()) return true;
    if(cube[21]==RED && cube[50] == BLUE && isResolveFirstFace()) return true;
    return false;
}

bool Cube::isEdgeBlue(){
    if(cube[12]==BLUE && cube[52] == RED && isResolveFirstFace()) return true;
    if(cube[12]==BLUE && cube[52] == ORANGE && isResolveFirstFace()) return true;
    return false;
}

bool Cube::isResolveSecondEdgeOrange(){
    return (isResolveFirstFace() && cube[32]==ORANGE && cube[39]==GREEN && cube[30]==ORANGE && cube[16]==BLUE);
}

bool Cube::isResolveSecondEdgeGreen(){
    return (isResolveFirstFace() && cube[32]==ORANGE && cube[39]==GREEN && cube[41]==GREEN && cube[19]==RED);
}

bool Cube::isResolveSecondEdgeRed(){
    return (isResolveFirstFace() && cube[41]==GREEN && cube[19]==RED && cube[25]==RED && cube[10]==BLUE);
}
bool Cube::isResolveSecondEdgeBlue(){
    return (isResolveFirstFace() && cube[10]==BLUE && cube[25]==RED && cube[16]==BLUE && cube[30]==ORANGE);
}

bool Cube::isResolveSecondEdge(){
    return isResolveSecondEdgeOrange() && isResolveSecondEdgeGreen() && isResolveSecondEdgeRed() && isResolveSecondEdgeBlue();
}

bool Cube::isResolveThirdCross() {
    return (cube[48]==YELLOW && cube[46]==YELLOW && cube[50]==YELLOW && cube[52]==YELLOW);
}

bool Cube::isResolveThirdEdge(){
    for(int i =45; i < 54; i++) if(cube[i] != YELLOW) return false;
    return true;
}

bool Cube::is2CornerThirdEdge(){
    if(cube[51]==YELLOW && cube[45] == YELLOW) return true;
    if(cube[51]==YELLOW && cube[47] == YELLOW) return true;
    if(cube[51]==YELLOW && cube[53] == YELLOW) return true;
    if(cube[45]==YELLOW && cube[47] == YELLOW) return true;
    if(cube[45]==YELLOW && cube[53] == YELLOW) return true;
    if(cube[47]==YELLOW && cube[53] == YELLOW) return true;
    return false;
}

bool Cube::isResolveThirdEdgeCorner(){
    return (isResolveThirdEdge() && cube[35]==ORANGE && cube[33]==ORANGE && cube[42]==GREEN && cube[44]==GREEN && cube[18]==RED && cube[24]==RED && cube[9]==BLUE);
}

bool Cube::isResolve(){
    int i = 0;
    for(; i<9;  i++) if(cube[i] != WHITE) return false;
    for(; i<18; i++) if(cube[i] != BLUE)  return false;
    for(; i<27; i++) if(cube[i] != RED)   return false;
    for(; i<36; i++) if(cube[i] != ORANGE)return false;
    for(; i<45; i++) if(cube[i] != GREEN) return false;
    for(; i<54; i++) if(cube[i] != YELLOW)return false;
    return true;
}

void Cube::restart(){
    int i = 0;
    for(; i<9;  i++)cube[i] = WHITE;
    for(; i<18; i++)cube[i] = BLUE;
    for(; i<27; i++)cube[i] = RED;
    for(; i<36; i++)cube[i] = ORANGE;
    for(; i<45; i++)cube[i] = GREEN;
    for(; i<54; i++)cube[i] = YELLOW;
    rotationCount = 0;
}

#ifndef LISTE_H
#define LISTE_H
#include <string>

typedef struct noeud {
    int info;
    struct noeud* succ;
}noeud;

typedef struct maillon {
        noeud* info;
        struct maillon* succ;
} maillon;
typedef maillon* liste;

noeud* listecc(int n, int* t);
liste listePermutations(int n, ...);
bool deleteListePermutations(liste* l);
void detruire(noeud** l);
#endif // LISTE_H

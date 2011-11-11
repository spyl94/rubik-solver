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

/**
 * Représente une liste sous forme d'une chaîne de caractères. La liste peut
 * être linéaire ou circulaire.
 *
 * Parametre l : liste a représenter.
 *
 * Retourne : la chaîne représentant l.
 */
std::string chainel(liste l);
std::string chainesl(noeud* l);


/**
 * Convertit un tableau d'entiers en une liste chainee, simplement circulaire.
 *
 * Parametre n : le nombre d'elements de t.
 * Parametre t : tableau d'entiers a convertir.
 *
 * Retourne : la liste equivalente a t.
 */
noeud* listecc(int n, int* t);
/**
 * Convertit plusieurs tableaux d'entier en une liste chainee simplement chainée de liste chainée circulaire
 *
 * Parametre n : le nombre d'elements de t.
 * Parametres : tableaux d'entiers de taille 4 à insérer.
 *
 * Retourne : la liste.
 */
liste listePermutations(int n, ...);

#endif // LISTE_H

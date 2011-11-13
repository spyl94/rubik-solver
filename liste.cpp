/******************************************************************************
  MANIPULATION DE LISTES
 ******************************************************************************/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <cstdarg>
#include <QDebug>

#include "liste.h"
using namespace std;

/**
 * Représente une liste sous forme d'une chaîne de caractères. La liste peut
 * être linéaire ou circulaire.
 *
 * Parametre l : liste a représenter.
 *
 * Retourne : la chaîne représentant l.
 */
string chainel(liste l) {
        if (l == NULL) {
                return ".";
        }
        ostringstream r;
        maillon* c = l;
        do {
                r << "[" << c->info->info << "]";
                if (c->succ == NULL || c->succ == l) {
                    break;
                }
                r << "->";
                c = c->succ;
        } while (true);
        r << (c->succ == NULL ? "|" : ">");
        return r.str();
}

/**
 * Représente une liste sous forme d'une chaîne de caractères. La liste peut
 * être linéaire ou circulaire.
 *
 * Parametre l : liste a représenter.
 *
 * Retourne : la chaîne représentant l.
 */
string chainesl(noeud* l) {
        if (l == NULL) {
                return ".";
        }
        ostringstream r;
        noeud* c = l;
        do {
                r << "[" << c->info << "]";
                if (c->succ == NULL || c->succ == l) {
                    break;
                }
                r << "->";
                c = c->succ;
        } while (true);
        r << (c->succ == NULL ? "|" : ">");
        return r.str();
}

/**
 * Convertit un tableau d'entiers en une liste chainee, simplement circulaire.
 *
 * Parametre n : le nombre d'elements de t.
 * Parametre t : tableau d'entiers a convertir.
 *
 * Retourne : la liste equivalente a t.
 */
noeud* listecc(int n, int* t) {
        if (t == NULL || n == 0) {
            return NULL;
        }
        noeud* m = new noeud;
        m->info = t[0];
        noeud* l = m;
        for (int i = 1; i < n; i++) {
                m->succ = new noeud;
                m->succ->info = t[i];
                m = m->succ;
        }
        m->succ = l;
        return l;
}

/**
 * Convertit plusieurs tableaux d'entier en une liste chainee simplement chainée de liste chainée circulaire
 *
 * Parametre n : le nombre d'elements de t.
 * Parametres : tableaux d'entiers de taille 4 à insérer.
 *
 * Retourne : la liste.
 */
liste listePermutations(int n, ...) {
    if(n==0) return NULL;
    va_list ap;
    va_start(ap, n);
    liste m = new maillon;
    liste l = m;
    for(int i = 0 ; i < n ; i++){ // pour chaqun des tableaux reçus...
        noeud* c = listecc(4, va_arg(ap, int*)); //on crée une sous liste chainée contenant les valeurs du tableau.
        m->info = c; // que l'on ajoute à notre liste simplemetn chainée.
        if(i < n-1) {
            m->succ = new maillon;
            m = m->succ;
        }
        else m->succ = NULL;
    }
    va_end(ap);
    return l;
}
/**
 * Supprime une liste chainée circulaire de noeuds.
 *
 * Parametre l : pointeur sur une adresse noeud.
 *
 */
void detruire(noeud** l) {
        if(l == NULL || *l == NULL) return;
        noeud* n = NULL;
        noeud* s = (*l);
        while((*l)->succ != s) {
            n = (*l);
            (*l) = (*l)->succ;
            delete(n);
        }
        delete *l;
}
/**
 * Supprime une liste chainée de liste chainée circulaire (noeuds).
 *
 * Parametre l : pointeur sur une liste.
 *
 * Retourne : (booléen)? Bonne exécution : Paramètre incorrect.
 */
bool deleteListePermutations(liste* l) {
        if (l == NULL) {  // si un parametre est incorrect
            return false;
        }
        while ((*l) != NULL) { // parcourrir la liste et liberer les maillons un a un
            maillon* s = (*l);
            (*l) = (*l)->succ;
            detruire(&(s->info)); // detruire la sous liste circulaire
            delete s;
        }
        return true;
}

#ifndef ARBRE_H
#define ARBRE_H
#include "liste.h"

typedef struct Noeud{
    unsigned int nb;
    char caractere;
    struct Noeud* Sad;
    struct Noeud* Sag;
}Noeud;

typedef struct List_Noeud{
    struct Noeud* noeud;
    struct List_Noeud* suiv;
}List_Noeud;

Noeud* Creer_Arbre_Huffman(Element* list);
Noeud* Convert_El_to_Noeud(Element* el);        
List_Noeud* Lier_2x_Noeud(Noeud* ab1, Noeud* ab2);   // ab1->nb >= ab2->nb
List_Noeud* Convert_List_Element_to_List_Noeud(Element* list);
void ecriture_dico_rec(Noeud* Ab, char* code, int i, FILE* dico);

Element* Minimum_List(List_Noeud** list,List_Noeud** list2);                  // determine minimum (nb) d'une liste et le supprime en le renvoyant

#endif
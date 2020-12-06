#ifndef DICO_H
#define DICO_H
#include "arbre.h"

typedef struct Noeud_Dico{
    char code[8];
    char caractere;
    struct Noeud_Dico* Sag;
    struct Noeud_Dico* Sad;
}Noeud_Dico;

void Creation_Dico(Noeud2* Ab_Huffman, Noeud_Dico** dico);
void print_tree_dico(Noeud_Dico* tree);
void Codage_Texte(Noeud_Dico* dico, char* nom_txt);

void free_tree_dico(Noeud_Dico* dico);

#endif
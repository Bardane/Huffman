#ifndef ARBRE_H
#define ARBRE_H

typedef struct Noeud{
    unsigned int nb;
    struct Lettre* caractere;
    struct Noeud* Sad;
    struct Noeud* Sag;
}Noeud;

typedef struct Noeud2{
    unsigned int nb;
    char caractere;
    struct Noeud2* Sad;
    struct Noeud2* Sag;
}Noeud2;

typedef struct Lettre{
    struct Lettre* suiv;
    char lettre;
}Lettre;

typedef struct List_Noeud{
    struct List_Noeud* suiv;
    unsigned int nb;
    struct Noeud2* noeud;
}List_Noeud;

void print_AB(Noeud2* ab);
void print_AVL(Noeud* ab);

Noeud* Convert_Occ_Txt_to_AVL(char* nom_txt);
Noeud2* Creer_Ab_Huffman_opti(Noeud** Ab_occ);

void free_Ab(Noeud2* Ab);

#endif
#ifndef LISTE_H
#define LISTE_H

typedef struct Element{
    char caractere;
    unsigned int nb;
    struct Element* suiv;
}Element;

Element* Occ_txt(char* nom_txt);                        // ajout de tous les caractere dans une liste avec son nombre d'occurences exo 2.1
void Ajouter_occ_List(Element** list, char caractere);  // ajout caractere dans une liste d'occurences 
void Ajouter_List(Element** list, char caractere);      // création list / ajout Element en fin de liste
int presence_char(Element* list, char caractere);       // présence 1: oui 0: non
void affich_List(Element* l);

#endif
#include <stdio.h>
#include <stdlib.h>
#include "fonctions.h"
#include "liste.h"
#include "arbre.h"

int main(){
    printf("DEBUT\n");

    char* nom_txt = "texte_test";

    // Exo Partie 1 , A

    Conv_txt_to_bin(nom_txt);

    // Exo Partie 1 , B

    printf("\nLe texte %s possede %d caracteres",nom_txt,Nb_char_txt(nom_txt));

    // Exo Partie 2 , C

    Element* list = Occ_txt(nom_txt);

    affich_List(list);

    // Exo Partie 2 , D  (En phase de test)

    
    Noeud* Ab = Creer_Arbre_Huffman(list);

    char code[8] = {'\0'};
    FILE* dico = fopen("dico.txt", "w");
    ecriture_dico_rec(Ab,code,0,dico);


    
    printf("\nFIN");
}
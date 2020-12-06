#include <stdio.h>
#include <stdlib.h>
#include "dico.h"
#include "arbre.h"

void print_Title(){
    printf("#######                  #####                                                                   \n   #     #    #  #####  #     #   ####   #    #  #    #  ######  #####   #####  ######  #####    \n   #      #  #     #    #        #    #  ##   #  #    #  #       #    #    #    #       #    #   \n   #       ##      #    #        #    #  # #  #  #    #  #####   #    #    #    #####   #    #   \n   #       ##      #    #        #    #  #  # #  #    #  #       #####     #    #       #####    \n   #      #  #     #    #     #  #    #  #   ##   #  #   #       #   #     #    #       #   #    \n   #     #    #    #     #####    ####   #    #    ##    ######  #    #    #    ######  #    #   \n");
}

int menu(){
    printf("\nMENU :\n");
    printf("\n      1 - Compresser un fichier texte");
    printf("\n      2 - Quitter");
    printf("\n\nEntree : ");
    int input;
    scanf("%d",&input);
    return input;
}

int main(){

    print_Title();
    int input;
    char* nom_txt = malloc(sizeof(char)*264);

    do{

        input = menu();

        if (input == 1){
            do{
                printf("Entrez le nom du fichier sans ommettre  .txt : ");
            }while (scanf("%264s", nom_txt) != 1);

            int aff = -1;
            do{
                printf("Affichage Debug (Oui : 1 / Non : 0) : ");
                scanf("%d",&aff);
            }while (aff == -1);

            printf("\n OUVERTURE TEXTE (%s)",nom_txt);

            printf("\n\n RECHERCHE OCCURENCES...\n");

            Noeud* Ab_occ = Convert_Occ_Txt_to_AVL(nom_txt);
            if (aff == 1 ){
                printf("\ncaracteres par occurences :\n");
                print_AVL(Ab_occ);
            }
            
            printf("\n\n CREATION ARBRE HUFFMAN...\n");

            Noeud2* Ab_Huffman = Creer_Ab_Huffman_opti(&Ab_occ);
            if (aff == 1 ){
                print_AB(Ab_Huffman);
            }
            
            printf("\n\n CREATION DICO...\n");

            Noeud_Dico* dico = NULL;
            Creation_Dico(Ab_Huffman,&dico);
            if (aff == 1 ){
                print_tree_dico(dico);
            }
            

            printf("\n\n CODAGE TEXTE...\n");

            Codage_Texte(dico,nom_txt);

            free_tree_dico(dico);
            free_Ab(Ab_Huffman);

            printf("\n\n COMPRESSION TERMINEE\n");
        }
    }while (input != 2);
}
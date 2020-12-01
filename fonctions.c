#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "fonctions.h"

unsigned int* Conv_char_to_bin(char caractere){
    unsigned int* bin = malloc(sizeof(int)*8);
    for(int n=0 ; n<8 ; n++){
        bin[7-n] = caractere % 2;
        caractere /= 2;
    }
    return bin;
}

void Conv_txt_to_bin(char* nom_txt){
    FILE* texte = NULL;
    texte = fopen(nom_txt,"r");
    char caractere = fgetc(texte);
    while(caractere != EOF){
        unsigned int* bin = Conv_char_to_bin(caractere);
        printf("\n");
        for(int i=0;i<8;i++){
            printf("%d",bin[i]);
        }
        caractere = fgetc(texte);
    }
    fclose(texte);
}

int Nb_char_txt(char* nom_txt){
    FILE* texte = NULL;
    texte = fopen(nom_txt,"r");
    int nbchar = 0;
    while(fgetc(texte) != EOF){
        nbchar++;
    }
    fclose(texte);
    return nbchar;
}


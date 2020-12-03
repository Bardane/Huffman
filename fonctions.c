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

void Decodage_txt(char* nomdico,char* nomaconv){
    FILE* dico_txt = fopen(nomdico,"r");
    FILE* encode = fopen(nomaconv,"r");

    FILE* decodage = fopen("decodage.txt","w");
    char* encour = (char*)malloc(20 * sizeof(char));
    int i = 0;
    while((char c = fgetc(dico_txt)) != EOF){
        encour[i] = c;
        char aecrire;
        if((aecrire = bintochar(encour,dico_txt)) != NULL){
            fputc(aecrire,dcodage);
            i = 0;
            free(encour);
            char* encour = (char*)malloc(20 * sizeof(char));
        }
        else{
            i++;
        }
    }

}

char bintochar(char* encour,FILE* dico_txt){
    void rewind(dico_txt);//on positionne le pointeur sur le debut du fichier
    char bin[20];
    while( (fscanf(dico_txt,"%s : %c",bin,&c))

    char c;
    do{
        fscanf(dico_txt,"%s : %c",bin,&c);
        if (strcmp(bin,encour) == 0){
            return c;
        }
        else{
            return NULL;
        }
    }

}

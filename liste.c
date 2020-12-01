#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

Element* Occ_txt(char* nom_txt){
    FILE* texte = NULL;
    Element* list = NULL;
    texte = fopen(nom_txt,"r");
    char caractere = fgetc(texte);
    while(caractere != EOF){
        Ajouter_occ_List(&list,caractere);
        caractere = fgetc(texte);
    }
    fclose(texte);
    return list;
}

void affich_List(Element* l){
    printf("\n");
    while(l!=NULL){
        printf(" %c : %d ->",l->caractere,l->nb);
        l=l->suiv;
    }
    printf(" NULL");
}

int presence_char(Element* list, char caractere){
    //printf("\nTEST1-1\n");
    while (list != NULL){
        if (list->caractere == caractere){
            return 1;
        }
        else{
            list = list->suiv;
        }
    }
    return 0;
}

void Ajouter_List(Element** list, char caractere){
    //printf("\nTEST3\n");
    if ((*list) != NULL){
        Element* tmp = *list;
        while(tmp->suiv != NULL){
            tmp = tmp->suiv;
        }
        Element* tmp2 = malloc(sizeof(Element));
        tmp->suiv = tmp2;
        tmp2->caractere = caractere;
        tmp2->suiv = NULL;
        tmp2->nb = 1;
    }
    else{
        *list = malloc(sizeof(Element));
        (*list)->caractere = caractere;
        (*list)->suiv = NULL;
        (*list)->nb = 1;
    }
}

void Ajouter_occ_List(Element** list, char caractere){
    //printf("\nTEST1\n");
    if (presence_char((*list),caractere) == 0){
        //printf("\nTEST2\n");
        Ajouter_List(list,caractere);
    }
    else{
        Element* tmp = *list;
        while (tmp->caractere != caractere){
            tmp = tmp->suiv;
        }
        tmp->nb += 1;
    }
}



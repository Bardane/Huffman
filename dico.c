#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dico.h"

void reset(char* chaine, int taille){
    for (int i=0;i<taille;i++){
        chaine[i] = '\0';
    }
}

Noeud_Dico* create_node_dico(char caractere, char* code){
    Noeud_Dico* new_node = malloc(sizeof(Noeud_Dico));
    new_node->caractere = caractere;
    reset(new_node->code,8);
    strcpy(new_node->code,code);
    new_node->Sag = NULL;
    new_node->Sad = NULL;
    //printf("\n Noeud_Dico = %c :",new_node->caractere);
    int j=0;
    while (j<8 && new_node->code[j]!='\0'){
        //printf("%c",new_node->code[j]);
        j++;
    }
    return new_node;
}

void print_tree_dico(Noeud_Dico* tree){
    if (tree != NULL){
        //printf("\n TEST : (%c:",tree->caractere);
        printf(" \n%c(%d):",tree->caractere,tree->caractere);
        int j=0;
        while (j<8 && tree->code[j]!='\0'){
            printf("%c",tree->code[j]);
            j++;
        }
        if (tree->Sag == NULL){
            printf(" / ");
        }
        if (tree->Sad == NULL){
            printf(" / ");
        }
        print_tree_dico(tree->Sag);
        print_tree_dico(tree->Sad);
    }
}

void free_tree_dico(Noeud_Dico* tree){
    if(tree != NULL){
        free_tree_dico(tree->Sag);
        free_tree_dico(tree->Sad);
        free(tree);
    }
}

int depth_dico(Noeud_Dico* tree){
    if(tree == NULL){
        return 0;//Attention définition. -1 ou 0
    }
    else{
        int depth_left = depth_dico(tree->Sag);
        int depth_right = depth_dico(tree->Sad);
        if(depth_left > depth_right){
            return 1 + depth_left;
        }
        else{
            return 1 + depth_right;
        }
    }
}

void add_node_BST_dico(Noeud_Dico** tree, char caractere, char* code){
    if(*tree == NULL){
        *tree = create_node_dico(caractere, code);
    }
    else{
        if ((*tree)->caractere > caractere){
            add_node_BST_dico(&((*tree)->Sag) , caractere, code);
        }
        else if((*tree)->caractere < caractere){
            add_node_BST_dico(&((*tree)->Sad) , caractere, code);
        }
    }
}

int get_min_BST_perso_dico(Noeud_Dico* tree){// On peut s'autoriser des simplifications
    if (tree->Sag == NULL) return tree->caractere;
    else return get_min_BST_perso_dico(tree->Sag);
}

int bf_dico(Noeud_Dico* tree){
    if(tree == NULL) {
        return 0;
    }
    else{
        return depth_dico(tree->Sad) - depth_dico(tree->Sag);
    }
}

void right_rotation_dico(Noeud_Dico** tree){
    if (*tree != NULL){
        Noeud_Dico* temp = (*tree)->Sag;
        (*tree)->Sag = temp->Sad;
        temp->Sad = *tree;
        *tree = temp;
    }
}

void left_rotation_dico(Noeud_Dico** tree){
    if (*tree != NULL){
        Noeud_Dico* temp = (*tree)->Sad;
        (*tree)->Sad = temp->Sag;
        temp->Sag = *tree;
        *tree = temp;
    }
}

void balance_dico(Noeud_Dico** tree){
    if (*tree != NULL){
        balance_dico(&((*tree)->Sag));// Postfix
        balance_dico(&((*tree)->Sad));
        
        int balance_factor = bf_dico(*tree);
        if (balance_factor <= -2){// Cas Gauche - ??
            if(bf_dico((*tree)->Sag) > 0){// Gauche - Droite
                left_rotation_dico(&((*tree)->Sag));
            }
            right_rotation_dico(tree);// Gauche - Gauche
        }
        else if (balance_factor >= 2){// Cas Droite - ??
            if(bf_dico((*tree)->Sad) < 0){// Droite - Gauche
                right_rotation_dico(&((*tree)->Sad));
            }
            left_rotation_dico(tree);// Droite - Droite
        }
    }
}

void add_node_AVL_dico(Noeud_Dico** tree, char caractere, char* code){
    add_node_BST_dico(tree, caractere, code);
    balance_dico(tree);
}

void creer_dico(Noeud2* Ab, Noeud_Dico** dico, char* code, int i){
    if (Ab != NULL){
        if (Ab->Sag == NULL && Ab->Sad == NULL){
            // creation noeud AVL_dico
            //printf("\n Creation Noeud : %c , ", Ab->caractere);
            int j=0;
            while (j<8 && code[j]!='\0'){
                //printf("%c",code[j]);
                j++;
            }
            add_node_AVL_dico( dico, Ab->caractere, code); 
        }
        else{
            char code_copy[8] = {'\0'};
            strcpy(code_copy,code);
            if (Ab->Sag != NULL){
                code[i] = '1';
                creer_dico(Ab->Sag, dico, code, i+1);
                code_copy[i] = '0';
                creer_dico(Ab->Sad, dico, code_copy, i+1);
            }

        }
    }
}

void ecriture_dico(Noeud_Dico* dico, FILE* Dico){
    //printf("\n ecriture_dico : %c :",dico->caractere);
    if (dico != NULL){
        fputc(dico->caractere,Dico);
        fputs(" : ",Dico);
        int j=0;
        while (j<8 && dico->code[j] != '\0'){
            fputc(dico->code[j],Dico); 
            j++;
        }
        fputc('\n',Dico);
        ecriture_dico(dico->Sag,Dico);
        ecriture_dico(dico->Sad,Dico);
    }
}

void Creation_Dico(Noeud2* Ab_Huffman, Noeud_Dico** dico){
    char code[8];
    reset(code,8);
    creer_dico( Ab_Huffman, dico, code, 0);
    FILE* Dico = fopen("dico.txt", "w");
    ecriture_dico(*dico,Dico);
    fclose(Dico);
}

void Codage_Texte(Noeud_Dico* dico, char* nom_txt){
    //printf("\nDEBUT CODAGE");
    if (dico != NULL){
        FILE* texte = fopen(nom_txt,"r");
        FILE* encodage = fopen("compressfile.bin","wb");
        Noeud_Dico* tmp;
        char caractere;
        while ((caractere = fgetc(texte)) != EOF){
            //printf("\ncaractere = %c",caractere);
            tmp = dico;
            while(caractere != tmp->caractere){
                if (caractere > tmp->caractere){
                    tmp = tmp->Sad;
                }
                else{
                    tmp = tmp->Sag;
                }
                //printf("\ncible = %c",dico->caractere);
            }
            fputs(tmp->code,encodage);
        }
        fclose(texte);
        fclose(encodage);
    }
    //printf("\nFIN CODAGE");
}

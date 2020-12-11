#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"

/**
 * \file arbre.c
 * \brief Programme de compresion de texte.
 * \author Arthur Arnaud Romain Theo
 * \version 0.2
 * \date 4 decembre 2001
 *
 */


void free_Ab(Noeud2* Ab){
    if (Ab==NULL){
        return;
    }
    free_Ab(Ab->Sag);
    free_Ab(Ab->Sad);
    free(Ab);
}

void free_List_Ab(List_Noeud* list){
    if (list != NULL){
        free_List_Ab(list->suiv);
        free(list);
    }
}

// AVL

Noeud* create_node(int val, char caractere){
    Noeud* new_noeud = (Noeud*)malloc(sizeof(Noeud));
    Lettre* new_lettre = (Lettre*)malloc(sizeof(Lettre));
    new_noeud->nb = val;
    new_noeud->Sag = NULL;
    new_noeud->Sad = NULL;
    new_noeud->caractere = new_lettre;
    new_lettre->lettre = caractere;
    new_lettre->suiv = NULL;
    return new_noeud;
}

void print_AVL(Noeud* ab){
    if(ab != NULL){
        int n=10;
        printf("%d : ", ab->nb);
        Lettre* tmp = ab->caractere;
        while(tmp != NULL && n!=0){
            printf(" %c(%d) ", tmp->lettre,10-n);
            tmp = tmp->suiv;
            n--;
        }
        print_AVL(ab->Sag);
        print_AVL(ab->Sad);
    }
    else{
        printf(" / ");
    }
}

void print_AB(Noeud2* ab){
    if(ab != NULL){
        printf(" %d", ab->nb);
        if (ab->Sag == NULL && ab->Sad == NULL){ printf("(%c)  ",ab->caractere);}
        print_AB(ab->Sag);
        print_AB(ab->Sad);
    }
    else{
        printf(" / ");
    }
}

void print_List_Noeud(List_Noeud* list){
    int i=0;
    while (list != NULL){
        printf("\n%d : ",i);
        print_AB(list->noeud);
        list = list->suiv;
        i++;
    }
}

int depth(Noeud* ab){
    if(ab == NULL){
        return 0;//Attention définition. -1 ou 0
    }
    else{
        int depth_left = depth(ab->Sag);
        int depth_right = depth(ab->Sad);
        if(depth_left > depth_right){
            return 1 + depth_left;
        }
        else{
            return 1 + depth_right;
        }
    }
}

void add_node_BST(Noeud** ab, char cible, int nb){
    if(*ab == NULL){
        *ab = create_node(nb,cible);
        //printf("\n TEST - affichage : ");
        //print_tree(*ab);
    }
    else{
        //printf("\n comparaison : %c (%d) et %c (%d)",(*ab)->caractere,(*ab)->caractere,cible,cible);
        if ((*ab)->nb > nb){
            add_node_BST(&((*ab)->Sad), cible, nb);
        }
        else if((*ab)->nb < nb){
            add_node_BST(&((*ab)->Sag), cible, nb);
        }
    }
}

int get_min_BST_perso(Noeud* ab){// On peut s'autoriser des simplifications
    if (ab->Sag == NULL) return ab->nb;
    else return get_min_BST_perso(ab->Sag);
}
 
int bf(Noeud* ab){
    if(ab == NULL) {
        return 0;
    }
    else{
        return depth(ab->Sad) - depth(ab->Sag);
    }
}

void right_rotation(Noeud** ab){
    if (*ab != NULL){
        Noeud* temp = (*ab)->Sag;
        (*ab)->Sag = temp->Sad;
        temp->Sad = *ab;
        *ab = temp;
    }
}

void left_rotation(Noeud** ab){
    if (*ab != NULL){
        Noeud* temp = (*ab)->Sad;
        (*ab)->Sad = temp->Sag;
        temp->Sag = *ab;
        *ab = temp;
    }
}

void balance(Noeud** ab){
    if (*ab != NULL){
        balance(&((*ab)->Sag));// Postfix
        balance(&((*ab)->Sad));
        
        int balance_factor = bf(*ab);
        if (balance_factor <= -2){// Cas Gauche - ??
            if(bf((*ab)->Sag) > 0){// Gauche - Droite
                left_rotation(&((*ab)->Sag));
            }
            right_rotation(ab);// Gauche - Gauche
        }
        else if (balance_factor >= 2){// Cas Droite - ??
            if(bf((*ab)->Sad) < 0){// Droite - Gauche
                right_rotation(&((*ab)->Sad));
            }
            left_rotation(ab);// Droite - Droite
        }
    }
}

void add_node_AVL(Noeud** ab, char cible, int nb){
    add_node_BST(ab, cible, nb);
    balance(ab);
}

void add_occ_AVL(Noeud** ab, char cible, int nb){
    if (*ab == NULL){
        add_node_AVL(ab,cible,1);
        //printf("\nAJOUT");
    }
    else{
        //print_tree(*ab);
        Noeud* tmp = *ab;
        while(tmp->Sag != NULL){
            tmp = tmp->Sag;
        }
        //if (tmp->caractere == NULL){printf("\nTEST - NULL");}
        //printf("\n TEST - tmp->caractere->lettre = %c",tmp->caractere->lettre);
        Lettre* new_lettre = malloc(sizeof(Lettre));
        new_lettre->lettre = cible;
        //if (tmp->caractere != NULL){printf("\n TEST : tmp->caractere->suiv->lettre = %c",tmp->caractere->suiv->lettre);}
        new_lettre->suiv = tmp->caractere;
        tmp->caractere = new_lettre;
    }
}

void transfert_Noeud_AVL(Noeud* Ab,Lettre* tmp,int nb){
    if (Ab != NULL){
        //printf("\n TEST - transfert");
        if (nb > Ab->nb){
            if (Ab->Sad != NULL){
                transfert_Noeud_AVL(Ab->Sad,tmp,nb);
            }
            else{
                Noeud* new_noeud = malloc(sizeof(Noeud));
                Ab->Sad = new_noeud;
                new_noeud->nb = nb;
                new_noeud->caractere = tmp;
                new_noeud->Sag = new_noeud->Sad = NULL;
            }
        }
        else if (nb < Ab->nb){
            if (Ab->Sag != NULL){
                transfert_Noeud_AVL(Ab->Sag,tmp,nb);
            }
            else{
                Noeud* new_noeud = malloc(sizeof(Noeud));
                Ab->Sag = new_noeud;
                new_noeud->nb = nb;
                new_noeud->caractere = tmp;
                new_noeud->Sag = new_noeud->Sad = NULL;
            }
        }
        else{   // Noeud trouvé
            //printf("\n TEST - Noeud trouve");
            tmp->suiv = Ab->caractere;
            Ab->caractere = tmp;
        }
    }
}

int presence_caractere(Noeud** Ab, char caractere, Lettre** transfert, int* nb){
    if (*Ab==NULL){
        //printf(" NULL ");
        return 0;
    }
    Lettre* prec = NULL;
    Lettre* list = (*Ab)->caractere;
    while (list != NULL && list->lettre != caractere){
        prec = list;
        list = list->suiv;
    }
    if (list != NULL){   // if Ab->caractere->lettre == caractere
        Lettre* tmp = list;
        int val = (*Ab)->nb;
        if (prec == NULL){
            (*Ab)->caractere = tmp->suiv;
            if ((*Ab)->caractere == NULL){
                // supprimer noeud;
                //printf("\nSuppression Noeud");
                if((*Ab)->Sag == NULL && (*Ab)->Sad == NULL){
                    //printf("\n option - 1");
                    free(*Ab);
                    *Ab = NULL;
                }
                else if ((*Ab)->Sad != NULL && (*Ab)->Sag == NULL){
                    //printf("\n option - 2");
                    Noeud* temp = *Ab;
                    *Ab = (*Ab)->Sad;
                    free(temp);
                }
                else if ((*Ab)->Sag != NULL && (*Ab)->Sad == NULL){
                    //printf("\n option - 3");
                    Noeud* temp = *Ab;
                    *Ab = (*Ab)->Sag;
                    free(temp);
                }
            }
        }
        else{
            prec->suiv = tmp->suiv;
            //printf("\n TEST - %c",tmp->suiv->lettre);
        }
        //printf("\n FIN"); 
        tmp->suiv = NULL;
        *transfert = tmp;
        *nb = val + 1;
        //printf("\ntransfert: %c vers %d",tmp->lettre,*nb);
        // recup tmp et transfert   noeud : (Ab->nb) + 1
        return 1;
    }
    else{
        return presence_caractere(&((*Ab)->Sag),caractere,transfert,nb) + presence_caractere(&((*Ab)->Sad),caractere,transfert,nb);
    }
}

Noeud* Convert_Occ_Txt_to_AVL(char* nom_txt){ 

    FILE* texte = NULL;
    Noeud* Arbre_occ = NULL;
    texte = fopen(nom_txt,"r");
    char caractere = fgetc(texte);
    int nb;
    Lettre* transfert;
    while(caractere != EOF){
        //printf("\n\ncaractere : %c",caractere);
        if (presence_caractere(&Arbre_occ,caractere,&transfert,&nb)==0){
            //printf("\n%c pas present",caractere);
            //print_AVL(Arbre_occ);
            add_occ_AVL(&Arbre_occ, caractere, 1);
        }
        else{
            //printf("\n%c present",caractere);
            //printf("\ntransfert: %c vers %d - arbre avc val supp :",transfert->lettre,nb);
            //print_AVL(Arbre_occ);
            transfert_Noeud_AVL(Arbre_occ, transfert, nb);
        }
        balance(&Arbre_occ);

        //printf("\n Affichage test : ");
        //print_tree(Arbre_occ);
        //printf("\n fin affichage test ");
        caractere = fgetc(texte);
    }
    fclose(texte);
    return Arbre_occ;
    
}

int nb_minimum_AVL(Noeud* Ab){
    while(Ab->Sag != NULL){
        Ab = Ab->Sag;
    }
    return Ab->nb;
    
}

Noeud2* Minimum_AVL(Noeud** Avl){
    //printf("\nRECHERCHE minimum");
    if (*Avl == NULL){
        return NULL;
    }
    Noeud* prec = NULL;
    Noeud* tmp = *Avl;
    while (tmp->Sag != NULL){
        prec = tmp;
        tmp = tmp->Sag;
    }
    // recup Lettre* :
    char lettre = tmp->caractere->lettre;
    int nb = tmp->nb;
    Lettre* k = tmp->caractere;
    tmp->caractere = tmp->caractere->suiv;
    free(k);
    // suppression Noeud si Ab->caractere == NULL : 
    if (tmp->caractere == NULL){
        //printf("\n TEST - liste caractere vide");
        if (tmp->Sad != NULL){
            if (prec != NULL) {
                prec->Sag = tmp->Sad;
                //printf("\n opt - 1");
            }
            else{
                *Avl = tmp->Sad;
                //printf("\n opt - 2");
            }
            //tmp->Sad = NULL;
        }
        else{
            if (prec != NULL){
                prec->Sag = NULL;
                //printf("\n opt - 3");
            }
            else{
                *Avl = NULL;
                //printf("\n opt - 4");
            }
        }
        free(tmp);
    }
    // creation Noeud* à partir lettre :
    Noeud2* new_noeud = malloc(sizeof(Noeud2));
    new_noeud->nb = nb;
    new_noeud->caractere = lettre;
    //printf("\n AVL_noeud : %c",lettre);
    new_noeud->Sag = new_noeud->Sad = NULL;
    return new_noeud;
}

int Nombre_Noeud(List_Noeud* Ab, Noeud* AVL){
    // si nb elements >= 2 => =1 sinon , =2
    int n = 0;
    if (AVL != NULL){
        n += 1;
        if (AVL->Sag != NULL){
            n++;
        }
        if (AVL->Sad != NULL){
            n++;
        }
    }
    //printf("\n TEST 1 - n : %d", n);
    while(n < 2 && Ab != NULL){
        n++;
        Ab = Ab->suiv;
    }
    //printf("\n TEST 2 - n : %d", n);
    if (n >= 2){
        return 1;
    }
    else{
        return 0;
    }
}

int nb_minimum_List_Noeud(List_Noeud* list){
    if (list==NULL){
        return 0;
    }
    while (list->suiv != NULL){
        list = list->suiv;
    }
    return list->noeud->nb;
}

Noeud2* Minimum_List_Noeud(List_Noeud** list){
    if (*list == NULL){
        return NULL;
    }
    //AFFICHAGE
    //printf("\n\nAffichage AV: ");
    List_Noeud* test = *list;
    while (test!=NULL){
        //printf(" %d ->",test->nb);
        test = test->suiv;
    }
    //printf(" NULL");
    //FIN AFFICHAGE
    List_Noeud* prec = NULL;
    List_Noeud* tmp = *list;
    Noeud2* cible;
    while (tmp->suiv != NULL){
        prec = tmp;
        tmp = tmp->suiv;
    }
    //printf("\n cible tmp = %d",tmp->nb);
    if (prec == NULL){
        //printf("\nprec == NULL");
        *list = NULL;
    }
    else{
        //printf("\nprec != NULL : %d",prec->nb);
        prec->suiv = NULL;
    }
    cible = tmp->noeud;
    free(tmp);
    //AFFICHAGE
    //printf("\nAffichage AP: ");
    test = *list;
    while (test!=NULL){
        //printf(" %d ->",test->nb);
        test = test->suiv;
    }
    //printf(" NULL\n\n");
    //FIN AFFICHAGE
    //printf("\n>List_noeud : nb_el : %d",Nombre_Noeud(*list));
    return cible;
}

Noeud2* Global_Minimum(List_Noeud** list,Noeud** avl){
    int min1 = -1;
    int min2 = -1;
    if (*avl != NULL){
        min1 = nb_minimum_AVL(*avl);
        //printf("\n>AVL non nul : min1 = %d",min1);   
    }
    if (*list != NULL){
        min2 = nb_minimum_List_Noeud(*list);
        //printf("\n>List_noeud non nul : min2 = %d ; nb_el : %d",min2,Nombre_Noeud(*list, *avl));
    }
    if (min2 != -1){
        if(min1 != -1){
            if (min1 < min2){
                //printf("\nrecherche AVL");
                return Minimum_AVL(avl);
            }else{
                //printf("\nrecherche List");
                return Minimum_List_Noeud(list);
            }
        }
        else{
            //printf("\nrecherche List");
            return Minimum_List_Noeud(list);
        }
    }
    else{
        //printf("\nrecherche AVL");
        return Minimum_AVL(avl);
    }
    //printf("\nERREUR");
}

void Lier_2x_Noeud(List_Noeud** list_noeud, Noeud2* ab1, Noeud2* ab2){    // ab2 = nb minimum par rapport à ab1
    List_Noeud* list = malloc(sizeof(List_Noeud));
    Noeud2* noeud_tmp = malloc(sizeof(Noeud2));
    noeud_tmp->Sag = ab1;
    noeud_tmp->Sad = ab2;
    list->nb = noeud_tmp->nb = ab1->nb + ab2->nb;
    //printf("\nfonction Lier_2x_Noeud : n1 : %d ; n2 : %d = %d",ab1->nb,ab2->nb,noeud_tmp->nb);
    list->noeud = noeud_tmp;
    list->suiv = *list_noeud;
    *list_noeud = list;
}

Noeud2* Creer_Ab_Huffman_opti(Noeud** Ab_occ){

    if (*Ab_occ == NULL){
        return NULL;
    }
    List_Noeud* list_noeud = NULL;
    Noeud2* noeud1;
    Noeud2* noeud2;
    Noeud2* tmp;
    while (Nombre_Noeud(list_noeud, *Ab_occ)==1){ //(*Ab_occ != NULL && ((*Ab_occ)->Sag != NULL || (*Ab_occ)->Sad != NULL)) || Nombre_Noeud(list_noeud)>1
        //printf("\n Affichage Ab_occ : ");
        //print_AVL(*Ab_occ);
        //printf("\n\nRECHERCHE MINIMUM");
        //printf("\n-----------noeud1----------------");
        noeud1 = Global_Minimum(&list_noeud,Ab_occ);
        //printf("\n-----------noeud2----------------");
        noeud2 = Global_Minimum(&list_noeud,Ab_occ);
        //printf("\n\n noeud1 : %d, noeud2 : %d",noeud2->nb,noeud1->nb);
        Lier_2x_Noeud(&list_noeud, noeud2, noeud1);
        //print_List_Noeud(list_noeud);
        //printf("\n CONDITION test : ");
        //printf("\n Nombre_Noeud : %d",Nombre_Noeud(list_noeud, *Ab_occ));
        //printf("\nFinBoucle");
    }
    //if (n==0){printf("\nBOUCLE INFINI !!");}
    //printf("\n\nFIN");

    return list_noeud->noeud;
}


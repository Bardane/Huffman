#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arbre.h"
#include "liste.h"

Noeud* Convert_El_to_Noeud(Element* el){
    Noeud* ab = malloc(sizeof(Noeud));
    ab->nb = el->nb;
    ab->caractere = el->caractere;
    ab->Sag = ab->Sad = NULL;
    return ab;
}

int Nombre_List_Noeud(List_Noeud* l){
    int n=0;
    while (l!=NULL){
        n++;
        l = l->suiv;
    }
    //printf("\nfonction Nombre_List_Noeud nb = %d",n);
    return n;
}

List_Noeud* supp(List_Noeud** l, List_Noeud* pt){
    //printf("\nNouvelle Boucle");
    //if (*l==NULL){printf("\nlist2 = NULL");}else{printf("\nlist2 != NULL");}
    if (*l != NULL){
        //printf("\nTEST - pt : %p ; cible : %p ;",*l,pt);
        if ((*l)==pt){
            List_Noeud *tmp = *l;
            *l = (*l)->suiv;
            tmp->suiv = NULL;
            return tmp;
            //printf("\nvalide");
        }
        return supp(&((*l)->suiv),pt);
    }
    //printf("\nSORTIE");
    return NULL;
    
}

Noeud* Minimum_List_Noeud(List_Noeud** list,List_Noeud** list2){
    //printf("\nfonction Minimum_List_Noeud");

    List_Noeud* tmp = *list2;                   // Recherche position minimum
    int nb_min = 0,provenance=1;
    char char_min = '\0';
    List_Noeud* address_pt = NULL;

    if (*list2 != NULL){
        tmp = *list2;
        nb_min = tmp->noeud->nb;
        address_pt = tmp;
        while (tmp != NULL){        
            if (nb_min > tmp->noeud->nb){
                nb_min = tmp->noeud->nb;
                address_pt = tmp;
                provenance = 1;
            }
        tmp = tmp->suiv;
        }
    }
    if (*list2 == NULL && *list != NULL){
        tmp = *list;
        nb_min = tmp->noeud->nb;
        char_min = tmp->noeud->caractere;
        address_pt = tmp;
        tmp = tmp->suiv;
        provenance = 0;
    }

    //printf("\n -> Part 1 : nb_min = %d ",nb_min);

    if (*list != NULL){
        tmp = *list;
        while (tmp != NULL){        
            if (nb_min > tmp->noeud->nb){
                nb_min = tmp->noeud->nb;
                address_pt = tmp;
                char_min = tmp->noeud->caractere;
                //printf("add pt : %p",address_pt);
                provenance = 0;
            }
            tmp = tmp->suiv;
        }
    }

    //printf("\n -> Part 2 : nb_min = %d , char_min = .%c. , provenance = %d",nb_min,char_min,provenance);

    Noeud* temp = NULL;
    //if (*list2==NULL){printf("\nlist2 = NULL");}else{printf("\nlist2 != NULL");}
    if (provenance == 0){
        //printf("\n provenance 0");
        temp = supp(list,address_pt)->noeud;   // Suppression et récupération Element 
        
    }
    else{
        //printf("\n provenance 1");
        temp = supp(list2,address_pt)->noeud;   //else
    }
    return temp; 
}

List_Noeud* Convert_List_Element_to_List_Noeud(Element* list_el){
    if (list_el==NULL){
        return NULL;
    }
    List_Noeud* list_noeud = malloc(sizeof(List_Noeud));
    List_Noeud* tmp = list_noeud;
    Element* k;
    do{
        tmp->noeud = Convert_El_to_Noeud(list_el);
        k = list_el;
        list_el = list_el->suiv;
        free(k);
        if (list_el == NULL){
            tmp->suiv = NULL;
        }
        else{
            tmp = tmp->suiv = malloc(sizeof(List_Noeud));
        }  
    }while (list_el != NULL);
    
    return list_noeud;
}

List_Noeud* Lier_2x_Noeud(Noeud* ab1, Noeud* ab2){    // ab2 = nb minimum par rapport à ab1
    // printf("\nfonction Lier_2x_Noeud");
    List_Noeud* list = malloc(sizeof(List_Noeud));
    Noeud* noeud_tmp = malloc(sizeof(Noeud));
    noeud_tmp->Sag = ab1;
    noeud_tmp->Sad = ab2;
    noeud_tmp->nb = ab1->nb + ab2->nb;
    list->noeud = noeud_tmp;
    return list;
}

Noeud* Creer_Arbre_Huffman(Element* list){
    List_Noeud* list_noeud_feuilles = Convert_List_Element_to_List_Noeud(list);
    List_Noeud* list_noeud_pivot = NULL;
    if (list_noeud_feuilles == NULL){
        return NULL;
    }
    Noeud* noeud1;
    Noeud* noeud2;
    List_Noeud* tmp;
    while (Nombre_List_Noeud(list_noeud_pivot) + Nombre_List_Noeud(list_noeud_feuilles) >= 2){   //list_noeud_feuilles->suiv != NULL
        noeud1 = Minimum_List_Noeud(&list_noeud_feuilles,&list_noeud_pivot);
        noeud2 = Minimum_List_Noeud(&list_noeud_feuilles,&list_noeud_pivot);
        //printf("\nliaison : noeud1 : #%c#(%d) , noeud2 : #%c#(%d)\n",noeud1->caractere,noeud1->nb,noeud2->caractere,noeud2->nb);

        tmp = Lier_2x_Noeud(noeud2,noeud1);

        tmp->suiv = list_noeud_pivot;    // ajout à la liste
        list_noeud_pivot = tmp;
    }
    return list_noeud_pivot->noeud;
    
}

void ecriture_dico_rec(Noeud* Ab, char* code, int i, FILE* dico){
    if (Ab != NULL){
        
        if ((Ab->Sag == NULL)&&(Ab->Sad == NULL)){
            fputc(Ab->caractere,dico);
            fputs(" : ",dico);
            int j=0;
            printf("\n");
            printf("%c : ",Ab->caractere);
            while (j<8 && code[j]!='\0'){
                printf("%c",code[j]);
                fputc(code[j],dico); 
                j++;
            }
            fputc('\n',dico);
        }
        else{
            char tmp[8] = {'\0'};
            strcpy(tmp,code);
            code[i] = '1';
            ecriture_dico_rec(Ab->Sag,code,i+1,dico);
            tmp[i] = '0';
            ecriture_dico_rec(Ab->Sad,tmp,i+1,dico);
        }
    }
}

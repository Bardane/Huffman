#ifndef ARBRE_H
#define ARBRE_H
/**
 * \file arbre.h
 * \brief Structure et prototype en rapport avec la creation des AVL
 * \author Arthur Arnaud Romain Theo
 * \version 0.2
 * \date 4 decembre 2001
 */


/**
 * \struct Noeud
 * \brief AVL qui stock une Liste de char avec le meme nombre d occurence dans le texte
 *
 */
typedef struct Noeud{
    unsigned int nb;
    struct Lettre* caractere;
    struct Noeud* Sad;
    struct Noeud* Sag;
}Noeud;

/**
 * \struct Noeud2
 * \brief Arbre de Huffman
 *
 */
typedef struct Noeud2{
    unsigned int nb;
    char caractere;
    struct Noeud2* Sad;
    struct Noeud2* Sag;
}Noeud2;


/**
 * \struct Lettre
 * \brief Liste qui stock des char dans le but de creer le premier AVL
 *
 */
typedef struct Lettre{
    struct Lettre* suiv;
    char lettre;
}Lettre;

/**
 * \struct List_Noeud
 * \brief Liste qui stock des noeuds et permet la creation de l arbre de Huffman
 *
 */
typedef struct List_Noeud{
    struct List_Noeud* suiv;
    unsigned int nb;
    struct Noeud2* noeud;
}List_Noeud;

void free_Ab(Noeud2* Ab);
/**
 * \fn free_Ab(Noeud2* Ab)
 * \brief libere un arbre
 * 
 * \param pointeur/addrese de l arbre
 */

void free_List_Ab(List_Noeud* list);
/**
 * \fn free_List_Ab(List_Noeud* list)
 * \brief libere une liste d arbre
 * 
 * \param pointeur/addrese de la liste
 */

Noeud* create_node(int val, char caractere);
/**
 * \fn create_node(int val, char caractere)
 * \brief creer une feuille
 * 
 * \param int et char a ajouter dans le noeud et
 * \return un noeud avec sa valeur
 */

void print_AVL(Noeud* ab);
/**
 * \fn print_AVL(Noeud* ab)
 * \brief affiche un avl
 * 
 * \param pointeur/adresse de l AVL
 */

void print_AB(Noeud2* ab);
/**
 * \fn print_AB(Noeud2* ab)
 * \brief affiche un arbre
 * 
 * \param pointeur/adresse de l arbre
 */

void print_List_Noeud(List_Noeud* list);
/**
 * \fn print_List_Noeud(List_Noeud* list)
 * \brief affiche une liste de noeud
 * 
 * \param pointeur/adresse de la liste
 */

int depth(Noeud* ab);
/**
 * \fn depth(Noeud* ab)
 * \brief retourne la profondeur
 * 
 * \param noeud
 * \return un noeud avec sa valeur
 */

void add_node_BST(Noeud** ab, char cible, int nb);
/**
 * \fn add_node_BST(Noeud** ab, char cible, int nb)
 * \brief ajoute un noeud a un arbre de recherche
 * 
 */

int get_min_BST_perso(Noeud* ab);
/**
 * \fn get_min_BST_perso(Noeud* ab)
 * \brief trouve le min d'un arbre de recherche
 * 
 * \param pointeur/adresse d un arbre de recherche
 * \return le min d un arbre de recherche
 */

int bf(Noeud* ab);
/**
 * \fn bf(Noeud* ab)
 * \brief ?
 * 
 * \param pointeur/adresse d un AVL
 * \return ?
 */

void right_rotation(Noeud** ab);
/**
 * \fn right_rotation(Noeud** ab)
 * \brief ?
 * 
 * \param pointeur de pointeur d un AVL
 */

void left_rotation(Noeud** ab);
/**
 * \fn left_rotation(Noeud** ab)
 * \brief ?
 * 
 * \param pointeur de pointeur d un AVL
 */

void balance(Noeud** ab);
/**
 * \fn balance(Noeud** ab)
 * \brief ?
 * 
 * \param pointeur de pointeur d un AVL
 */

void add_node_AVL(Noeud** ab, char cible, int nb);
/**
 * \fn add_node_AVL(Noeud** ab, char cible, int nb)
 * \brief ajoute un Noeud a un AVL
 * 
 * \param int et char a ajouter dans le noeud et
 */

void add_occ_AVL(Noeud** ab, char cible, int nb);
/**
 * \fn add_occ_AVL(Noeud** ab, char cible, int nb)
 * \brief ajoute une occurence a un AVL si l occurence n existe pas elle est ajoutee
 * 
 * \param pointeur de pointeur d un AVL et char et int a ajouter
 */

void transfert_Noeud_AVL(Noeud* Ab,Lettre* tmp,int nb);
/**
 * \fn transfert_Noeud_AVL(Noeud* Ab,Lettre* tmp,int nb)
 * \brief ?
 * 
 * \param 

int presence_caractere(Noeud** Ab, char caractere, Lettre** transfert, int* nb);
/**
 * \fn presence_caractere(Noeud** Ab, char caractere, Lettre** transfert, int* nb)
 * \brief ?
 * 
 * \param int et char a ajouter dans le noeud et
 * \return un noeud avec sa valeur
 */

Noeud* Convert_Occ_Txt_to_AVL(char* nom_txt);
/**
 * \fn Convert_Occ_Txt_to_AVL(char* nom_txt)
 * \brief ?
 * 
 * \param int et char a ajouter dans le noeud et
 * \return un noeud avec sa valeur
 */

int nb_minimum_AVL(Noeud* Ab);
/**
 * \fn nb_minimum_AVL(Noeud* Ab)
 * \brief ?
 * 
 * \param int et char a ajouter dans le noeud et
 * \return un noeud avec sa valeur
 */

Noeud2* Minimum_AVL(Noeud** Avl);
/**
 * \fn Minimum_AVL(Noeud** Avl)
 * \brief ?
 * 
 * \param int et char a ajouter dans le noeud et
 * \return un noeud avec sa valeur
 */

int Nombre_Noeud(List_Noeud* Ab, Noeud* AVL);
/**
 * \fn Nombre_Noeud(List_Noeud* Ab, Noeud* AVL)
 * \brief ?
 * 
 * \param int et char a ajouter dans le noeud et
 * \return un noeud avec sa valeur
 */

int nb_minimum_List_Noeud(List_Noeud* list);
/**
 * \fn nb_minimum_List_Noeud(List_Noeud* list)
 * \brief ?
 * 
 * \param int et char a ajouter dans le noeud et
 * \return un noeud avec sa valeur
 */

Noeud2* Minimum_List_Noeud(List_Noeud** list);
/**
 * \fn Minimum_List_Noeud(List_Noeud** list)
 * \brief ?
 * 
 * \param int et char a ajouter dans le noeud et
 * \return un noeud avec sa valeur
 */

Noeud2* Global_Minimum(List_Noeud** list,Noeud** avl);
/**
 * \fn Global_Minimum(List_Noeud** list,Noeud** avl)
 * \brief ?
 * 
 * \param int et char a ajouter dans le noeud et
 * \return un noeud avec sa valeur
 */

void Lier_2x_Noeud(List_Noeud** list_noeud, Noeud2* ab1, Noeud2* ab2);
/**
 * \fn Lier_2x_Noeud(List_Noeud** list_noeud, Noeud2* ab1, Noeud2* ab2)
 * \brief ?
 * 
 * \param int et char a ajouter dans le noeud et
 */

Noeud2* Creer_Ab_Huffman_opti(Noeud** Ab_occ);
/**
 * \fn Creer_Ab_Huffman_opti(Noeud** Ab_occ)
 * \brief ?
 * 
 * \param int et char a ajouter dans le noeud et
 * \return un abre de Huffman
 */

#endif
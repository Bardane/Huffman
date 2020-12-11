#ifndef DICO_H
#define DICO_H
#include "arbre.h"
/**
 * \file dico.h
 * \brief Structure et prototype en rapport avec la creation du dictionnaire
 * \author Arthur Arnaud Romain Theo
 * \version 0.2
 * \date 4 decembre 2020
 */

/**
 * \struct Noeud_Dico
 * \brief AVL qui stock un char et son code ASCII.
 *
 */
typedef struct Noeud_Dico{
    char code[8];
    char caractere;
    struct Noeud_Dico* Sag;
    struct Noeud_Dico* Sad;
}Noeud_Dico;

void reset(char* chaine, int taille);


Noeud_Dico* create_node_dico(char caractere, char* code);


void print_tree_dico(Noeud_Dico* tree);


void free_tree_dico(Noeud_Dico* tree);


int depth_dico(Noeud_Dico* tree);


void add_node_BST_dico(Noeud_Dico** tree, char caractere, char* code);


int get_min_BST_perso_dico(Noeud_Dico* tree);


int bf_dico(Noeud_Dico* tree);

void right_rotation_dico(Noeud_Dico** tree);


void left_rotation_dico(Noeud_Dico** tree);


void balance_dico(Noeud_Dico** tree);


void add_node_AVL_dico(Noeud_Dico** tree, char caractere, char* code);


void creer_dico(Noeud2* Ab, Noeud_Dico** dico, char* code, int i);
/**
 * \fn creer_dico(Noeud2* Ab, Noeud_Dico** dico, char* code, int i)
 * \brief creer un AVL classé par code ASCII
 */

void ecriture_dico(Noeud_Dico* dico, FILE* Dico);
/**
 * \fn ecriture_dico(Noeud_Dico* dico, FILE* Dico)
 * \brief creer le fichier dico.txt
 */

void Creation_Dico(Noeud2* Ab_Huffman, Noeud_Dico** dico);
/**
 * \fn Creation_Dico(Noeud2* Ab_Huffman, Noeud_Dico** dico)
 * \brief centralise creer et ecriture
 */

void Codage_Texte(Noeud_Dico* dico, char* nom_txt);
/**
 * \fn Codage_Texte(Noeud_Dico* dico, char* nom_txt)
 * \brief code le texte envoye en parametre avec le dictionaire en parametre 
 */

#endif

#ifndef DICO_H
#define DICO_H
#include "arbre.h"
/**
 * \file dico.h
 * \brief Structure et prototype en rapport avec la creation du dictionnaire
 * \author Arthur Arnaud Romain Theo
 * \version 0.2
 * \date 4 decembre 2001
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
/**
 * \fn reset(char* chaine, int taille)
 * \brief reset une chaine de char
 * 
 * \param la chaine a reset et sa taille
 */

Noeud_Dico* create_node_dico(char caractere, char* code);
/**
 * \fn create_node_dico(char caractere, char* code)
 * \brief ?
 * 
 * \param ?
 * \return ?
 */

void print_tree_dico(Noeud_Dico* tree);
/**
 * \fn print_tree_dico(Noeud_Dico* tree)
 * \brief ?
 * 
 * \param ?
 */

void free_tree_dico(Noeud_Dico* tree);
/**
 * \fn free_tree_dico(Noeud_Dico* tree)
 * \brief ?
 * 
 * \param ?
 */

int depth_dico(Noeud_Dico* tree);
/**
 * \fn depth_dico(Noeud_Dico* tree)
 * \brief ?
 * 
 * \param ?
 * \return ?
 */

void add_node_BST_dico(Noeud_Dico** tree, char caractere, char* code);
/**
 * \fn add_node_BST_dico(Noeud_Dico** tree, char caractere, char* code)
 * \brief ?
 * 
 * \param ?
 */

int get_min_BST_perso_dico(Noeud_Dico* tree);
/**
 * \fn get_min_BST_perso_dico(Noeud_Dico* tree)
 * \brief ?
 * 
 * \param ?
 * \return ?
 */

int bf_dico(Noeud_Dico* tree);
/**
 * \fn bf_dico(Noeud_Dico* tree)
 * \brief ?
 * 
 * \param ?
 * \return ?
 */

void right_rotation_dico(Noeud_Dico** tree);
/**
 * \fn right_rotation_dico(Noeud_Dico** tree)
 * \brief ?
 * 
 * \param ?
 */

void left_rotation_dico(Noeud_Dico** tree);
/**
 * \fn left_rotation_dico(Noeud_Dico** tree)
 * \brief ?
 * 
 * \param ?
 */

void balance_dico(Noeud_Dico** tree);
/**
 * \fn balance_dico(Noeud_Dico** tree)
 * \brief ?
 * 
 * \param ?
 */

void add_node_AVL_dico(Noeud_Dico** tree, char caractere, char* code);
/**
 * \fn add_node_AVL_dico(Noeud_Dico** tree, char caractere, char* code)
 * \brief ?
 * 
 * \param ?
 */

void creer_dico(Noeud2* Ab, Noeud_Dico** dico, char* code, int i);
/**
 * \fn creer_dico(Noeud2* Ab, Noeud_Dico** dico, char* code, int i)
 * \brief ?
 * 
 * \param ?
 */

void ecriture_dico(Noeud_Dico* dico, FILE* Dico);
/**
 * \fn ecriture_dico(Noeud_Dico* dico, FILE* Dico)
 * \brief ?
 * 
 * \param ?
 */

void Creation_Dico(Noeud2* Ab_Huffman, Noeud_Dico** dico);
/**
 * \fn Creation_Dico(Noeud2* Ab_Huffman, Noeud_Dico** dico)
 * \brief ?
 * 
 * \param ?
 */

void Codage_Texte(Noeud_Dico* dico, char* nom_txt);
/**
 * \fn Codage_Texte(Noeud_Dico* dico, char* nom_txt)
 * \brief ?
 * 
 * \param ?
 */

#endif
#ifndef FONCTIONS_H
#define FONCTIONS_H

void Conv_txt_to_bin(char* nom_txt); // Affichage
unsigned int* Conv_char_to_bin(char caractere); 
int Nb_char_txt(char* nom_txt); 
void Decodage_txt(char* nomdico,char* nomaconv);
char bintochar(char* encour,FILE* dico_txt);

#endif

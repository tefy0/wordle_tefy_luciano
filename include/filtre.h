#ifndef FILTRE_H
#define FILTRE_H

#define MAX_WORDS 3000
#define WORD_LEN  5

int charger_mots(const char *fichier, char mots[][WORD_LEN + 1], int max);
int filtre_contient(char mots[][WORD_LEN + 1], int nb, char lettre, char resultat[][WORD_LEN + 1]);
int filtre_exclut(char mots[][WORD_LEN + 1], int nb, char lettre, char resultat[][WORD_LEN + 1]);
int filtre_position(char mots[][WORD_LEN + 1], int nb, char lettre, int position, char resultat[][WORD_LEN + 1]);
int filtre_substring(char mots[][WORD_LEN + 1], int nb, const char *sub, char resultat[][WORD_LEN + 1]);
void afficher_mots(char mots[][WORD_LEN + 1], int nb);

#endif

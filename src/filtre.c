#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "../include/filtre.h"

int charger_mots(const char *fichier, char mots[][WORD_LEN + 1], int max) {
    FILE *f = fopen(fichier, "r");
    if (!f) {
        printf("Erreur : impossible d'ouvrir %s\n", fichier);
        return 0;
    }
    int nb = 0;
    char token[256];
    while (fscanf(f, "%255s", token) == 1 && nb < max) {
        if (strlen(token) == WORD_LEN) {
            int valide = 1;
            for (int i = 0; i < WORD_LEN; i++)
                if (!isalpha(token[i])) { valide = 0; break; }
            if (valide) {
                for (int i = 0; i < WORD_LEN; i++)
                    mots[nb][i] = tolower(token[i]);
                mots[nb][WORD_LEN] = '\0';
                nb++;
            }
        }
    }
    fclose(f);
    return nb;
}

int filtre_contient(char mots[][WORD_LEN + 1], int nb, char lettre, char resultat[][WORD_LEN + 1]) {
    int count = 0;
    lettre = tolower(lettre);
    for (int i = 0; i < nb; i++)
        if (strchr(mots[i], lettre))
            strcpy(resultat[count++], mots[i]);
    return count;
}

int filtre_exclut(char mots[][WORD_LEN + 1], int nb, char lettre, char resultat[][WORD_LEN + 1]) {
    int count = 0;
    lettre = tolower(lettre);
    for (int i = 0; i < nb; i++)
        if (!strchr(mots[i], lettre))
            strcpy(resultat[count++], mots[i]);
    return count;
}

int filtre_position(char mots[][WORD_LEN + 1], int nb, char lettre, int position, char resultat[][WORD_LEN + 1]) {
    int count = 0;
    lettre = tolower(lettre);
    if (position < 0 || position >= WORD_LEN) return 0;
    for (int i = 0; i < nb; i++)
        if (mots[i][position] == lettre)
            strcpy(resultat[count++], mots[i]);
    return count;
}

int filtre_substring(char mots[][WORD_LEN + 1], int nb, const char *sub, char resultat[][WORD_LEN + 1]) {
    int count = 0;
    for (int i = 0; i < nb; i++)
        if (strstr(mots[i], sub))
            strcpy(resultat[count++], mots[i]);
    return count;
}

void afficher_mots(char mots[][WORD_LEN + 1], int nb) {
    printf("\n=== %d mot(s) restant(s) ===\n", nb);
    for (int i = 0; i < nb; i++)
        printf("%s\n", mots[i]);
    printf("\n");
}

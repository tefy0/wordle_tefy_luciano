#include <stdio.h>
#include <string.h>
#include "../include/filtre.h"

int main() {
    char mots[MAX_WORDS][WORD_LEN + 1];
    char resultat[MAX_WORDS][WORD_LEN + 1];
    int nb, nb_res;

    nb = charger_mots("ressource/bdd_wordle.txt", mots, MAX_WORDS);
    if (nb == 0) return 1;
    printf("Dictionnaire chargé : %d mots.\n", nb);

    for (int i = 0; i < nb; i++) strcpy(resultat[i], mots[i]);
    nb_res = nb;

    int choix;
    char lettre, sub[WORD_LEN + 1];
    int position;

    while (1) {
        printf("\n--- WORDLE SOLVER ---\n");
        printf("1. Contient une lettre\n");
        printf("2. Exclut une lettre\n");
        printf("3. Lettre a une position exacte\n");
        printf("4. Contient une sous-chaine\n");
        printf("5. Afficher les mots restants\n");
        printf("6. Reinitialiser\n");
        printf("0. Quitter\n");
        printf("Choix : ");
        scanf("%d", &choix);

        char temp[MAX_WORDS][WORD_LEN + 1];
        int nb_temp;

        switch (choix) {
            case 1:
                printf("Lettre : ");
                scanf(" %c", &lettre);
                nb_temp = filtre_contient(resultat, nb_res, lettre, temp);
                for (int i = 0; i < nb_temp; i++) strcpy(resultat[i], temp[i]);
                nb_res = nb_temp;
                printf("%d mots restants.\n", nb_res);
                break;
            case 2:
                printf("Lettre : ");
                scanf(" %c", &lettre);
                nb_temp = filtre_exclut(resultat, nb_res, lettre, temp);
                for (int i = 0; i < nb_temp; i++) strcpy(resultat[i], temp[i]);
                nb_res = nb_temp;
                printf("%d mots restants.\n", nb_res);
                break;
            case 3:
                printf("Lettre : ");
                scanf(" %c", &lettre);
                printf("Position (0 a 4) : ");
                scanf("%d", &position);
                nb_temp = filtre_position(resultat, nb_res, lettre, position, temp);
                for (int i = 0; i < nb_temp; i++) strcpy(resultat[i], temp[i]);
                nb_res = nb_temp;
                printf("%d mots restants.\n", nb_res);
                break;
            case 4:
                printf("Sous-chaine : ");
                scanf("%5s", sub);
                nb_temp = filtre_substring(resultat, nb_res, sub, temp);
                for (int i = 0; i < nb_temp; i++) strcpy(resultat[i], temp[i]);
                nb_res = nb_temp;
                printf("%d mots restants.\n", nb_res);
                break;
            case 5:
                afficher_mots(resultat, nb_res);
                break;
            case 6:
                for (int i = 0; i < nb; i++) strcpy(resultat[i], mots[i]);
                nb_res = nb;
                printf("Reinitialise. %d mots.\n", nb_res);
                break;
            case 0:
                printf("Au revoir !\n");
                return 0;
            default:
                printf("Choix invalide.\n");
        }
    }
}

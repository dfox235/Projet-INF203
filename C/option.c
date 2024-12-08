#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "options.h"


// Fonction pour afficher le message dans la bulle
void message(char *chaine){
    int len = strlen(chaine);
    printf(" ");
    // Boucle pour réaliser la ligne supérieure
    for (int i = 0; i < len + 2; i++) {
        printf("_");
    }
    printf(" \n");
    // affiche le texte entouré par ces deux caractères < >
    printf("< %s >\n", chaine);
    printf(" ");
    // Boucle pour réaliser la ligne inférieure
    for (int i = 0; i < len + 2; i++) {
        printf("-");
    }
    printf(" \n");
}

// Fonction pour afficher une vache
void affiche_vache(char* texte,char* yeux, char* queue, char* langue , int nb_vache) {
    message(texte); // Affiche le message dans la bulle avec le texte donné en argument
    // Affiche la vache (par défaut le nombre de vache est 1 et il y a pas d'option pour modifier cela donc on affiche toujours qu'une seule vache)
    for (int i=0;i<nb_vache;i++){ 
        printf("       \\    ^__^\n"
        "        \\   (%s)\\_______\n"
        "            (__)\\       )\\/\\%s\n"
        "             %s ||----w |\n"
        "                ||     ||\n", yeux, queue, langue);
    }
}

// Fonction pour gérer les options
int options(int argc, char* argv[]) {
    char yeux[3] = "oo";  // Yeux par défaut
    char langue[3] = "  "; // Langue par défaut
    char* queue = NULL; // Initialisation de la queue
    int nb_vache=1; // Nombre de vaches (par défaut une seule) non modifiable
    char texte[1000]; // Message à afficher par la vache
    strcpy(texte, argv[argc - 1]); // Copie le dernier argument dans texte
    // Si seul le message est donné, affiche une seule vache avec les paramètres par défaut
    if (argc==2){
          affiche_vache(texte,yeux, "", langue, nb_vache); 
    }
    // Si des options sont données
    else if (argc %2 == 0 ){
        // Parcourt toutes les options
        for (int i = 1; i < argc; i++) {
            if (strcmp(argv[i], "-e") == 0 || strcmp(argv[i], "--eyes") == 0) {  // Si l'option spécifie les yeux de la vache
                if (i + 1 < argc) {
                    strncpy(yeux, argv[i + 1], 2); 
                    yeux[2] = '\0'; 
                    i++;
                } else {
                    printf("Erreur : argument manquant pour l'option -e\n");
                    return 1;
                }
            } else if (strcmp(argv[i], "-T") == 0) {  // Si l'option spécifie la langue de la vache
                if (i + 1 < argc) {
                    strncpy(langue, argv[i + 1], 2); 
                    langue[2] = '\0'; 
                    i++;
                } else {
                    printf("Erreur : argument manquant pour l'option -T\n");
                    return 1;
                }
            } else if (strcmp(argv[i], "--tail") == 0) { // Si l'option spécifie la queue de la vache
                if (i + 1 < argc) {
                    int taille = atoi(argv[i + 1]); 
                    if (taille >= 0 && taille <= 9) {
                        // Allocation dynamique de la queue de la vache
                        queue = malloc(taille * 3 + 1); 
                        if (queue == NULL) {
                            printf("Erreur : échec de l'allocation de mémoire pour la queue\n");
                            return 1;
                        }
                        // Construction de la queue de la vache avec un boucle en fonction de l'entier entrer en argument apres le --tail
                        for (int j = 0; j < taille * 2; j += 2) {
                            queue[j] = '/';
                            queue[j + 1] = '\\';

                        }
                        queue[taille * 3] = '\0'; 
                        i++;
                    } else {
                        printf("Erreur : argument non compris entre 0 et 9 ou manquant pour l'option --tail\n ");
                    }
                }
            }
        }
        // Affichage de la vache avec les options spécifiées
        if (queue != NULL) { 
            affiche_vache(texte, yeux, queue, langue, nb_vache);
            free(queue);
        } else {
            affiche_vache(texte, yeux, "", langue, nb_vache); 
        }
    }
    // Si le nombre d'arguments est incorrect
    else {
        printf("Le nombre d'arguments est incorrecte!\n");
        return -1;
    }
return 0;

}   
#include <stdio.h>
#include <unistd.h>
#include <string.h>

// Fonction pour effacer l'écran
void clear_screen() {
    printf("\033[H\033[J"); 
}

// Fonction pour déplacer le curseur à la position spécifiée
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", x, y);
}

// Fonction pour afficher un message dans une bulle
void message(char *bubble) {
    int len = strlen(bubble);
    // Affichage de la ligne supérieure de la bulle
    gotoxy(1, 1);
    printf(" ");
    for (int i = 0; i < len + 2; i++) {
        printf("_");
    }
    printf(" \n");
    // Affichage du texte dans la bulle
    printf("< %s >\n", bubble);
    // Affichage de la ligne inférieure de la bulle
    printf(" ");
    for (int i = 0; i < len + 2; i++) {
        printf("-");
    }
    printf("\n"); 
}

// Fonction pour afficher la vache
void vache() {
    printf("        \\   ^__^\n"
           "         \\  (oo)\\_______\n"
           "            (__)\\       )\\/\\\n"
           "                ||----w |\n"
           "                ||     ||\n");
}

// Fonction pour lire et afficher le contenu d'un fichier avec une vache lisant
void reading_cow(FILE *file) {
    clear_screen(); // Efface l'écran
    char character;
    char bubble[100] = ""; // Initialise une chaîne de caractères pour la bulle de texte
    message(bubble); // Affiche la bulle vide
    vache(); // Affiche la vache
 
    int x_bouche = 7; // Position x de la bouche de la vache
    int y_bouche = 14; // Position y de la bouche de la vache
 
    // Boucle pour lire et afficher le contenu du fichier
    while ((character = fgetc(file)) != EOF) {
        if (character == '\n') {
            continue; // Ignore les caractères de nouvelle ligne
        }

        gotoxy(x_bouche, y_bouche); // Déplace le curseur à la position de la bouche de la vache
        printf(" "); // Efface le caractère précédent

        gotoxy(x_bouche, y_bouche); // Déplace le curseur à la position de la bouche de la vache
        printf("%c", character); // Affiche le caractère
        fflush(stdout);  // Vide le tampon de sortie
        sleep(1);   // Attend une seconde pour simuler la lecture
        
        int len = strlen(bubble);
        // Ajoute le caractère à la chaîne de caractères de la bulle
        bubble[len] = character;
        bubble[len + 1] = '\0';
        message(bubble); // Met à jour la bulle de texte avec le nouveau contenu
    }

    clear_screen(); // Efface l'écran
    message(bubble); // Affiche la bulle de texte final
    vache(); // Affiche la vache
}

// Fonction principale
int main(int argc, char *argv[]) {
    FILE *file;
    // Vérifie si le nombre d'arguments est correct
    if (argc != 2) {
        printf("Usage: ./a.out <fichier>\n");
        return 1;
    }
    // Ouvre le fichier en lecture
    file = fopen(argv[1], "r");
    if (!file) {
        perror("Problème sur le fichier entré en argument");
        return 1;
    }
    // Appelle la fonction pour lire et afficher le contenu du fichier avec la vache lisant
    reading_cow(file);
    
    fclose(file); // Ferme le fichier

    return 0;
}

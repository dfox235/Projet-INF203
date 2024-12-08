#include<stdio.h>
#include <unistd.h>
#include "options.h"
#include "wildcow.h"

// Efface l'écran
void update() {
    printf("\033[H\033[J");
}

// Déplace le curseur à la position spécifiée
void gotoxy(int x, int y) {
    printf("\033[%d;%dH", x, y);
}

// Affiche une chaîne de caractères à la position spécifiée
void print(int x, int y, const char* ch) {
    gotoxy(x,y);
    printf("%s",ch);
    fflush(stdout);
}

// Animation pour les yeux de la vache
void yeux(){
    for (int i =0; i < 4; i++)
    {
        print(5,14,"--");
        usleep(700000);
        print(5,14,"oo");
        usleep(700000);
    }
    gotoxy(0,0);
}

// Animation pour la langue de la vache
void langue(){
    for (int i =0; i <4 ;i++)
    {
        print(7,14," U");
        usleep(700000);
        print(7,14,"  ");
        usleep(700000);
    }
    gotoxy(0,0);

}

// Animation pour la vache se déplaçant vers l'arrière
void vachearriere(){
    char patte[50];
    int x=1;
    int y=0;
    
    for(int i=0;i<15;i++){
        int cpt=0;
        y++;
        while (cpt!=3){ 
            if (cpt==3){
                strcpy(&patte[0],"\\\\");
            }
            else if (cpt==2){
                strcpy(&patte[0],"||");
            }
            else {
                strcpy(&patte[0],"//");
            }
            gotoxy(4,y);
            printf("            ^__^\n");
            gotoxy(5,y);
            printf("            (oo)\\_______\n");
            gotoxy(6,y);
            printf("            (__)\\       )\\/\\\n");
            gotoxy(7,y);
            printf("                ||----w |\n");
            gotoxy(8,y);
            printf("                %s     %s\n",patte,patte);
            cpt++;
            usleep(70000);
            update();

            }
        }
    }

// Animation pour la vache marchant vers l'avant
void vachemarche(){
    char patte[50];
    int x=1;
    int y=15;
    
    for(int i=0;i<15;i++){
        int cpt=0;
        y--;
        while (cpt!=3){ 
            if (cpt==0){
                strcpy(&patte[0],"\\\\");
            }
            else if (cpt==1){
                strcpy(&patte[0],"||");
            }
            else {
                strcpy(&patte[0],"//");
            }
            gotoxy(4,y);
            printf("            ^__^\n");
            gotoxy(5,y);
            printf("            (oo)\\_______\n");
            gotoxy(6,y);
            printf("            (__)\\       )\\/\\\n");
            gotoxy(7,y);
            printf("                ||----w |\n");
            gotoxy(8,y);
            printf("                %s     %s\n",patte,patte);
            cpt++;
            usleep(70000);
            update();

            }
        }
    }

// Fonction pour faire marcher la vache
void marche(){
    vachemarche();

}


// Fonction principale
int main(int argc,char *argv[]) {
    update(); // Efface l'écran
    options(argc,argv); // Gestion des options
    yeux();  // Animation pour les yeux
    fflush(stdout);  // Nettoyage du flux de sortie
    update();  // Efface l'écran
    options(argc,argv); // Gestion des options
    langue(); // Animation pour la langue
    update(); // Efface l'écran
    vachearriere(); // Animation pour la vache se déplaçant vers l'arrière
    marche(); // Animation pour la vache marchant
    return 0;
}
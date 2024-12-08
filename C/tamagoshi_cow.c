#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "options.h"

// Définition des états de la vache
#define LIFEROCKS 2
#define LIFESUCKS 1
#define BYEBYELIFE 0

// Variables globales pour le stock et la forme physique de la vache
int stock = 5; 
int fitness = 5; 

// Fonction pour afficher la vache en fonction de son état
void affiche_vache1(int etat) {
    switch(etat) {
        case LIFEROCKS:
            affiche_vache("","oo", "","  ",1); 
            break;
        case LIFESUCKS:
            affiche_vache("","--", "","  ",1);
            break;
        case BYEBYELIFE:
            affiche_vache("","xx", "","  ",1); 
            break;
    }
}

// Fonction pour mettre à jour l'état de la vache
int maj_etat(int etat) {
    if (etat == LIFEROCKS) {
        if (((fitness >= 1 ) && (fitness <= 3))||((fitness  >= 7 ) && (fitness <= 9)))
            return LIFESUCKS;  // Si la forme physique est mauvaise
        else if ((fitness >= 4 ) && (fitness <= 6))
            return LIFEROCKS; // Si la forme physique est correcte
        else if (fitness <= 0)
            return BYEBYELIFE;  // Si la vache est morte de faim
        else if (fitness >= 10)
            return BYEBYELIFE; // Si la vache est morte de suralimentation

    } else if (etat == LIFESUCKS) {
        if (fitness >= 10)
            return BYEBYELIFE; // Si la vache est morte de suralimentation

        else if (fitness <= 0)
            return BYEBYELIFE;  // Si la vache est morte de faim

        else if (((fitness >= 1 ) && (fitness <= 3))||((fitness  >= 7 ) && (fitness <= 9)))
            return LIFESUCKS;  // Si la forme physique est mauvaise
        
        else
            return LIFEROCKS; // Si la forme physique est correcte
    }
    return etat;
}

// Fonction pour mettre à jour la forme physique de la vache
void fitness_update(int lunchfood, int digestion) {
    fitness = fitness + lunchfood + digestion;
    if (fitness < 0)
        fitness = 0; // Limite inférieure de la forme physique
    else if (fitness > 10)
        fitness = 10; // Limite supérieure de la forme physique
}

// Fonction pour mettre à jour le stock de nourriture de la vache
void stock_update(int lunchfood, int crop) {
    stock = stock - lunchfood + crop;
    if (stock < 0)
        stock = 0; // Limite inférieure du stock de nourriture
    else if (stock > 10)
        stock = 10; // Limite supérieure du stock de nourriture
}

int main() {
    srand(time(NULL)); // Initialisation pour la génération de nombres aléatoires

    int etat = LIFEROCKS; // État initial de la vache
    int duree_de_vie = 0;   // Initialisation du compteur de durée de vie
    int lunchfood, digestion, crop; // Initialisation des variables lunchfood, digestion, crop

    while (etat != BYEBYELIFE) { // Tant que la vache est en vie
       
        affiche_vache1(etat); // Affichage de l'état de la vache

     
        printf("Stock : %d\n", stock); // Affichage du stock de nourriture disponible

        // Demande de la quantité de nourriture à donner
        printf("Quantite de nourriture a donner (0-%d) : \n", stock);
        scanf("%d", &lunchfood);
        while (lunchfood < 0 || lunchfood > stock) {
            printf("Quantite invalide, veuillez entrer une valeur entre 0 et %d : \n", stock);
            scanf("%d", &lunchfood);
        }

        // Génération de valeurs aléatoires pour la digestion et la récolte
        digestion = -3 + rand() % 4; 
        crop = -3 + rand() % 7; 
        
        // Mise à jour de la forme physique et du stock de nourriture de la vache
        fitness_update(lunchfood, digestion);
        stock_update(lunchfood, crop);

        // Mise à jour de l'état de la vache en fonction de sa forme physique
        etat = maj_etat(etat);
        
        // Incrémentation de la durée de vie de la vache
        duree_de_vie++;
    }
    // Affichage de l'état final de la vache
    affiche_vache1(etat);
    // Affichage du score final (durée de vie)
    printf("Votre score final (duree de vie) est : %d\n", duree_de_vie);

    return 0;
}

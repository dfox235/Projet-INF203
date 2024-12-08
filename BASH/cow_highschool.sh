#!/bin/bash

# Ce script affiche les carrés des nombres de 1 à n avec cowsay.

clear
# Boucle pour calculer les carrés des nombres de 1 à n 
for (( i=1; i<=$1 ; i++ ))
do 
    carre=$(($i**2)) # Calcule le carré de la valeur actuelle de la boucle
    sleep 1 | cowsay $carre  # Utilise cowsay pour afficher le carré actuel
    clear  # Efface l'écran pour afficher le carré suivant
done
cowsay -T " U" "c'est fini"

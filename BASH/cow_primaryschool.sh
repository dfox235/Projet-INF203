#!/bin/bash

# Ce script affiche les nombres de 1 à n (un entier) avec cowsay.

clear 
# Boucle pour compter de 1 à n
for ((i=1 ; i<=$1 ; i++))
do 
    sleep 1 | cowsay $i
    clear # Efface l'écran pour afficher le nombre suivant
done
cowsay -T " U" "c'est fini"


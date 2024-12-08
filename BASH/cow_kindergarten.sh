#!/bin/bash 

# Ce script affiche les nombres de 1 à 10 en utilisant cowsay

clear
# Boucle pour compter de 1 à 10
for ((i=1 ; i<=10 ; i++))
do
    sleep 1 | cowsay $i # Utilise cowsay pour afficher le nombre actuel
    clear # Efface l'écran pour afficher le nombre suivant
done 
cowsay -T " U" "c'est fini"
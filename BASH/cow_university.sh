#!/bin/bash

# Ce script affiche les nombres tous les nombres premiers inférieur à l'entier entrer en argument 

clear
# Boucle pour tester les nombres premiers jusqu'au nombre spécifié par l'utilisateur
for ((i=1; i<$1 ; i++))
do
    compteur=0 # Initialisation du compteur de diviseurs
    # Boucle pour compter le nombre de diviseurs du nombre actuel
    for ((a=1; a<=$i ; a++))
    do
        if [ $(($i%$a)) -eq 0 ] # Test si $i est divisible par $a
        then 
            compteur=$(expr $compteur + 1) # Incrémente le compteur de diviseurs si c'est le cas

        fi
    done
    # Si le nombre de diviseurs est égal à 2, alors c'est un nombre premier
    if  [ $compteur -eq 2 ]
    then 
        sleep 1 | cowsay $i # Affiche le nombre premier
        clear # Efface l'écran pour afficher le prochain nombre
    fi
done
cowsay -T " U" "c'est fini"
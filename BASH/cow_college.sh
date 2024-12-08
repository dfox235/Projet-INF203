#!/bin/bash

# Ce script affiche les nombres tous les termes de la suite de Fibonacci inférieur à l'entier entrer en argument 

Un=0 # Initialisation du premier terme de la suite de Fibonacci
Un1=1 # Initialisation du deuxième terme de la suite de Fibonacci
clear

# Vérification si l'argument est inférieur ou égal à 0
if [ $1 -le 0 ]; then
    sleep 5 | cowsay "l'argument doit être strictement supérieur de 0 car il n'y a pas de terme inférieur à 0 dans la suite de Fibonacci "
else
    sleep 1 | cowsay "O" # Affiche le premier terme "0" de la suite
    clear
    # Vérification si le deuxième terme est inférieur à l'argument
    if (($Un1 < $1)); then
        sleep 1 | cowsay "$Un1"
        clear
    fi
    # Boucle pour calculer les termes suivants de la suite de Fibonacci
    for ((i=2; i<=$1; i++))
    do
        Un2=$(($Un1+$Un)) # Calcul du terme suivant
        if (($Un2 < $1)); then
            sleep 1 | cowsay "$Un2" # Affiche le terme suivant s'il est inférieur à l'argument
            clear
        else
            break # Sort de la boucle si le terme suivant est supérieur ou égal à l'argument
        fi
        Un=$Un1 # Mise à jour des valeurs pour le calcul des termes suivants
        Un1=$Un2
    done
fi

clear
cowsay -T " U" "c'est fini"
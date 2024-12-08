#!/bin/bash

# Ce script calcule et affiche le nombre d'or avec un nombre de décimales spécifié par l'utilisateur

# Vérifie si le nombre d'arguments est différent de 1
if [ $# -ne 1 ]; then
    echo "il faut un seul argument, un entier positif."
    exit 1
fi

# Vérifie si l'argument est un nombre entier positif
if [ $1 -lt 0 ]; then
    echo "L'argument doit être un nombre entier positif."
    exit 1
fi

# Calcul du nombre d'or avec le nombre de décimales spécifié par l'utilisateur
nb_or=$(echo "scale=$1; ((1+(sqrt(5)))/2)" | bc -l) # Formule du nombre d'or = ((1+(sqrt(5)))/2)

cowsay "Le nombre d'or avec $1 décimale(s) est : $nb_or " # Affichage du nombre d'or avec un message

# Affichage d'un message expliquant le lien entre le nombre d'or et la suite de Fibonacci
cowthink "D'ailleur il y a un lien entre le nombre d'or et le suite de 
Fibonacci vu précédement, car la limite de Fn/F(n-1) tend vers le nombre d'or 
quand n tend vers plus l'infini"
exit 0
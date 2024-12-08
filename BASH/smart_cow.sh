#!/bin/bash


# Ce script prend en argument un calcul ( par exemple:'3' + 11') entrer guillemet avec un espace entre chaque caractère 
# et affiche une vache qui prononce le calcul et dont les yeux se transforment en le résultat du calcul


# Sépare la chaîne en trois parties en utilisant l'espace comme délimiteur
part1=$(echo $1 | cut -d ' ' -f1) 
part2=$(echo $1 | cut -d ' ' -f2) 
part3=$(echo $1 | cut -d ' ' -f3) 

# Vérifie si le deuxième élément est une opération
if [ $part2 = '+' ]
    then result=$(expr $part1 + $part3)  # Effectue l'addition
        if [ $result -lt 10 ] 
        then cowsay -e $result" " $1 # Affiche le résultat avec un espace avant s'il est inférieur à 10 pour ne pas créer de décalage
        else 
            cowsay -e $result $1 # Sinon on affiche normalement
        fi

elif [ $part2 = '-' ]
    then result=$(expr $part1 - $part3) # Effectue la soustraction
        if [ $result -lt 10 ] 
        then cowsay -e $result" " $1 # Affiche le résultat avec un espace avant s'il est inférieur à 10 pour ne pas créer de décalage
        else 
            cowsay -e $result $1 # Sinon on affiche normalement
        fi

elif [ $part2 = "x" ]
    then 
        # Boucle pour effectuer la multiplication
        for (( i=0; i<$part3; i++ )); do
            result=$(expr $result + $part1)
        done
        if [ $result -lt 10 ] 
        then cowsay -e $result" " $1 # Affiche le résultat avec un espace avant s'il est inférieur à 10 pour ne pas créer de décalage
        else 
            cowsay -e $result $1 # Sinon on affiche normalement
        fi
        

elif [ $part2 = '/' ]
    then result=$(expr $part1 / $part3) # Effectue la division
        if [ $result -lt 10 ] 
        then cowsay -e $result" " $1 # Affiche le résultat avec un espace avant s'il est inférieur à 10 pour ne pas créer de décalage
        else 
            cowsay -e $result $1 # Sinon on affiche normalement
        fi

else
    # Affiche un message d'erreur si l'opération n'est pas reconnue et rappel quelles sont les bon symboles et les conditions d'utilisation
    echo "Erreur: le bon symbole pour l'addition est '+' "
    echo "        le bon symbole pour la soustraction  est '-' "
    echo "        le bon symbole pour la division est '/' "
    echo "        le bon symbole pour la multiplication est 'x' "
    echo "        il faut un espace entre chaque caractère ( par exemple:'3' + 11') "

fi




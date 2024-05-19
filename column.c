//Projet CDataframe
//Jade Brana et Clément Davenne
//Ce fichier comporte l'ensemple des fonctions pour les colonnes que contient notre CDataframe
//C'est grace à ce fichier que notre cdataframe peut contenir différentes colonne
//Chaque fonction du CDataframe.c est créer à partir de l'appel d'une de ces fonctions

#include <stdio.h>
#include <malloc.h>
#include "column.h"
#define MALLOC_SIZE 256

//création de colonne
COLUMN *create_column(char* title) { //On effectue un return car on renvoie les colonnes avec des valeurs du cdataframe
    COLUMN *col = (COLUMN *)malloc(sizeof(COLUMN));
    col->title = title; //Relie un titre à une colonne
    col->tl = 0; //Relie la colonne à une taille logique de 0
    col->tp = 0; //De meme mais avec la taille physique
    col->tab = NULL; //Initialise avec les colonnes un tableau de donnée vide
    return col; //Retourne la colonne
}

//Fonction permettant insèrer une valeur entière dans une colonne COLUMN
int insert_value(COLUMN* column, int value) {
    if (column->tab == NULL || column->tl >= column->tp) { //Regarde si le tableau est vide ou non
        //Augmentation du tableau
        int new_tp = column->tp + MALLOC_SIZE;
        int *new_tab = (int *)realloc(column->tab, new_tp * sizeof(int));
        column->tab = new_tab;
        column->tp = new_tp;
    }
    //Insère une valeur et augmente la taille logique
    column->tab[column->tl] = value;
    column->tl++;

    return 1;
}

//Fonction permettant de supprimer une colonne et de libérer de l'espace mémoire
void delete_column(COLUMN **col) { //Pas besoin de return, on supprime juste une colonne
    if (*col == NULL){
    free((*col)->title); //Libère de l'espace pour le titre
    free((*col)->tab); //Libère de l'espace pour le tableau de donnée (cdataframe)
    free(*col); //Libère des colonnes
    *col = NULL; //Remet la colonne vide
    }
}

//Fonction permettant d'afficher proprement les colonnes avec le titre de la colonne
void print_col(COLUMN* col){//Pas besoin de return car on affiche que les colonnes et qu'on ne cherche/renvoie pas de valeur
    printf("Titre de la colonne : %s\n", col->title); //Affichage du titre de la colonne
    printf("Contenu de la colonne :\n");
    for (int i = 0; i < col->tl; i++){
        printf("[%d] %d\n", i, col->tab[i]); //Affichage du contenue de la colonne
    }
}

//Fonction permettant de compter le nombre de fois ou apparait une valeur
int count_occurences(COLUMN *col, int value) { //Besoin d'un return car on compte le nombre de fois ou apparait une valeur
    int count = 0;
    for (int i = 0; i < col->tl; i++) { //Parcours les colonnes en fonction de la taille logique
        if (col->tab[i] == value) { //Si la valeur apparait
            count++; //Compteur +1
        }
    }
    return count; //Renvoie le nombre de fois qu'est apparue une valeur
}

//Fonction permettant l'affichage de la position d'une valeur
int value_position(COLUMN *col, int position) { //nous effectuons un return car nous devons renvoyer la valeur à partir d'une position
    if (position < 0 || position >= col->tl){ //Si la position n'est pas comprise entre 0 et la taille logique
        printf("Position invalide");
    }
    return col->tab[position]; // Renvoie la valeur à la position spécifiée dans la colonne.
}

//Fonction donnant les valeurs les plus haute à partir d'une valeur donnée
int more_value(COLUMN *col, int value) { //Besoin d'un return cat nous devons, à partir d'une valeur donnée, renvoyer le nombre de valeur plus grande que celle-ci dans le cdataframe
    int count = 0;
    for (int i=0; i<col->tl; i++){
        if (col->tab[i]>value) { //Chaque fois qu'il trouve une valeur plus grande:
            count++;//Compteur +1
        }
    }
    return count;//Retourne le nombre de valeur plus grande
}

//Fonction donnant les valeurs les plus basses à partir d'une valeur donnée
int less_value(COLUMN *col, int value) { //Besoin d'un return cat nous devons, à partir d'une valeur donnée, renvoyer le nombre de valeur plus petite que celle-ci dans le cdataframe
    int count=0;
    for (int i=0 ;i<col->tl; i++){ // parcours le tableau
        if (col->tab[i]<value){ //Chaque fois qu'il trouve une valeur plus petite:
            count++;//Compteur +1
        }
    }
    return count;//Renvoie le nombre de valeur plus petite
}

//Fonction donnant les valeurs égales à une valeur donnée
//Fonction équivalente à celle du comptage d'occurence mais sous un autre nom, nous l'avons quand meme utilisé par la suite
int equal_value(COLUMN *col, int value) {
    int count=0;
    for (int i=0 ;i<col->tl; i++){ //Cherche les valeurs égales à une valeur donnée,
        if (col->tab[i]==value){ // si trouvé :
            count++; //compteur +1
        }
    }
    return count;//Renvoie le nombre de valeur égales à une valeur donnée
}




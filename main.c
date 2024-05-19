//Projet CDataframe
//Jade Brana et Clément Davenne
//Ce fichier sert à l'interface utilisateur, il va permettre de faire fonctionner les fonctions que nous avons créée
//Il comporte toutes les fonctions créée dans le fichier CDataframe.c et initialiser dans le CDataframe.h

#include <stdio.h>
#include "column.h"
#include "CDataframe.h"
#include <stdlib.h>

int main() {
    //Initialisation du CDataframe vide
    CDATAFRAME *cdata = create_cdataframe();
    int begin = 1;
    while (begin){
        welcome(); //Fonction affichant le menu de bienvenue (initialiser dans le fichier cdataframe.c pour éviter d'avoir un main trop long)
        int choix;
        scanf("%d", &choix); //Permet le choix des différentes cases
        switch (choix){
            case 1:
                //Choix de la case hardware permettant d'avoir un cdataframe prérempli
                hardware_cdataframe(cdata);
                begin =0; //Permet de passer à la suite
                break;
            case 2:
                //Choix d'un cdataframe vide, à compléter avec les fonctionnalités présente après
                begin=0;
                break;
            default: {
                //Erreur de saisie, permet d'éviter que le programme s'arrete
                if (scanf("%d", &choix) != 1 || choix <= 0) {
                    printf("Entree invalide.\n");
                    while (getchar() != '\n'); // getchar permet de lire un caractère lors d'une saisie clavier, il sécurise notre programmesi l'utilisateur décide de saisir un caractère au lieu d'un entier
                    break;
                }
            }
        }
    }
    int running = 1;
    while (running) {
        print_menu(); //Fonction permettant l'affichage du menu, initialiser dans le cdataframe.c

        int choice;
        scanf("%d", &choice); //Accéder à une case

        switch (choice) {
            case 1: {
// Ajouter une colonne
                char title[100];
                printf("Entrez le titre de la colonne:\n");
                scanf("%s", title);
                COLUMN *col = create_column(title);
                add_column_cdataframe(cdata, col);
                printf("Colonne '%s' ajoutee.\n", title);
                break;
            }
            case 2: {
// Ajouter une ligne
                int num_cols = get_row_count(cdata); //Ajoute le nombre de ligne en fonction du nombre de colonne
                if (num_cols == 0) {
                    printf("Aucune colonne n'existe. Ajoutez d'abord des colonnes.\n");
                    break;
                }
                int *values = malloc(num_cols * sizeof(int));
                for (int i = 0; i < num_cols; i++) {
                    printf("Entrez la valeur pour la colonne %d:\n", i + 1);
                    if (scanf("%d", &values[i]) != 1) {
                        printf("Entree invalide. Ligne annulee.\n");
                        free(values);
                        while (getchar() != '\n'); // getchar permet de lire un caractère lors d'une saisie clavier
                        break;
                    }
                }
                add_row_cdataframe(cdata, values); //Utilise la fonction qui ajoute des lignes
                free(values);
                printf("Ligne ajoutee.\n");
                break;
            }
            case 3: {
// Supprimer une ligne
                int row;
                printf("Entrez le numero de la ligne a supprimer:\n");
                if (scanf("%d", &row) != 1 || row <= 0) { //Permet de choisir la ligne à renommer
                    printf("Entree invalide.\n");
                    while (getchar() != '\n'); // getchar permet de lire un caractère lors d'une saisie clavier
                    break;
                }
                delete_row_cdataframe(cdata, row - 1); //Utilise la fonction supprimant des lignes et créer dans le fichier cdataframe.c
                printf("Ligne %d supprimee.\n", row);
                break;
            }
            case 4: {
// Supprimer une colonne
                int col;
                printf("Entrez le numero de la colonne a supprimer:\n");
                if (scanf("%d", &col) != 1 || col <= 0) { //Permet de choisir la colonne à supprimer
                    printf("Entree invalide.\n");
                    while (getchar() != '\n'); // getchar permet de lire un caractère lors d'une saisie clavier
                    break;
                }
                delete_column_cdataframe(cdata, col - 1); //Fonction principal permettant la suppréssion de colonne
                printf("Colonne %d supprimee.\n", col);
                break;
            }
            case 5: {
// Renommer une colonne
                int col;
                char new_title[50];
                printf("Entrez le numero de la colonne a renommer:\n");
                if (scanf("%d", &col) != 1 || col <= 0) { //Permet de choisir la colonne à renommer
                    printf("Entree invalide.\n");
                    while (getchar() != '\n'); // getchar permet de lire un caractère lors d'une saisie clavier
                    break;
                }
                printf("Entrez le nouveau titre de la colonne:\n");
                scanf("%s", new_title);
                rename_column_cdataframe(cdata, col - 1 , new_title); //Fonction principale pour renommer une colonne
                printf("Colonne %d renommee en '%s'.\n", col, new_title);
                break;
            }
            case 6: {
// Afficher le dataframe
                printf("Dataframe actuel:\n");
                print_cdataframe(cdata); //Fonction permettant d'afficher la totalité de notre cdataframe
                break;
            }
            case 7: {
// Vérifier l'existence d'une valeur
                int value;
                printf("Entrez la valeur a rechercher:\n");
                if (scanf("%d", &value) != 1) {
                    printf("Entree invalide.\n");
                    while (getchar() != '\n'); // getchar permet de lire un caractère lors d'une saisie clavier
                    break;
                }
                int exists = exists_value_cdataframe(cdata, value); //Vérifie si la valeur existe dans le cdataframe
                printf("La valeur %d existe dans le dataframe: %s\n", value, exists ? "Oui" : "Non");
                break;
            }
            case 8: {
//Affiche de la première à la ligne que l'on souhaite
                int row1, row2;
                printf("Entrez le numero de la premiere colonne:\n");
                scanf("%d", &row1);
                printf("Entrez le numero de la derniere colonne:\n");
                scanf("%d", &row2);
                print_row(cdata, row1, row2); //Affichage des lignes (selon celle que vous avez sélectionner)
                break;
            }
            case 9:{
//Affiche de la première à la colonne que l'on souhaite
                int col1, col2;
                printf("Entrez le numero de la premiere colonne:\n");
                scanf("%d", &col1);
                printf("Entrez le numero de la derniere colonne:\n");
                scanf("%d", &col2);
                print_column(cdata, col1, col2); //Affichage des colonnes (selon celle que vous avez sélectionner)
                break;
            }
            case 10:{
//Affichage de la mémoire
                int row_count = get_row_count(cdata); //Renvoie la taille logique
                int column_count = get_column_count(cdata); //Renvoie la taille physique
                printf("Nombre de lignes (deja rempli) : %d\n", row_count);
                printf("Nombre de colonnes (en tout): %d\n", column_count);
                break;
            }
            case 11: {
//Acceder et changer la valeur à partir d'une saisie de ligne et colonne voulue
                int row, col;
                int new_value;
                printf("Entrez le numero de la ligne :\n");
                scanf("%d", &row);
                printf("Entrez le numero de la colonne :\n");
                scanf("%d", &col);
                int value = get_value_cdataframe(cdata, row, col); //Renvoie la valeur de la colonne et ligne saisie
                if (value != -1) {
                    printf("La valeur a la ligne %d, colonne %d est : %d\n", row, col, value);
                    printf("Entrez la nouvelle valeur :\n");
                    scanf("%d", &new_value);
                    set_value_cdataframe(cdata, row, col, new_value); //Remplace la valeur précédente par la nouvelle
                    printf("Nouvelle valeur à la ligne %d, colonne %d : %d\n", row, col, get_value_cdataframe(cdata, row, col));
                } else {
                    printf("Indice de ligne ou de colonne invalide.\n");
                }
                break;
            }
            case 12: {
//Comparaison lors de la saisie d'une valeur (supérieur/inférieur/égale)
                int x;
                printf("Entrez une valeur pour les comparaisons : ");
                scanf("%d", &x);
                int equal_count = count_cells_equal_to(cdata, x); //Nous donne les valeurs égales à x dans le cdataframe
                printf("Nombre de cellules egales a %d : %d\n", x, equal_count);
                int greater_count = count_cells_greater_than(cdata, x); //Nous donne les valeurs inférieurs à x dans le cdataframe
                printf("Nombre de cellules superieures a %d : %d\n", x, greater_count);
                int less_count = count_cells_less_than(cdata, x); //Nous donne les valeurs suppérieurs à x dans le cdataframe
                printf("Nombre de cellules inferieures a %d : %d\n", x, less_count);
                break;
            }
            case 13:{
                printf("Voici le nom des colonnes presentent dans le cdataframe:\n");
                print_column_names_cdataframe(cdata); //Permet l'affichage de tous les noms des colonnes
                break;
            }
            case 14: {
// Quitter
                running = 0; //Permet de quitter la boucle
                printf("Au revoir!\n");
                break;
            }
            default: {
                if (scanf("%d", &choice) != 1 || choice <= 0) {
                    printf("Entree invalide.\n");
                    while (getchar() != '\n'); // getchar permet de lire un caractère lors d'une saisie clavier, il sécurise notre programmesi l'utilisateur décide de saisir un caractère au lieu d'un entier
                    break;
                }
            }
        }
    }

    return 0;
}
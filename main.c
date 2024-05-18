#include <stdio.h>
#include "column.h"
#include "CDataframe.h"
#include <stdlib.h>

int main() {
    CDATAFRAME *cdata = create_cdataframe();

    // Saisie en dur (initialisation)
    COLUMN *col1 = create_column("Colonne 1");
    COLUMN *col2 = create_column("Colonne 2");

    insert_value(col1, 10);
    insert_value(col1, 20);
    insert_value(col1, 30);

    insert_value(col2, 40);
    insert_value(col2, 50);
    insert_value(col2, 60);

    add_column_cdataframe(cdata, col1);
    add_column_cdataframe(cdata, col2);

    int new_row_values[] = {70, 80};
    add_row_cdataframe(cdata, new_row_values);

    printf("Dataframe initialisé avec des valeurs en dur:\n");
    print_cdataframe(cdata);


    int running = 1;
    while (running) {
        print_menu();

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Ajouter une colonne
                char title[100];
                printf("Entrez le titre de la colonne:\n");
                scanf("%s", title);
                COLUMN *col = create_column(title);
                add_column_cdataframe(cdata, col);
                printf("Colonne '%s' ajoutée.\n", title);
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
                        printf("Entrée invalide. Ligne annulée.\n");
                        free(values);
                        while (getchar() != '\n'); // getchar permet de lire un caractère lors d'une saisie clavier
                        break;
                    }
                }
                add_row_cdataframe(cdata, values);
                free(values);
                printf("Ligne ajoutée.\n");
                break;
            }
            case 3: {
                // Supprimer une ligne
                int row;
                printf("Entrez le numéro de la ligne à supprimer:\n");
                if (scanf("%d", &row) != 1 || row <= 0) {
                    printf("Entrée invalide.\n");
                    while (getchar() != '\n'); // getchar permet de lire un caractère lors d'une saisie clavier
                    break;
                }
                delete_row_cdataframe(cdata, row - 1);
                printf("Ligne %d supprimée.\n", row);
                break;
            }
            case 4: {
                // Supprimer une colonne
                int col;
                printf("Entrez le numéro de la colonne à supprimer:\n");
                if (scanf("%d", &col) != 1 || col <= 0) {
                    printf("Entrée invalide.\n");
                    while (getchar() != '\n'); // getchar permet de lire un caractère lors d'une saisie clavier
                    break;
                }
                delete_column_cdataframe(cdata, col - 1);
                printf("Colonne %d supprimée.\n", col);
                break;
            }
            case 5: {
                // Renommer une colonne
                int col;
                char new_title[100];
                printf("Entrez le numéro de la colonne à renommer:\n");
                if (scanf("%d", &col) != 1 || col <= 0) {
                    printf("Entrée invalide.\n");
                    while (getchar() != '\n'); // getchar permet de lire un caractère lors d'une saisie clavier
                    break;
                }
                printf("Entrez le nouveau titre de la colonne:\n");
                scanf("%s", new_title);
                rename_column_cdataframe(cdata, col - 1, new_title);
                printf("Colonne %d renommée en '%s'.\n", col, new_title);
                break;
            }
            case 6: {
                // Afficher le dataframe
                printf("Dataframe actuel:\n");
                print_cdataframe(cdata);
                break;
            }
            case 7: {
                // Vérifier l'existence d'une valeur
                int value;
                printf("Entrez la valeur à rechercher:\n");
                if (scanf("%d", &value) != 1) {
                    printf("Entrée invalide.\n");
                    while (getchar() != '\n'); // getchar permet de lire un caractère lors d'une saisie clavier
                    break;
                }
                int exists = exists_value_cdataframe(cdata, value);
                printf("La valeur %d existe dans le dataframe: %s\n", value, exists ? "Oui" : "Non");
                break;
            }
            case 8: {
                //Affiche de la première à la ligne que l'on souhaite
                int row1, row2;
                printf("Entrez le numéro de la première colonne:\n");
                scanf("%d", &row1);
                printf("Entrez le numéro de la dernière colonne:\n");
                scanf("%d", &row2);
                print_ligne(cdata, row1, row2);
                break;
            }
            case 9:{
                //Affiche de la première à la colonne que l'on souhaite
                int col1, col2;
                printf("Entrez le numéro de la première colonne:\n");
                scanf("%d", &col1);
                printf("Entrez le numéro de la dernière colonne:\n");
                scanf("%d", &col2);
                print_colonne(cdata, col1, col2);
                break;
            }
            case 10:{
                int row_count = get_row_count(cdata);
                int column_count = get_column_count(cdata);
                printf("Nombre de lignes (utilisé) : %d\n", row_count);
                printf("Nombre de colonnes (en tout): %d\n", column_count);
                break;
            }
            case 12: {
                // Quitter
                running = 0;
                printf("Au revoir!\n");
                break;
            }
            default: {
                printf("Option invalide. Veuillez réessayer.\n");
                break;
            }
        }
    }

    return 0;
}

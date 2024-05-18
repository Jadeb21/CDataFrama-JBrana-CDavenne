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
                printf("Entrez le titre de la colonne: ");
                scanf("%s", title);
                COLUMN *col = create_column(title);
                add_column_cdataframe(cdata, col);
                printf("Colonne '%s' ajoutée.\n", title);
                break;
            }
            case 2: {
                // Ajouter une ligne
                int num_cols = get_column_count(cdata);
                if (num_cols == 0) {
                    printf("Aucune colonne n'existe. Ajoutez d'abord des colonnes.\n");
                    break;
                }
                int *values = malloc(num_cols * sizeof(int));
                for (int i = 0; i < num_cols; i++) {
                    printf("Entrez la valeur pour la colonne %d: ", i + 1);
                    if (scanf("%d", &values[i]) != 1) {
                        printf("Entrée invalide. Ligne annulée.\n");
                        free(values);
                        while (getchar() != '\n'); // Clear the input buffer
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
                printf("Entrez le numéro de la ligne à supprimer: ");
                if (scanf("%d", &row) != 1 || row <= 0) {
                    printf("Entrée invalide.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }
                delete_row_cdataframe(cdata, row - 1);
                printf("Ligne %d supprimée.\n", row);
                break;
            }
            case 4: {
                // Supprimer une colonne
                int col;
                printf("Entrez le numéro de la colonne à supprimer: ");
                if (scanf("%d", &col) != 1 || col <= 0) {
                    printf("Entrée invalide.\n");
                    while (getchar() != '\n'); // Clear the input buffer
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
                printf("Entrez le numéro de la colonne à renommer: ");
                if (scanf("%d", &col) != 1 || col <= 0) {
                    printf("Entrée invalide.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }
                printf("Entrez le nouveau titre de la colonne: ");
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
                printf("Entrez la valeur à rechercher: ");
                if (scanf("%d", &value) != 1) {
                    printf("Entrée invalide.\n");
                    while (getchar() != '\n'); // Clear the input buffer
                    break;
                }
                int exists = exists_value_cdataframe(cdata, value);
                printf("La valeur %d existe dans le dataframe: %s\n", value, exists ? "Oui" : "Non");
                break;
            }
            case 8: {
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

    // Libération des ressources
    for (int i = 0; i < cdata->tl; i++) {
        delete_column(&cdata->tab[i]);
    }
    free(cdata->tab);
    free(cdata);

    return 0;
}

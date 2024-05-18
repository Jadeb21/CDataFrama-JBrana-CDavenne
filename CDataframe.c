//
// Created by jadeb on 17/05/2024.
//
#include <malloc.h>
#include "CDataframe.h"
#include "column.h"
#include <stdio.h>
#include <string.h>

//Initialisation du cdataframe vide
CDATAFRAME *create_cdataframe(){
    CDATAFRAME *cdata = (CDATAFRAME*)malloc(sizeof(COLUMN));
    cdata->tp=0;
    cdata->tl=0;
    cdata->tab = NULL;
    return cdata;

}
int input_user(CDATAFRAME* cdata, COLUMN* col){
    char title[100];
    int value;
    int T;
    int choix;
    do {
        printf("Entrer le titre de la colonne:\n");
        scanf("%50s", title); //permet de saisir 50 caractères maximum, correspondant au mot le plus long du monde en français
        COLUMN* tab = create_column(title);
        do {
            printf("Entrer la valeur de la colonne \"%s\" (Saisir -1 quand vous avez fini): ", title);
            if (scanf("%d", &value) != 1) { // Vérifie si la saisie est un entier
                printf("Invalid input. Please enter an integer.\n");
                while (getchar() != '\n'); // Vide le tampon d'entrée
                continue;
            }

            if (value != -1) {
                insert_value(tab, value);
            }
        } while (value != -1);
    }while(choix == 'o' || choix == 'O');

    printf("Voulez-vous entrer une autre valeur ?[O/N]\n");
    scanf("%c ", &choix);

}



int insert_cdataframe_column(CDATAFRAME* cdata, COLUMN* col) {
    int* ptr;
    if (cdata->tp==0){
        cdata->tab = malloc(REALLOC_SIZE*sizeof(COLUMN));
        cdata->tp+=REALLOC_SIZE;
        if (cdata->tp==cdata->tl) {
            ptr = realloc(cdata->tab, REALLOC_SIZE * sizeof(COLUMN));
            if (ptr == NULL)
                return 0;
            cdata->tab = ptr;
            cdata->tp += REALLOC_SIZE;
        }
        cdata->tab[cdata->tl] = *col;
        cdata->tl++;
        return 1;
    }

}

//Fonction affiche tout le cdataframe
void print_cdataframe(CDATAFRAME* cdata){
    for (int i=0; i<cdata->tl; i++){
        print_col(&cdata->tab[i]); //Utilisation du print_col initialisé dans le fichier column.c
    }
}

//Fonction affiche les lignes selon votre choix, du cdataframe
void print_ligne(CDATAFRAME* cdata, int ligne1, int ligne2){
    for (int i=0; i<cdata->tl; i++)
    {

        printf("ligne %d:\n", ligne1+i);
        for (int j=ligne1-1; j<ligne2; j++)
        {
            COLUMN *col = &cdata->tab[j];
            printf("%d ", col->tab[i]);
        }
        printf("\n");
    }
}

//Fonction permettant d'afficher les colonnes choisis du cdataframe
void print_colonne(CDATAFRAME* cdata, int col1, int col2)
{
    for (int i=col1-1; i<col2; i++)
    {
        printf("colonne %d:\n", col1+i);
        COLUMN *col = &cdata->tab[i];
        for (int j=0; j<cdata->tl; j++)
        {
            printf("%d ", col->tab[j]);
        }
        printf("\n");
    }
}

// Fonction pour ajouter une ligne de valeurs au CDataframe
void add_row_cdataframe(CDATAFRAME* cdata, int* values) {
    if (cdata->tp == 0 || cdata->tl >= cdata->tp) {
        // Réallocation si nécessaire
        cdata->tp += REALLOC_SIZE;
        cdata->tab = realloc(cdata->tab, cdata->tp * sizeof(COLUMN));
    }

    for (int i = 0; i < cdata->tl; ++i) {
        insert_value(&(cdata->tab[i]), values[i]);
    }
    cdata->tl++;
}

void delete_row_cdataframe(CDATAFRAME* cdata, int row) {
    if (row < 0 || row >= cdata->tl) return;

    for (int i = 0; i < cdata->tp; ++i) {
        for (int j = row; j < cdata->tab[i].tl - 1; ++j) {
            cdata->tab[i].tab[j] = cdata->tab[i].tab[j + 1];
        }
        cdata->tab[i].tl--;
    }
    cdata->tl--;
}

void add_column_cdataframe(CDATAFRAME* cdata, COLUMN* col) {
    if (cdata->tp == cdata->tl) {
        cdata->tp += REALLOC_SIZE;
        cdata->tab = realloc(cdata->tab, cdata->tp * sizeof(COLUMN));
    }
    cdata->tab[cdata->tl++] = *col;
}

void delete_column_cdataframe(CDATAFRAME* cdata, int col_index) {
    if (col_index < 0 || col_index >= cdata->tl) return;

    delete_column(&(cdata->tab[col_index]));

    for (int i = col_index; i < cdata->tl - 1; ++i) {
        cdata->tab[i] = cdata->tab[i + 1];
    }
    cdata->tl--;
}

void rename_column_cdataframe(CDATAFRAME* cdata, int col_index, char* new_title) {
    if (col_index < 0 || col_index >= cdata->tl) return;

    free(cdata->tab[col_index].title);
    cdata->tab[col_index].title = strdup(new_title);
}
int exists_value_cdataframe(CDATAFRAME* cdata, int value) {
    for (int i = 0; i < cdata->tl; ++i) {
        if (count_occurences(&(cdata->tab[i]), value) > 0) {
            return 1;
        }
    }
    return 0;
}
int get_value_cdataframe(CDATAFRAME* cdata, int row, int col) {
    if (col < 0 || col >= cdata->tl || row < 0 || row >= cdata->tab[col].tl) {
        return -1; // ou une autre valeur indicative d'erreur
    }
    return value_position(&(cdata->tab[col]), row);
}

void set_value_cdataframe(CDATAFRAME* cdata, int row, int col, int value) {
    if (row < 0 || row >= cdata->tab[col].tl || col < 0 || col >= cdata->tl) {
        return;
    }
    cdata->tab[col].tab[row] = value;
}
void print_column_names_cdataframe(CDATAFRAME* cdata) {
    for (int i = 0; i < cdata->tl; ++i) {
        printf("%s\n", cdata->tab[i].title);
    }
}
int get_row_count(CDATAFRAME* cdata) {
    return cdata->tl;
}
int get_column_count(CDATAFRAME* cdata) {
    return cdata->tp;
}
int count_cells_equal_to(CDATAFRAME* cdata, int x) {
    int count = 0;
    for (int i = 0; i < cdata->tp; ++i) {
        count += equal_value(&(cdata->tab[i]), x);
    }
    return count;
}
int count_cells_greater_than(CDATAFRAME* cdata, int x) {
    int count = 0;
    for (int i = 0; i < cdata->tp; ++i) {
        count += more_value(&(cdata->tab[i]), x);
    }
    return count;
}
int count_cells_less_than(CDATAFRAME* cdata, int x) {
    int count = 0;
    for (int i = 0; i < cdata->tp; ++i) {
        count += less_value(&(cdata->tab[i]), x);
    }
    return count;
}

void print_menu() {
    printf("\nMenu:\n");
    printf("1. Ajouter une colonne\n");
    printf("2. Ajouter une ligne\n");
    printf("3. Supprimer une ligne\n");
    printf("4. Supprimer une colonne\n");
    printf("5. Renommer une colonne\n");
    printf("6. Afficher le dataframe\n");
    printf("7. Vérifier l'existence d'une valeur\n");
    printf("8. Quitter\n");
    printf("Choisissez une option:\n");
}
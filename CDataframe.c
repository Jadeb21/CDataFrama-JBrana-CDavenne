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

//Initialisation du cdataframe en saisie utilisateur
//Fonction non utilisé dans notre cdataframe car beaucoup de bug
void input_user(CDATAFRAME* cdata, COLUMN* col){
    char title[100];
    int value;
    int choix;
    do {
        printf("Entrer le titre de la colonne:\n");
        scanf("%50s", title); //permet de saisir 50 caractères maximum, correspondant au mot le plus long du monde en français
        COLUMN* tab = create_column(title);
        do {
            printf("Entrer la valeur de la colonne \"%s\" (Saisir -1 quand vous avez fini):\n", title);
            if (scanf("%d", &value) != 1) { // Vérifie si la saisie est un entier
                printf("Entrer invalide, veuillez saisir un autre chiffre.\n");
                while (getchar() != '\n');
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

//Initialisation du cdataframe en dur
void hardware_cdataframe(CDATAFRAME* cdata) {
    // Création de colonnes avec des valeurs initiales
    COLUMN *col1 = create_column("Colonne 1");
    COLUMN *col2 = create_column("Colonne 2");
    COLUMN *col3 = create_column("Colonne 3");
    COLUMN *col4 = create_column("Colonne 4");
    COLUMN *col5 = create_column("Colonne 5");
    COLUMN *col6 = create_column("Colonne 6");
    COLUMN *col7 = create_column("Colonne 7");
    COLUMN *col8 = create_column("Colonne 8");
    COLUMN *col9 = create_column("Colonne 9");
    COLUMN *col10 = create_column("Colonne 10");

    insert_value(col1, 10);
    insert_value(col1, 20);
    insert_value(col1, 30);

    insert_value(col2, 40);
    insert_value(col2, 50);
    insert_value(col2, 60);

    insert_value(col3, 70);
    insert_value(col3, 80);
    insert_value(col3, 90);

    insert_value(col4, 100);
    insert_value(col4, 110);
    insert_value(col4, 120);

    insert_value(col5, 130);
    insert_value(col5, 140);
    insert_value(col5, 150);

    insert_value(col6, 160);
    insert_value(col6, 170);
    insert_value(col6, 180);

    insert_value(col7, 190);
    insert_value(col7, 200);
    insert_value(col7, 210);

    insert_value(col8, 220);
    insert_value(col8, 230);
    insert_value(col8, 240);

    insert_value(col9, 250);
    insert_value(col9, 260);
    insert_value(col9, 270);

    insert_value(col10, 280);
    insert_value(col10, 290);
    insert_value(col10, 300);


    // Ajout des colonnes au CDATAFRAME
    add_column_cdataframe(cdata, col1);
    add_column_cdataframe(cdata, col2);
    add_column_cdataframe(cdata, col3);
    add_column_cdataframe(cdata, col4);
    add_column_cdataframe(cdata, col5);
    add_column_cdataframe(cdata, col6);
    add_column_cdataframe(cdata, col7);
    add_column_cdataframe(cdata, col8);
    add_column_cdataframe(cdata, col9);
    add_column_cdataframe(cdata, col10);

}

//Ajout d'une colonne
void add_column_cdataframe(CDATAFRAME* cdata, COLUMN* col) {
    if (cdata->tp == cdata->tl) {
        cdata->tp += REALLOC_SIZE;
        cdata->tab = realloc(cdata->tab, cdata->tp * sizeof(COLUMN));
    }
    cdata->tab[cdata->tl].title = strdup(col->title); //Permet de garder en mémoire le nom de la colonne ajouter
    cdata->tab[cdata->tl++] = *col;
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
        cdata->tp += REALLOC_SIZE;
        cdata->tab = realloc(cdata->tab, cdata->tp * sizeof(COLUMN));
    }
    for (int i = 0; i < cdata->tl; ++i) {
        insert_value(&(cdata->tab[i]), values[i]);
    }
    cdata->tl++;
}

//Suppression d'une ligne
void delete_row_cdataframe(CDATAFRAME* cdata, int row) {
    if (row < 0 || row >= cdata->tl)
        return;
    for (int i = 0; i < cdata->tl; ++i) {
        for (int j = row; j < cdata->tab[i].tl - 1; ++j) {
            cdata->tab[i].tab[j] = cdata->tab[i].tab[j + 1];
        }
        cdata->tab[i].tl--;
    }
    cdata->tl--;
}

//Suppression d'une colonne
void delete_column_cdataframe(CDATAFRAME* cdata, int col_index) {
    if (col_index < 0 || col_index >= cdata->tp) {
        return;
    }
    delete_column((COLUMN **) &(cdata->tab[col_index]));

    // Déplacer les colonnes suivantes vers la gauche
    for (int i = col_index; i < cdata->tp - 1; ++i) {
        cdata->tab[i] = cdata->tab[i + 1];
    }

    // Décrémenter la taille logique
    cdata->tp--;
}


//Renommer une colonne du cdataframe
void rename_column_cdataframe(CDATAFRAME* cdata, int col_index, char *new_title) {
    if (col_index < 0 || col_index >= cdata->tl)
        free(cdata->tab[col_index].title);

    cdata->tab[col_index].title = strdup(new_title);

}

//chercher s'il existe une valeur donnée
int exists_value_cdataframe(CDATAFRAME* cdata, int value) {
    for (int i = 0; i < cdata->tl; ++i) {
        if (count_occurences(&(cdata->tab[i]), value) > 0) { //On utilise le nombre d'occurrence de la fonction column.h pour compter le nombre de fois ou la valeur apparait
            return 1;
        }
    }
    return 0;
}

//Chercher une valeur
int get_value_cdataframe(CDATAFRAME* cdata, int row, int col) {
    if (col < 0 || col >= cdata->tl || row < 0 || row >= cdata->tab[col].tl) {
        return -1; // ou une autre valeur indicative d'erreur
    }
    return value_position(&(cdata->tab[col]), row);
}

//Changer la valeur après avoir utiliser get_value_cdataframe
void set_value_cdataframe(CDATAFRAME* cdata, int row, int col, int value) {
    if (row < 0 || row >= cdata->tab[col].tl || col < 0 || col >= cdata->tl) {
        return;
    }
    cdata->tab[col].tab[row] = value;
}

//Renvoie le nom des colonnes
void print_column_names_cdataframe(CDATAFRAME* cdata) {
    for (int i = 0; i < cdata->tl; ++i) {
        printf("%s\n", cdata->tab[i].title);
    }
}

//Compte le nombre de colonne utiliser
int get_row_count(CDATAFRAME *cdata) {
    return cdata->tl;
}

//Montre toute la mémoire
int get_column_count(CDATAFRAME *cdata) {
    return cdata->tp;
}

//compte le nombre de valeur egale à une valeur donner
int count_cells_equal_to(CDATAFRAME* cdata, int x) {
    int count = 0;
    for (int i = 0; i < cdata->tl; ++i) {
        count += equal_value(&(cdata->tab[i]), x); //Utilisation de equal_value (nous aurions pu utiliser count_occurrence) initialiser en column.h
    }
    return count;
}
int count_cells_greater_than(CDATAFRAME* cdata, int x) {
    int count = 0;
    for (int i = 0; i < cdata->tl; ++i) {
        count += more_value(&(cdata->tab[i]), x);//Utilisation de more_value initialiser en column.h
    }
    return count;
}
int count_cells_less_than(CDATAFRAME* cdata, int x) {
    int count = 0;
    for (int i = 0; i < cdata->tl; ++i) {
        count += less_value(&(cdata->tab[i]), x);//Utilisation de less_value initialiser en column.h
    }
    return count;
}

//Menu du cdataframe
void print_menu() {
    printf("\nMenu:\n");
    printf("1. Ajouter une colonne\n");
    printf("2. Ajouter une ligne\n");
    printf("3. Supprimer une ligne\n");
    printf("4. Supprimer une colonne\n");
    printf("5. Renommer une colonne\n");
    printf("6. Afficher le dataframe\n");
    printf("7. Verifier l'existence d'une valeur\n");
    printf("8. Afficher les premieres lignes voulu\n");
    printf("9. Afficher les premieres colonnes voulu\n");
    printf("10. Afficher la memoire\n");
    printf("11. Acceder et changer une valeur\n");
    printf("12. Comparaison a partir d'une valeur donnee\n");
    printf("13. Renvoyer le nom des colonnes\n");
    printf("14. Quitter\n");
    printf("Choisissez une option:\n");
}

void welcome(){
    printf("Bonjour et bienvenue dans le CDataframe !\n");
    printf("Merci de choisir une option:\n");
    printf("1. Prerempli\n");
    printf("2. Vide (a remplir au fur et a mesure)\n");
    printf("Comment voulez-vous initialiser votre CDataframe ?\n");
}
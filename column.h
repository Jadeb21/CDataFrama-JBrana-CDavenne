#ifndef PROJET2_0_COLUMN_H
#define PROJET2_0_COLUMN_H
//Fichier permettant la définition de chaque fonction de column.c

typedef struct {
    char *title; //Titre
    int tl; //taille logique
    int tp; //taille physique
    int *tab; //donnée
}COLUMN;

COLUMN *create_column(char* title);
int insert_value(COLUMN* col, int value);
void delete_column(COLUMN **col);
void print_col(COLUMN* col);
int count_occurences(COLUMN *col, int value);
int value_position(COLUMN *col, int position);
int more_value(COLUMN *col, int value);
int less_value(COLUMN *col, int value);
int equal_value(COLUMN *col, int value);

/* Definition fonction : Partie 2 du projet :

#define REALLOC_SIZE 256
enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type {
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE;

struct column {
    char *title;
    unsigned int size; // taille logique
    unsigned int max_size; // taille physique
    ENUM_TYPE column_type;
    COL_TYPE **data; // tableau de pointeurs vers les données stockées
    unsigned long long int *index; // tableau d'entiers
};
typedef struct column COLUMN;

COLUMN *create_column(ENUM_TYPE type, char* title);
int insert_value(COLUMN *col, void *value);
void delete_column(COLUMN **col);
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);
void print_col(COLUMN* col);
int count_occurences(COLUMN *col, int value);
int value_position(COLUMN *col, int position);
int more_value(COLUMN *col, int value);
int less_value(COLUMN *col, int value);
int equal_value(COLUMN *col, int value);
 */
#endif //PROJET2_0_COLUMN_H

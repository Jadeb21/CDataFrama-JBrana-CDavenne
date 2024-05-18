//
// Created by jadeb on 17/05/2024.
//

#ifndef PROJET2_0_COLUMN_H
#define PROJET2_0_COLUMN_H

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

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;
union column_type{
    unsigned int uint_value;
    signed int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE ;


#endif //PROJET2_0_COLUMN_H

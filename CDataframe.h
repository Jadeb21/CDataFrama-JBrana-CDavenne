//
// Created by jadeb on 17/05/2024.
//

#ifndef PROJET2_0_CDATAFRAME_H
#define PROJET2_0_CDATAFRAME_H

#include "column.h"
#define REALLOC_SIZE 256

typedef struct {
    COLUMN *tab;
    int tp;
    int tl;
}CDATAFRAME;

CDATAFRAME *create_cdataframe();
int insert_cdataframe_column(CDATAFRAME* cdata, COLUMN* col);
void print_cdataframe(CDATAFRAME* cdata);
void print_ligne(CDATAFRAME* cdata, int ligne1, int ligne2);
void print_colonne(CDATAFRAME* cdata, int col1, int col2);
int input_user(CDATAFRAME* cdata, COLUMN* col);
void add_row_cdataframe(CDATAFRAME* cdata, int* values);
void delete_row_cdataframe(CDATAFRAME* cdata, int row);
void add_column_cdataframe(CDATAFRAME* cdata, COLUMN* col);
void delete_column_cdataframe(CDATAFRAME* cdata, int col_index);
void rename_column_cdataframe(CDATAFRAME* cdata, int col_index, char* new_title);
int exists_value_cdataframe(CDATAFRAME* cdata, int value);
int get_value_cdataframe(CDATAFRAME* cdata, int row, int col);
void set_value_cdataframe(CDATAFRAME* cdata, int row, int col, int value);
void print_column_names_cdataframe(CDATAFRAME* cdata);

int get_row_count(CDATAFRAME* cdata);
int get_column_count(CDATAFRAME* cdata);
int count_cells_equal_to(CDATAFRAME* cdata, int x);
int count_cells_greater_than(CDATAFRAME* cdata, int x);
int count_cells_less_than(CDATAFRAME* cdata, int x);

#endif //PROJET2_0_CDATAFRAME_H

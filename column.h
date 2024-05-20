#ifndef PROJET_C_COLUMN_H
#define PROJET_C_COLUMN_H

#define REALOC_SIZE 256
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//Tout type de données

enum enum_type
{
    NULLVAL = 1 , UINT, INT, CHAR, FLOAT, DOUBLE, STRING, STRUCTURE
};
typedef enum enum_type ENUM_TYPE;

union column_type{
    unsigned int uint_value;
    int int_value;
    char char_value;
    float float_value;
    double double_value;
    char* string_value;
    void* struct_value;
};
typedef union column_type COL_TYPE ;

struct column {
    char *title;
    unsigned int size; //logical size
    unsigned int max_size; //physical size
    ENUM_TYPE column_type;
    COL_TYPE **data; // array of pointers to stored data
    unsigned long long int *index; // array of integers
// index valid
// 0 : no index
// -1 : invalid index
// 1 : valid index
    int valid_index;
// direction de tri Ascendant ou Déscendant
// 0 : ASC
// 1 : DESC
    int sort_dir;
};
typedef struct column COLUMN;

COLUMN* create_column(ENUM_TYPE column_type, char* titre);
int insert_value(COLUMN* col, void *value);
void delete_column(COLUMN **col);
void del_cell(COL_TYPE **cell);
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);
void print_col(COLUMN* col);
void print_col_intervalle(COLUMN* col, int debut, int fin);
void fill_column(COLUMN *col, int num_col, unsigned nb_val);


int nb_occurence(COLUMN *col, void *x, ENUM_TYPE type);
int valeur(COLUMN *col, unsigned long long int i);
int nb_valeur_sup(COLUMN *col, void *x);
int nb_valeur_min(COLUMN *col, void *x);
#endif

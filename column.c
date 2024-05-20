#include "column.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void m_paint_mem(void* ptr, int size, char pattern){
    for(int i=0; i<size; i++){
        *((char*)(ptr + i)) = pattern;
    }
}

COLUMN* create_column(ENUM_TYPE column_type,char* Title){
    COLUMN *col = (COLUMN*) malloc(sizeof(COLUMN));
    //m_paint_mem(col, sizeof(COLUMN), 0xcc);
    col->max_size = 0;
    col->size = 0;
    col->data = NULL;
    col->index = NULL;
    col->column_type = column_type;
    col->title = (char*) malloc(strlen(Title)+1);
    strcpy(col->title, Title);
    return col;
}

int insert_value(COLUMN* col, void *value){

    if (col->size == 0){
        col->data = malloc((sizeof(void*)*REALOC_SIZE/sizeof(void*)));

        col->max_size += REALOC_SIZE/sizeof(void*);
    }

    else if ((col->max_size) == col->size){                 //Todo Note si ça beug penser -1
        col->data = realloc(col->data, (col->max_size)*sizeof(void*) + (sizeof(void*)*REALOC_SIZE/sizeof(void*)));
        if (col->data == NULL)
            return 0;

        col->max_size += REALOC_SIZE/sizeof(void*);
    }
    if (value == NULL)
        col->data[col->size] = NULL;
    else{
        switch(col->column_type) {
            case INT:
                col->data[col->size] = (int*) malloc(sizeof(int));
                *((int *) col->data[col->size]) = *((int *) value);
                break;
            case UINT:
                col->data[col->size] = (unsigned int*) (COL_TYPE *) malloc(sizeof(unsigned int));
                *((unsigned int*) col->data[col->size]) = *((unsigned int*) value);
                break;
            case CHAR:
                col->data[col->size] = (char*) (COL_TYPE *) malloc(sizeof(char));
                *((char *) col->data[col->size]) = *((char *) value);
                break;
            case FLOAT:
                col->data[col->size] = (float*) (COL_TYPE *) malloc(sizeof(float));
                *((float *) col->data[col->size]) = *((float *) value);
                break;
            case DOUBLE:
                col->data[col->size] = (double*) (COL_TYPE *) malloc(sizeof(double));
                *((double *) col->data[col->size]) = *((double *) value);
                break;
            case STRING:
                col->data[col->size] = (char*) malloc(sizeof(char*));
                col->data[col->size]->string_value = (char*) malloc(strlen((char *)value) + 1);
                strcpy((char*) col->data[col->size]->string_value, (char *)value);
                break;
            case STRUCTURE:
                col->data[col->size] = (COL_TYPE *) malloc(sizeof(void*));
                *((void **) col->data[col->size]) = *((void **) value);
                break;
            case NULLVAL:
                col->data[col->size] = NULL;
                break;
            default:
                return 0;
        }
        }
    col->size++;
    return 1;
}

void delete_column(COLUMN **col){
    for (int i = 0; i < (*col)->size; i++) {
        del_cell(&(*col)->data[i]);
//        free(((*col)->data)[i]);
//        ((*col)->data)[i] = NULL;
    }
    free(*col);
    *col = NULL;
}
void del_cell(COL_TYPE **cell){
    free((*cell));
    *cell = NULL;
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size){
    if (col->data[i] == NULL) {
        snprintf(str, size, "NULL");
        return;
    }
    switch(col->column_type) {
        case INT:
            snprintf(str, size, "%d", *((int *) col->data[i]));
            break;
        case UINT:
            snprintf(str, size, "%d", *((int *) col->data[i]));
            break;
        case CHAR:
            snprintf(str, size, "%c", *((char *) col->data[i]));
            break;
        case FLOAT:
            snprintf(str, size, "%f", *((float *) col->data[i]));
            break;
        case DOUBLE:
            snprintf(str, size, "%lf", *((double *) col->data[i]));
            break;
        case STRING:
            strcpy(str, (char*) col->data[i]->string_value);
            break;
        case STRUCTURE:
            //TODO Faire pour les structures au fur et a mesure du projet.
            break;
        case NULLVAL:
            snprintf(str, size, "%s", *((char **) col->data[i]));
            snprintf(str, size, "NULL");
            break;

    }
}

void print_col(COLUMN* col){
    for (int i=0; i<(col->size); i++){
        char str[100]; //Todo faire dybamequement pour pouvoir avoir toute les tailles de variables
        convert_value(col, i, str, sizeof(str));
            printf("[%d] %s\n", i, str);

    }
}

void print_col_intervalle(COLUMN* col, int debut, int fin){
    for (int i=0; i<(col->size); i++){
        if (i >= debut && i <= fin) {
            char str[100];
            convert_value(col, i, str, sizeof(str));
            printf("[%d] %s\n", i, str);
        }
    }
}

int nb_occurence(COLUMN *col, void *x, ENUM_TYPE type){
    int cpt=0;
    for (int i=0; i<col->size; i++) {
        switch (type) {
            case INT:
                if (col->data[i]->int_value == *((int *) x))
                    cpt += 1;
                break;
            case UINT:
                if (col->data[i]->uint_value == *((unsigned int *) x))
                    cpt += 1;
                break;
            case CHAR:
                if (col->data[i]->char_value == *((char *) x))
                    cpt += 1;
                break;
            case FLOAT:
                if (col->data[i]->float_value == *((float *) x))
                    cpt += 1;
                break;
            case DOUBLE:
                if (col->data[i]->double_value == *((double *) x))
                    cpt += 1;
                break;
            case STRING:
                if (strcmp(col->data[i]->string_value, x) == 0)
                    cpt += 1;
                break;

        }
    }
    return cpt;
}

void fill_column(COLUMN *col, int num_col, unsigned int nb_val){
    void *ptr_val = NULL;
    printf("\nEntrez le titre de la colonne numero %d : ", num_col);
    scanf(" %s", col->title);
    for (int j=0; j<nb_val; j++){
        printf("\nEntrez une valeur a inserer dans la cellule [%d][%d] : ", num_col, j);
        switch (col->column_type) {
            case INT:
                ptr_val = (int *) malloc(sizeof(int));
                scanf(" %d", (int*)ptr_val);
                insert_value(col, ptr_val);
                break;
            case UINT:
                ptr_val = (int *) malloc(sizeof(int));
                scanf(" %d", (unsigned int*)ptr_val);
                insert_value(col, ptr_val);
                break;
            case CHAR:
                ptr_val = (char *) malloc(sizeof(int));
                scanf(" %c", (char*)ptr_val);
                insert_value(col, ptr_val);
                break;
            case FLOAT:
                ptr_val = (float *) malloc(sizeof(int));
                scanf(" %f", (float *)ptr_val);
                insert_value(col, ptr_val);
                break;
            case DOUBLE:
                ptr_val = (double *) malloc(sizeof(int));
                scanf(" %lf", (double *)ptr_val);
                insert_value(col, ptr_val);
                break;
            case STRING:
                ptr_val = (char *) malloc(sizeof(int));
                scanf(" %s", (char*)ptr_val); //Todo le scanf pour les chaines avec des espaces pour éviter les bugs
                insert_value(col, ptr_val);
                break;
            case STRUCTURE:
                //Todo cas structure.
                break;
            case NULLVAL:
                //Todo cas NULL
                break;
        }

    }
}

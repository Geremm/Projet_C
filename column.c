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
    //m_paint_mem(col->title, strlen(Title)+1, 0xaa);
    strcpy(col->title, Title);
    return col;
}

int insert_value(COLUMN* col, void *value){
    /*if (value == NULL) {
        int tmp = 0;
        value = &tmp;
    }*/

    if (col->size == 0){
        col->data = malloc((sizeof(void*)*REALOC_SIZE/sizeof(void*)));
        //m_paint_mem(col->data, sizeof(void*)*REALOC_SIZE/sizeof(void*), 0xdd);

        col->max_size += REALOC_SIZE/sizeof(void*);
    }

    else if ((col->max_size) == col->size){                 //Todo Note si ça beug penser -1
        col->data = realloc(col->data, (col->max_size)*sizeof(void*) + (sizeof(void*)*REALOC_SIZE/sizeof(void*)));
        //m_paint_mem(col->data, col->max_size + sizeof(void*)*REALOC_SIZE/sizeof(void*), 0xda);
        if (col->data == NULL)
            return 0;

        col->max_size += REALOC_SIZE/sizeof(void*);
    }
    if (value == NULL)
        col->data[col->size] = NULL;
    else{
        switch(col->column_type) {
            case INT:
                col->data[col->size] = (COL_TYPE *) (int *) malloc(sizeof(int));
                *((int *) col->data[col->size]) = *((int *) value);
                break;
            case UINT:
                col->data[col->size] = (COL_TYPE *) malloc(sizeof(unsigned int));
                *((unsigned int*) col->data[col->size]) = *((unsigned int*) value);
                break;
            case CHAR:
                col->data[col->size] = (COL_TYPE *) malloc(sizeof(char));
                //m_paint_mem(col->data[col->size], sizeof(char), 0xcc);
                *((char *) col->data[col->size]) = *((char *) value);
                break;
            case FLOAT:
                col->data[col->size] = (COL_TYPE *) malloc(sizeof(float));
                *((float *) col->data[col->size]) = *((float *) value);
                break;
            case DOUBLE:
                col->data[col->size] = (COL_TYPE *) malloc(sizeof(double));
                *((double *) col->data[col->size]) = *((double *) value);
                break;
            case STRING:
                col->data[col->size] = malloc(strlen((char *)value) + 1);
                strcpy((char*) col->data[col->size], (char *)value);
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
        free(((*col)->data)[(*col)->size]);         //TODO à vérifier si c'est i à la plce de col->size
        ((*col)->data)[(*col)->size] = NULL;
    }
    free(*col);
    *col = NULL;
    free(col);
    col = NULL;
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
            strcpy(str, (char*) col->data[i]);
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
        char str[100];
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

int nb_occurence(COLUMN *col, void *x){
    
}

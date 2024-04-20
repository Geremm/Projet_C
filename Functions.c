#include "Functions.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

COLUMN* create_column(ENUM_TYPE column_type,char* Title){
    COLUMN *col = (COLUMN*) malloc(sizeof(COLUMN));
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
    if (col->max_size == col -> size){
        if (col->size == 0){
            col->data = (void*) malloc(sizeof(void*));
        }
        else{
            realloc(col->data, sizeof(col->data) + sizeof(void*));
        }
    }
    switch(col->column_type) {
        case INT:
            (col->data)[col->size] = (int *) malloc(sizeof(int));
            *((int *) col->data[col->size]) = *((int *) value);
            break;
        case UINT:
            (col->data)[col->size] = (unsigned int*) malloc(sizeof(int));
            *((unsigned int*) col->data[col->size]) = *((unsigned int*) value);
            break;
        case CHAR:
            (col->data)[col->size] = (char *) malloc(sizeof(char));
            *((char *) col->data[col->size]) = *((char *) value);
            break;

        case FLOAT:
            (col->data)[col->size] = (float *) malloc(sizeof(float));
            *((float *) col->data[col->size]) = *((float *) value);
            break;
        case DOUBLE:
            (col->data)[col->size] = (double *) malloc(sizeof(double));
            *((double *) col->data[col->size]) = *((double *) value);
            break;
        case STRING:
            (col->data)[col->size] = (char **) malloc(sizeof(char*));
            *((char **) col->data[col->size]) = *((char **) value);
            break;
        case STRUCTURE:
            (col->data)[col->size] = (void **) malloc(sizeof(void*));
            *((void **) col->data[col->size]) = *((void **) value);
            break;
        case NULLVAL:
            (col->data)[col->size] = (void**) malloc(sizeof(NULL));
            *((void**) col->data[col->size]) = NULL;
    }
    col->size ++;
    return 1;
}

void delete_column(COLUMN **col){
    for (int i = 0; i < (*col)->size; i++) {
        free(((*col)->data)[(*col)->size]);
        ((*col)->data)[(*col)->size] = NULL;
    }
    free(*col);
    *col = NULL;
    free(col);
    col = NULL;
}

void convert_value(COLUMN *col, unsigned long long int i, char *str, int size){
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
            snprintf(str, size, "%s", *((char **) col->data[i]));
            break;
        case STRUCTURE:
            break;
        case NULLVAL:
            snprintf(str, size, "%s", *((char **) col->data[i]));
            break;

    }
}

void print_col(COLUMN* col){
    for (int i=0; i<(col->size); i++){
        char *str;
        convert_value(col, i, str, 10);
        printf("[%d] %s\n", i, str);
    }
}


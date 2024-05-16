#ifndef PROJET_C_CDATAFRAME_H
#define PROJET_C_CDATAFRAME_H
#include "list.h"
#include "column.h"

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);
void delete_cdataframe(CDATAFRAME **cdf);
void delete_column_cdf(CDATAFRAME *cdf, char *col_name);
int get_cdataframe_cols_size(CDATAFRAME *cdf);
CDATAFRAME *create_void_cdataframe(int size);
void fill_cdataframe(CDATAFRAME *cdf);
void print_cdataframe(CDATAFRAME *cdf);
void print_cdataframe_column(CDATAFRAME *cdf,int debut, int fin);
void print_cdataframe_ligne(CDATAFRAME *cdf,int debut, int fin);
void ajout_ligne(CDATAFRAME *cdf);
#endif //PROJET_C_CDATAFRAME_H

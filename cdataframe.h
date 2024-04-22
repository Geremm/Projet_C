#ifndef PROJET_C_CDATAFRAME_H
#define PROJET_C_CDATAFRAME_H
#include "list.h"
#include "column.h"

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);
void delete_cdataframe(CDATAFRAME **cdf);
void delete_column_cdf(CDATAFRAME *cdf, char *col_name);
int get_cdataframe_cols_size(CDATAFRAME *cdf);
void convert_value(COLUMN *col, unsigned long long int i, char *str, int size);

#endif //PROJET_C_CDATAFRAME_H

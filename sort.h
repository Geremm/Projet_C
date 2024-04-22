#ifndef PROJET_C_SORT_H
#define PROJET_C_SORT_H
#include "column.h"
#include "cdataframe.h"

void sort(COLUMN* col, int sort_dir);
void print_col_by_index(COLUMN *col);
void erase_index(COLUMN *col);
int check_index(COLUMN *col);
void update_index(COLUMN *col);
int search_value_in_column(COLUMN *col, void *val);

CDATAFRAME* load_from_csv(char *file_name, ENUM_TYPE *dftype, int size);
void save_into_csv(CDATAFRAME *cdf, char *file_name);

#endif //PROJET_C_SORT_H

#ifndef PROJET_C_CDATAFRAME_H
#define PROJET_C_CDATAFRAME_H
#include "list.h"
#include "column.h"

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size);
void delete_cdataframe(CDATAFRAME **cdf);
void del_colonne_cdf(CDATAFRAME *cdf, char *col_name);
int get_cdataframe_cols_size(CDATAFRAME *cdf);
CDATAFRAME *create_void_cdataframe(int size);
void fill_cdataframe(CDATAFRAME *cdf);
void print_cdataframe(CDATAFRAME *cdf);
void print_cdataframe_column(CDATAFRAME *cdf,int debut, int fin);
void print_cdataframe_ligne(CDATAFRAME *cdf,int debut, int fin);
void ajout_ligne(CDATAFRAME *cdf);
void ajout_col(CDATAFRAME *cdf, ENUM_TYPE col_type);
void del_ligne(CDATAFRAME *cdf, int num_ligne);
void remonter_val_col(COLUMN* col, int num_ligne);
void fill_cdataframe_saisie_endur(CDATAFRAME *cdf);
void rename_col(CDATAFRAME *cdf, char* titre,char* new_title);
int verif_existence(CDATAFRAME *cdf, void* val, ENUM_TYPE type);
void remplacer_val(CDATAFRAME *cdf, int i, int j);
void afficher_nom_colonnes(CDATAFRAME *cdf);
void afficher_nb_col(CDATAFRAME *cdf);
void afficher_nb_ligne(CDATAFRAME *cdf);
int nb_occurence_cdf(CDATAFRAME *cdf, void *x, ENUM_TYPE type);
#endif //PROJET_C_CDATAFRAME_H

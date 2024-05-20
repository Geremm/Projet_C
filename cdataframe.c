#include "cdataframe.h"

CDATAFRAME *create_cdataframe(ENUM_TYPE *cdftype, int size){
    list *lst = lst_create_list();
    for (int i=0; i<size; i++){
        char *str = (char *)malloc(20 * sizeof(char));
        snprintf(str, 20, "%d", i);
        COLUMN *col = create_column(cdftype[i], str);
        lnode *pnew = lst_create_lnode(col);
        lst_insert_tail(lst, pnew);
    }
    return lst;
}

CDATAFRAME *create_void_cdataframe(int size){
    list *lst = lst_create_list();
    for (int i=0; i<size; i++){
        char *str = (char *)malloc(20 * sizeof(char));
        snprintf(str, 20, "%d", i);
        COLUMN *col = create_column(NULLVAL, str);
        lnode *pnew = lst_create_lnode(col);
        lst_insert_tail(lst, pnew);
    }
    return lst;
}

void fill_cdataframe(CDATAFRAME *cdf){
    int nb_col = get_cdataframe_cols_size(cdf), nb_val;
    void *ptr_val = NULL;
    lnode *noeud_actuel = cdf->head;
    for (int i=0; i<nb_col; i++){
        if (i==0) {
            printf("\nEntrez le nombre de valeurs a inserer dans les colonnes : ");
            scanf(" %d", &nb_val);
        }
        fill_column(noeud_actuel->data,i, nb_val);
        noeud_actuel = noeud_actuel->next;
    }
}

void fill_cdataframe_saisie_endur(CDATAFRAME *cdf){
    int nb_col = get_cdataframe_cols_size(cdf), nb_val = 5;
    void *ptr_val = NULL;
    lnode *noeud_actuel = cdf->head;
    int  T[] = {12,24,36,48,60};
    char * str[] = {"Gerem", "Quenting", "Nico", "Esteb", "Matt"};
    double T_f[] = {1.12,2.24,3.36,4.48,5.60};
    strcpy(noeud_actuel->data->title, "Entier");
    for (int i=0; i<nb_val; i++)
        insert_value(noeud_actuel->data, T + i);

    noeud_actuel = noeud_actuel->next;

    strcpy(noeud_actuel->data->title, "STR");
    for (int i=0; i<nb_val; i++)
        insert_value(noeud_actuel->data, *(str + i));

    noeud_actuel = noeud_actuel->next;

    strcpy(noeud_actuel->data->title, "Double");
    for (int i=0; i<nb_val; i++)
        insert_value(noeud_actuel->data, T_f + i);
}


void delete_cdataframe(CDATAFRAME **cdf){
    int nb_col = get_cdataframe_cols_size(*cdf);
    lnode *noeud = (*cdf)->head;
    for(int i=0; i<nb_col; i++){
        delete_column(&noeud->data);
        noeud = noeud->next;
    }
    lst_delete_list(*cdf);
    *cdf = NULL;
}


int get_cdataframe_cols_size(CDATAFRAME *cdf){
    lnode *P = cdf->head;
    int nb_col = 1;
    while(P != cdf->tail){
        P = P->next;
        nb_col++;
    }
    return nb_col;
}

void print_cdataframe(CDATAFRAME *cdf){
    int nb_cols = get_cdataframe_cols_size(cdf);
    lnode *L = cdf->head;
    for(int i=0; i<nb_cols; i++) {
        printf("Column %d: \n", i);
        printf("Title : %s\n", L->data->title);
        print_col(L->data);
        L = L->next;
    }
}

void print_cdataframe_column(CDATAFRAME *cdf,int debut, int fin){
    int nb_cols = get_cdataframe_cols_size(cdf);
    lnode *L = cdf->head;
    for(int i=0; i<nb_cols; i++) {
        if (i >= debut && i <= fin) {
            printf("Column %d: \n", i);
            printf("Title : %s \n", L->data->title);
            print_col(L->data);
        }
        L = L->next;
    }
}

void print_cdataframe_ligne(CDATAFRAME *cdf, int debut, int fin){
    int nb_cols = get_cdataframe_cols_size(cdf);
    lnode *L = cdf->head;
    for(int i=0; i<nb_cols; i++) {
        printf("Column %d: \n", i);
        printf("Title : %s\n", L->data->title);
        print_col_intervalle(L->data, debut, fin);
        L = L->next;
    }
}

void ajout_ligne(CDATAFRAME *cdf){
    int nb_cols = get_cdataframe_cols_size(cdf);
    lnode *noeud_actuel = cdf->head;
    void *ptr_val = NULL;
    for (int i=0; i<nb_cols; i++){
        switch (noeud_actuel->data->column_type) {
            case INT:
                printf("\nEntrez une nouvelle valeur entiere dans la colonne %s : ", noeud_actuel->data->title);
                ptr_val = (int *) malloc(sizeof(int));
                scanf(" %d", (int*)ptr_val);
                insert_value(noeud_actuel->data, ptr_val);
                break;
            case UINT:
                printf("\nEntrez une nouvelle valeur entière positive dans la colonne %s : ", noeud_actuel->data->title);
                ptr_val = (int *) malloc(sizeof(int));
                scanf(" %d", (unsigned int*)ptr_val);
                insert_value(noeud_actuel->data, ptr_val);
                break;
            case CHAR:
                printf("\nEntrez un nouvel caractere dans la colonne %s : ", noeud_actuel->data->title);
                ptr_val = (char *) malloc(sizeof(int));
                scanf(" %c", (char*)ptr_val);
                insert_value(noeud_actuel->data, ptr_val);
                break;
            case FLOAT:
                printf("\nEntrez une nouvelle valeur decimale dans la colonne %s : ", noeud_actuel->data->title);
                ptr_val = (float *) malloc(sizeof(int));
                scanf(" %f", (float *)ptr_val);
                insert_value(noeud_actuel->data, ptr_val);
                break;
            case DOUBLE:
                printf("\nEntrez une nouvelle valeur decimale dans la colonne %s : ", noeud_actuel->data->title);
                ptr_val = (double *) malloc(sizeof(int));
                scanf(" %lf", (double *)ptr_val);
                insert_value(noeud_actuel->data, ptr_val);
                break;
            case STRING:
                printf("\nEntrez une nouvelle chaine de caractere dans la colonne %s : ", noeud_actuel->data->title);
                ptr_val = (char *) malloc(sizeof(int));
                scanf(" %s", (char*)ptr_val);
                insert_value(noeud_actuel->data, ptr_val);
                break;
        }
        noeud_actuel = noeud_actuel->next;
    }
}

//int nb_val_col_cdf(CDATAFRAME* cdf){
//    COLUMN *col = cdf->head->data;
//    for (int i=0; i<col->size; i++);
//}

void ajout_col(CDATAFRAME *cdf, ENUM_TYPE col_type){
    int nb_col = get_cdataframe_cols_size(cdf);
    char *str = (char *)malloc(20 * sizeof(char));
    snprintf(str, 20, "%d", nb_col);
    COLUMN *col = create_column(col_type, str);
    fill_column(col, nb_col, cdf->head->data->size);
    lnode *pnew = lst_create_lnode(col);
    lst_insert_tail(cdf, pnew);
}

void del_ligne(CDATAFRAME *cdf, int num_ligne){
    int nb_col = get_cdataframe_cols_size(cdf);
    lnode *noeud_actuel = cdf->head;

    for (int i = 0; i < nb_col; i++){
        del_cell(&noeud_actuel->data->data[num_ligne]);
        remonter_val_col(noeud_actuel->data, num_ligne);
        noeud_actuel = noeud_actuel->next;
    }


}

void remonter_val_col(COLUMN* col, int num_ligne){
    int i;
    for (i = num_ligne; i < (col->size - 1); i++) {
        if (col->data[i] == NULL) {
            col->data[i] = col->data[i+1];
            col->data[i+1] = NULL;
        }
    }
    free(col->data[i]);
    col->data[i] = NULL;
    col->size -= 1;
}

void del_colonne_cdf(CDATAFRAME *cdf, char* title) {
    lnode *noeud_actuel = cdf->head;

    // Utilisation de strcmp pour comparer les titres des colonnes
    while (noeud_actuel != NULL && strcmp(noeud_actuel->data->title, title) != 0) {
        noeud_actuel = noeud_actuel->next;
    }

    if (noeud_actuel != NULL && strcmp(noeud_actuel->data->title, title) == 0){
        //Modification du chainage:
        if (noeud_actuel->prev != NULL){
            noeud_actuel->prev->next = noeud_actuel->next;
        }
        else {
            cdf->head = noeud_actuel->next;
        }

        if (noeud_actuel->next != NULL) {
            noeud_actuel->next->prev = noeud_actuel->prev;
        }
        else {
            cdf->tail = noeud_actuel->prev;
        }
        //Suppression de la colonne:
        delete_column(&noeud_actuel->data);

        //Libération de la mémoire et mise à NULL du pointer:
        free(noeud_actuel);
        noeud_actuel = NULL;
    } else {
        printf("Colonne non trouvee \n");
    }
}

void rename_col(CDATAFRAME *cdf, char* titre,char* new_title){
    int nb_col = get_cdataframe_cols_size(cdf), i=0;
    COLUMN* col = cdf->head->data;
    lnode *noeud = cdf->head;
    while (i<nb_col && strcmp(noeud->data->title, titre) != 0){
        noeud = noeud->next;
        i++;
    }
    col = noeud->data;
    col->title = (char*) realloc(col->title, strlen(new_title) + 1);
    if (col->title == NULL) {
        printf("Erreur de réallocation de mémoire\n");
        return;
    }
    strcpy(col->title, new_title);
}

int verif_existence(CDATAFRAME *cdf, void* val, ENUM_TYPE type){
    int nb_col = get_cdataframe_cols_size(cdf);
    lnode *noeud_actuel = cdf->head;
    for (int i=0; i<nb_col; i++){
        if (noeud_actuel->data->column_type == type){
            for(int j=0; j<noeud_actuel->data->size; j++){
                switch(noeud_actuel->data->column_type) {
                    case INT:
                        if (noeud_actuel->data->data[j]->int_value == *(int*)val)
                            return 1;
                        break;
                    case UINT:
                        if (noeud_actuel->data->data[j]->uint_value == *(unsigned int*)val)
                            return 1;
                        break;
                    case CHAR:
                        if (noeud_actuel->data->data[j]->char_value == *(char*)val)
                            return 1;
                        break;

                    case FLOAT:
                        if (noeud_actuel->data->data[j]->float_value == *(float *)val)
                            return 1;
                        break;
                    case DOUBLE:
                        if (noeud_actuel->data->data[j]->double_value == *(double*)val)
                            return 1;
                        break;
                    case STRING:
                        if(strcmp(noeud_actuel->data->data[j]->string_value, (char*) val) == 0)
                            return 1;
                        break;
                    case STRUCTURE:
                            break;
                    case NULLVAL:
                            break;
                    default:
                        return 0;
                }
            }
        }
        noeud_actuel = noeud_actuel->next;
    }
    return 0;

}


COL_TYPE* acced_value(CDATAFRAME *cdf, int i, int j){
    lnode *noeud = cdf->head;
    for (int k=0; k < i; k++)
        noeud = noeud->next;
    return noeud->data->data[j];
}

void remplacer_val(CDATAFRAME *cdf, int i, int j){
    lnode *noeud = cdf->head;
    char str[100];
    for (int k=0; k < i; k++)
        noeud = noeud->next;
    switch (noeud->data->column_type) {
        case INT:
            printf("Entrez un entier a inserer dans la colonne %s, en [%d] [%d] : ", noeud->data->title, i, j);
            scanf(" %d", &noeud->data->data[j]->int_value);
            break;
        case UINT:
            printf("Entrez un entier a inserer dans la colonne %s, en [%d] [%d] : ", noeud->data->title, i, j);
            scanf(" %d", &noeud->data->data[j]->uint_value);
            break;
        case CHAR:
            printf("Entrez un caractere a inserer dans la colonne %s, en [%d] [%d] : ", noeud->data->title, i, j);
            scanf(" %c", &noeud->data->data[j]->char_value);
            break;
        case FLOAT:
            printf("Entrez un nombre decimal a inserer dans la colonne %s, en [%d] [%d] : ", noeud->data->title, i, j);
            scanf(" %f", &noeud->data->data[j]->float_value);
            break;
        case DOUBLE:
            printf("Entrez un nombre decimal a inserer dans la colonne %s, en [%d] [%d] : ", noeud->data->title, i, j);
            scanf(" %lf", &noeud->data->data[j]->double_value);
            break;
        case STRING:
            printf("Entrez un chaine de caractere a inserer dans la colonne %s, en [%d] [%d] : ", noeud->data->title, i, j);
            scanf(" %s", str);
            strcpy((char*) noeud->data->data[j]->string_value, str);
            break;
    }
}

void afficher_nom_colonnes(CDATAFRAME *cdf){
    int nb_col = get_cdataframe_cols_size(cdf);
    lnode *noeud = cdf->head;
    for (int i=0; i<nb_col; i++) {
        printf("Le nom de la colonne %d est %s\n", i, noeud->data->title);
        noeud = noeud->next;
    }
}

void afficher_nb_col(CDATAFRAME *cdf){
    printf("Il y a %d colonnes\n", get_cdataframe_cols_size(cdf));
}


void afficher_nb_ligne(CDATAFRAME *cdf){
    printf("Il y a %d lignes\n", cdf->head->data->size);
}

int nb_occurence_cdf(CDATAFRAME *cdf, void *x, ENUM_TYPE type){
    int cpt=0, nb_col= get_cdataframe_cols_size(cdf);
    lnode * noeud = cdf->head;
    for (int i = 0; i < nb_col; i++){
        cpt += nb_occurence(noeud->data, x, type);
        noeud = noeud->next;
    }
    return cpt;
}
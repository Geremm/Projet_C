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

void fill_cdataframe(CDATAFRAME *cdf){ //Todo faire des saisies sécurisées
    int nb_col = get_cdataframe_cols_size(cdf), nb_val;
    void *ptr_val = NULL;
    lnode *noeud_actuel = cdf->head;

    for (int i=0; i<nb_col; i++){
        printf("\nEntrez le titre de la colonne numero %d : ", i);
        scanf(" %s", noeud_actuel->data->title);
        printf("\nEntrez le nombre de valeurs a inserer dans la colonne %s : ", noeud_actuel->data->title);
        scanf(" %d", &nb_val);
        for (int j=0; j<nb_val; j++){
            printf("\nEntrez une valeur a inserer dans la cellule [%d][%d] : ", i, j);
            switch (noeud_actuel->data->column_type) {
                case INT:
                    ptr_val = (int *) malloc(sizeof(int));
                    scanf(" %d", (int*)ptr_val);
                    insert_value(noeud_actuel->data, ptr_val);
                    break;
                case UINT:
                    ptr_val = (int *) malloc(sizeof(int));
                    scanf(" %d", (unsigned int*)ptr_val);
                    insert_value(noeud_actuel->data, ptr_val);
                    break;
                case CHAR:
                    ptr_val = (char *) malloc(sizeof(int));
                    scanf(" %c", (char*)ptr_val);
                    insert_value(noeud_actuel->data, ptr_val);
                    break;
                case FLOAT:
                    ptr_val = (float *) malloc(sizeof(int));
                    scanf(" %f", (float *)ptr_val);
                    insert_value(noeud_actuel->data, ptr_val);
                    break;
                case DOUBLE:
                    ptr_val = (double *) malloc(sizeof(int));
                    scanf(" %lf", (double *)ptr_val);
                    insert_value(noeud_actuel->data, ptr_val);
                    break;
                case STRING:
                    ptr_val = (char *) malloc(sizeof(int));
                    scanf(" %s", (char*)ptr_val); //Todo le scanf pour les chaines avec des espaces pour éviter les bugs
                    insert_value(noeud_actuel->data, ptr_val);
                    break;
                case STRUCTURE:
                    //Todo cas structure.
                    break;
                case NULLVAL:
                    //Todo cas NULL
                    break;
            }

        }
        noeud_actuel = noeud_actuel->next;
    }
}
void delete_cdataframe(CDATAFRAME **cdf){
    lst_delete_list(*cdf);
}

void delete_column_cdf(CDATAFRAME *cdf, char *col_name){
    lnode *p = cdf->head;
    while((p->data->title != col_name) && (p->next != NULL)){
        p = p->next;
    }
    if (p->data->title == col_name)
        delete_column(&(p->data));

    else{
        printf("Colonne non trouvée\n");
    }
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
            case STRUCTURE:
                //Todo cas structure.
                break;
            case NULLVAL:
                //Todo cas NULL
                break;
        }
        noeud_actuel = noeud_actuel->next;
    }
}
#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "cdataframe.h"

int main() {
    int end = 0;
    int rep, nb_col, valide, debut, fin;
    char str[50], titre[50];
    void * ptr_val= NULL;
    ENUM_TYPE col_type;
    CDATAFRAME *cdf = create_void_cdataframe(1);

    while (end == 0){
        printf("Si vous voulez creer un Dataframe taper 1 sinon taper 0 : \n");
        scanf(" %d", &rep);
        if (rep == 1){
            printf("Entrez le nombre de colonnes que vous voulez : \n");
            scanf(" %d", &nb_col);
            ENUM_TYPE cdftype[nb_col];
            printf("La liste des types est : \nINT : Entier\nUINT : unsigned int\nCHAR : caractere simple\nFLOAT : nombres decimaux\nDOUBLE : nombres decimaux avec beaucoup de virgules\nSTRING : chaines caracteres\n\n");
            for (int i=0; i<nb_col; i++) {
                do {
                    printf("Entrez le type de la colonne [%d]: \n", i);
                    scanf(" %s", str);
                    if (strcmp(str, "INT") == 0) {
                        cdftype[i] = INT;
                        valide = 1;
                    }
                    else if (strcmp(str, "UINT") == 0){
                        cdftype[i] = UINT;
                        valide = 1;
                    }
                    else if (strcmp(str, "CHAR") == 0){
                        cdftype[i] = CHAR;
                        valide = 1;
                    }
                    else if (strcmp(str, "UINT") == 0){
                        cdftype[i] = UINT;
                        valide = 1;
                    }
                    else if (strcmp(str, "FLOAT") == 0){
                        cdftype[i] = FLOAT;
                        valide = 1;
                    }
                    else if (strcmp(str, "DOUBLE") == 0){
                        cdftype[i] = DOUBLE;
                        valide = 1;
                    }
                    else if (strcmp(str, "STRING") == 0){
                        cdftype[i] = STRING;
                        valide = 1;
                    }
                    else{
                        printf("Mauvaise saisie\n");
                        valide = 0;
                    }
                }while(valide == 0);
            }
            CDATAFRAME *cdf = create_cdataframe(cdftype, nb_col);
            fill_cdataframe(cdf);
            do {
                printf("Si vous voulez faire une modification dans le Dataframe tapez 1\n Pour l'affichage tapez 2\n Tapez 0 pour sortir\n\n");
                scanf(" %d", &rep);
                if (rep == 1){
                    printf("Pour renommer une colonne taper 1\nPour ajouter une colonne taper 2\nPour ajouter une ligne tapez 3\nPour supprimmer une colonne tapez 4\nPour supprimer une ligne tapez 5\nPour verifier l'existence d'une valeur tapez 6\nPour remplacer une valeur du dataframe tapez 7\n");
                    scanf(" %d", &rep);
                    switch (rep) {
                        case 1:
                            printf("Entrez la colonne a modifier : \n");
                            scanf(" %s", titre);
                            printf("Entrez le nouveau nom de la colonne : \n");
                            scanf(" %s", str);
                            rename_col(cdf, titre, str);
                            break;
                        case 2:

                            do {
                                printf("Entrez le type de la nouvelle colonne : \n");
                                scanf(" %s", str);
                                if (strcmp(str, "INT") == 0) {
                                    col_type = INT;
                                    ajout_col(cdf, col_type);
                                    valide = 1;
                                }
                                else if (strcmp(str, "UINT") == 0){
                                    col_type = UINT;
                                    ajout_col(cdf, col_type);
                                    valide = 1;
                                }
                                else if (strcmp(str, "CHAR") == 0){
                                    col_type = CHAR;
                                    ajout_col(cdf, col_type);
                                    valide = 1;
                                }
                                else if (strcmp(str, "UINT") == 0){
                                    col_type = UINT;
                                    ajout_col(cdf, col_type);
                                    valide = 1;
                                }
                                else if (strcmp(str, "FLOAT") == 0){
                                    col_type = FLOAT;
                                    ajout_col(cdf, col_type);
                                    valide = 1;
                                }
                                else if (strcmp(str, "DOUBLE") == 0){
                                    col_type = DOUBLE;
                                    ajout_col(cdf, col_type);
                                    valide = 1;
                                }
                                else if (strcmp(str, "STRING") == 0){
                                    col_type = STRING;
                                    ajout_col(cdf, col_type);
                                    valide = 1;
                                }
                                else{
                                    printf("Mauvaise saisie\n");
                                    valide = 0;
                                }
                            }while(valide == 0);
                            break;
                        case 3:
                            ajout_ligne(cdf);
                            break;
                        case 4:
                            printf("Entrez le nom de la colonne a supprimer : \n");
                            scanf(" %s", titre);
                            del_colonne_cdf(cdf,titre);
                            break;
                        case 5:
                            printf("Entrez le numero de la ligne a supprimer\n");
                            scanf(" %d", &rep);
                            del_ligne(cdf, rep);
                            break;
                        case 6:
                            do {
                                printf("Entrez le type valeur : \n");
                                scanf(" %s", str);
                                if (strcmp(str, "INT") == 0) {
                                    col_type = INT;
                                    valide = 1;
                                }
                                else if (strcmp(str, "UINT") == 0){
                                    col_type = UINT;
                                    valide = 1;
                                }
                                else if (strcmp(str, "CHAR") == 0){
                                    col_type = CHAR;
                                    valide = 1;
                                }
                                else if (strcmp(str, "UINT") == 0){
                                    col_type = UINT;
                                    valide = 1;
                                }
                                else if (strcmp(str, "FLOAT") == 0){
                                    col_type = FLOAT;
                                    valide = 1;
                                }
                                else if (strcmp(str, "DOUBLE") == 0){
                                    col_type = DOUBLE;
                                    valide = 1;
                                }
                                else if (strcmp(str, "STRING") == 0){
                                    col_type = STRING;
                                    valide = 1;
                                }
                                else{
                                    printf("Mauvaise saisie\n");
                                    valide = 0;
                                }
                            }while(valide == 0);
                            printf("Saisir la valeur : \n");
                            switch (col_type) {
                                case INT:
                                    ptr_val = (int *) malloc(sizeof(int));
                                    scanf(" %d", (int *) ptr_val);
                                    break;
                                case UINT:
                                    ptr_val = (int *) malloc(sizeof(int));
                                    scanf(" %d", (unsigned int *) ptr_val);
                                    break;
                                case CHAR:
                                    ptr_val = (char *) malloc(sizeof(int));
                                    scanf(" %c", (char *) ptr_val);
                                    break;
                                case FLOAT:
                                    ptr_val = (float *) malloc(sizeof(int));
                                    scanf(" %f", (float *) ptr_val);
                                    break;
                                case DOUBLE:
                                    ptr_val = (double *) malloc(sizeof(int));
                                    scanf(" %lf", (double *) ptr_val);
                                    break;
                                case STRING:
                                    ptr_val = (char *) malloc(sizeof(int));
                                    scanf(" %s", (char *) ptr_val);
                                    break;

                            }
                            if (verif_existence(cdf, ptr_val,col_type) == 1)
                                printf("La valeur existe.\n");
                            else
                                printf("La valeur n'est pas dans le tableau.\n");
                            break;
                        case 7:
                            printf("Entrez les indices de la cellule separer par un espace : \n");
                            scanf("%d %d", &debut, &fin);
                            remplacer_val(cdf, debut, fin);
                            break;
                    }
                }
                else if (rep == 2){
                    printf("Pour afficher tout le Dataframe tapez 0\nPour que certaines colonne tapez 1\nPour afficher que certaines lignes tapez 2\nPour afficher que les titres des colonnes tapez 3\n");
                    scanf(" %d", &rep);
                    switch(rep){
                        case 0:
                            print_cdataframe(cdf);
                            break;
                        case 1:
                            printf("Entrez l'intervalle dans lequel vous voulez affichez le dataframe separe par un espace : \n");
                            scanf(" %d %d", &debut, &fin);
                            print_cdataframe_column(cdf, debut, fin);
                            break;
                        case 2:
                            printf("Entrez l'intervalle dans lequel vous voulez affichez le dataframe separe par un espace : \n");
                            scanf(" %d %d", &debut, &fin);
                            print_cdataframe_ligne(cdf, debut, fin);
                            break;
                    }
                }
                else
                    end=1;

            }while(end == 0);
        }
        else
            end = 1;
    }
    delete_cdataframe(&cdf);
    return 0;
}

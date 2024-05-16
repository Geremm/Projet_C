#include <stdio.h>
#include <stdlib.h>
#include "column.h"
#include "cdataframe.h"

int main() {
    ENUM_TYPE cdftype [] = {INT,STRING};
    CDATAFRAME *cdf = create_cdataframe(cdftype, 2);
    fill_cdataframe(cdf);
    ajout_ligne(cdf);
    //print_cdataframe_column(cdf, 1, 2);
    //print_cdataframe_ligne(cdf, 2, 4);
    print_cdataframe(cdf);





//    int *Tab[5];
//    COLUMN *mycol = create_column(STRING, "Column 1");
//    char *a = NULL, *c = "Je m'appelle Geremy";
//    int val;
//    for(int i=0; i<500; i++) {
//        insert_value(mycol, c);
//        insert_value(mycol, a);
//    }
//    print_col(mycol);
    return 0;
}

#include <stdio.h>
#include "column.h"

int main() {
    COLUMN *mycol = create_column(INT, "Column 1");
    int a = 26, c = 32;
    insert_value(mycol, &a);
    insert_value(mycol, &c);
    print_col(mycol);
    delete_column(&mycol);
    return 0;
}

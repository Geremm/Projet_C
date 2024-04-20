#include <stdio.h>
#include "Functions.h"

int main() {
    COLUMN *mycol = create_column(CHAR, "Column 1");
    char a = 'A', c = 'C';
    insert_value(mycol, &a);
    insert_value(mycol, &c);
    print_col(mycol);
    delete_column(&mycol);
    return 0;
}

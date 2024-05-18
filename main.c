#include <stdio.h>
#include "column.h"

int main() {
    COLUMN *mycol = create_column("My column");
    int val = 8;
    if (insert_value(mycol, val))
        printf("Value added successfully to my column\n");
    else
        printf("Error adding value to my column\n");
    insert_value(mycol, 3);
    insert_value(mycol, 4);
    insert_value(mycol, 1);
    print_col(mycol);

    return 0;
}

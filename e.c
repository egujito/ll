#include "ll.h"
#include <stdio.h>

typedef struct {
    int integer;
    char* string;
} Custom_struct;

int main (void) {

    List list = LL_new();
    Custom_struct n_struct = { 70, "String of custom struct" };
    Custom_struct s_struct = { -1203, "Yet, another string of a custom structure" };

    LL_push(&list, &n_struct);
    LL_push(&list, &s_struct);

    Custom_struct* c_struct = *(Custom_struct**)LL_arr(&list);

    for (int i = 0; i < list.len; ++i) {
        printf("Index %d has integer %d and string \"%s\" \n", i, c_struct[i].integer, c_struct[i].string);
    }
    
    return 0;
}

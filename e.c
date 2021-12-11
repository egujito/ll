#include "ll.h"
#include <stdio.h>

typedef struct {
    int integer;
    char* string;
} Custom_struct;

int main (void) {

    List list = new();
    Custom_struct n_struct = { 70, "String of custom struct" };

    LL_push(&list, &n_struct);

    Custom_struct* c_struct = *(Custom_struct**)LL_arr(&list);

    for (int i = 0; i < list.len; ++i) {
        printf("Index %d has integer %d and string \"%s\" \n", i, c_struct[i].integer, c_struct[i].string);
    }
    
    return 0;
}

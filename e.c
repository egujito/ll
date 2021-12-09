#include "ll.h"
#include <stdio.h>

int main (void) {

    List list = new(&list);
    int val_st = 43;
    int val_nd = 59;
    int val_rd = 8;

    LL_push(&list, &val_st);
    LL_push(&list, &val_nd);
    LL_push(&list, &val_rd);
    
    LL_pop(&list); // Macro that traslates to LL_remove(&list, list.len - 1);

    int* arr = *(int**)LL_arr(&list);
    
    for (int i = 0; i < list.len; ++i) {
        printf("Index has value -> %d \n", arr[i]);
    }
    return 0;
}

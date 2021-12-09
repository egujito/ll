#include "ll.h"
#include <stdio.h>

int main (void) {

    List list = new(&list);
    LL_push(&list, 43);
    LL_push(&list, 59);
    LL_push(&list, 8);
    
    LL_pop(&list); // Macro that traslates to LL_remove(&list, list.len - 1);

    int* arr = LL_arr(&list);

    for (int i = 0; i < list.len; ++i) {
        printf("Index has value -> %d \n", arr[i]);
    }
    return 0;
}

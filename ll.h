#ifndef LL_H
#define LL_H

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define LL_pop(L) LL_remove(L, *L.len - 1)

struct Node {
    struct Node *next;
    void* data;
};

typedef struct {
    struct Node *start;
    size_t size;
    int len;
} List;

List LL_new(void); /* Create new linked list */
void LL_remove(List* list, int index); /* Remove item at the give index */
void LL_push(List *list, void* data); /* Add item to the last index */
void** LL_arr(List *list); /* convert Linked list to fixed size array */
size_t LL_size(List *list); /* Used to get and update the size of the list*/

List LL_new(void) {
    List list = { NULL, 0, 0, };
    return list;
}

void LL_push(List *list, void* data) {
    
    struct Node* iter = NULL;
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    if (list->start == NULL) {
        list->start = n;
        n->next = NULL;
    } else {
        iter = list->start;

        while(iter->next != NULL) {
            iter = iter->next;
        }

        iter->next = n;
        n->next = NULL;
    }
    list->size = LL_size(list);
    list->len++;
}

void LL_remove(List* list, int index) {

    assert(list->start != NULL);
    assert(index < list->len && index >= 0);

    int i = 0;

    struct Node* t = list->start;
  
    if (index == 0)
    {
        list->start = t->next;
        free(t);
        list->size = LL_size(list);
        list->len--;
        return;
    }
  
    while (t != NULL && i < index - 1) {
         ++i;
         t = t->next;
    }
  
    struct Node *next = t->next->next;
  
    free(t->next);
  
    t->next = next;
    list->size = LL_size(list);
    list->len--;    
}

size_t LL_size(List* list) {
    size_t s = 0;
    struct Node* t = NULL;
    if (list->start == NULL)
        return 0;
    else {
        t = list->start;
        while (t != NULL) {
            t = t->next;
            s++;
        }
    }
    return s * sizeof(struct Node);
}
 
void** LL_arr(List* list) {
    assert(list->start != NULL);

    void** arr = (void*)malloc(sizeof(void) * list->size);  
    struct Node* t = NULL;
    int i = 0;
    t = list->start;
    while (t != NULL) {
        arr[i] = t->data;
        t = t->next;
        i++;
    }
    return arr;
}

#endif

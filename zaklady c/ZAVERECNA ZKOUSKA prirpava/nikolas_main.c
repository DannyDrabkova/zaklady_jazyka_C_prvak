#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void List_Init(List *list) {
    if (list == NULL) {
        return;
    }
    list->first = NULL;
    list->active = NULL;
    printf("Initialized successfully.\n");
}

void Insert_End(List *list, int value) {
    Node *node;
    node = malloc(sizeof(Node));
    if (node == NULL) return;

    node->data = value;
    node->next = NULL;
    if (list->first == NULL) {
        list->first = node;
    } else {
        Node *last = list->first;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = node;
    }
}

int Reduce_Multiply(int product, Node *node) {
    if (node == NULL) {
        return product;
    }

    // return reduceMultiply(product, node->next) * node->data;
    product = product * node->data;
    return Reduce_Multiply(product, node->next);
}

int main() {
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    size_t array_size = sizeof(values) / sizeof(int);

    // list initalization
    List *list = malloc(sizeof(Node) * array_size);
    List_Init(list);
    for (int i = 0; i < array_size; i++) {
        Insert_End(list, values[i]);
    }

    list->active = list->first;
    while (list->active != NULL) {
        printf("%d  ", list->active->data);
        list->active = list->active->next;
    }

    int sum = 1;
    list->active = list->first;
    printf("\nMultiplication: %d\n", Reduce_Multiply(sum, list->active));

    free(list);
    printf("Freed successfully.\n");
    return 0;
}

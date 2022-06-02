#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "math.h"

struct node {
    int value;
   struct node *next;
};

typedef struct node node_t;

node_t  *create_new_node(int value) {
    node_t * tmp;
    tmp = malloc(sizeof (node_t));
    tmp->value = value;
    tmp->next = NULL;

    return tmp;
}




void * print_linkedlist (node_t * head) {
    node_t  *tmp = head;
    while(tmp!= NULL) {
        printf("%d - ", tmp->value);
        tmp = tmp->next;
    }

}

node_t  *inser_at_start (node_t *head, node_t *node_to_add) {

    node_to_add ->next = head;
    return node_to_add;
}


node_t *filterEven (node_t *head) {
    node_t * tmp = head;
    node_t * even;
    node_t *head_even = NULL;

    while( tmp->next!= NULL) {
        if(tmp->value %2 == 0){
            even = create_new_node(tmp->value);
            // pouziti predchozi predpripravene funkce  funkce pro:
            //tmp = malloc(sizeof (node_t));
            //tmp->value = value;
            //tmp->next = NULL;
            head_even = inser_at_start(head_even,even);
            // pouziti predpripravene funkce - zkratka pro:
            //node_to_add ->next = head;
            //return node_to_add;

        }
        tmp= tmp->next;
    }

    print_linkedlist(head_even);
    return head_even;

}

void *filterEvenOdd (node_t *head) {
    node_t * tmp = head;
    node_t * even;
    node_t *head_even = NULL;
    node_t * odd;
    node_t *head_odd = NULL;
    while( tmp->next!= NULL) {
        if(tmp->value %2 == 0){
            even = create_new_node(tmp->value);
            // pouziti predchozi predpripravene funkce  funkce pro:
            //tmp = malloc(sizeof (node_t));
            //tmp->value = value;
            //tmp->next = NULL;
            head_even = inser_at_start(head_even,even);
            // pouziti predpripravene funkce - zkratka pro:
            //node_to_add ->next = head;
            //return node_to_add;
        }else {
            odd = create_new_node(tmp->value);
            // pouziti predchozi predpripravene funkce  funkce pro:
            //tmp = malloc(sizeof (node_t));
            //tmp->value = value;
            //tmp->next = NULL;
            head_odd = inser_at_start(head_odd,odd);
            // pouziti predpripravene funkce - zkratka pro:
            //node_to_add ->next = head;
            //return node_to_add;
        }
        tmp= tmp->next;
    }
    printf("even: "); print_linkedlist(head_even);
    printf("\n");
    printf("odd: ");print_linkedlist(head_odd);

}

int main() {
  node_t *list, *head = NULL;

    for (int i = 0; i < 8; ++i) {
        list =  create_new_node(i);
        head = inser_at_start(head,list);
    }

    printf("puvodni: ");print_linkedlist(head);
    printf("\n");

    printf("\n");
    printf("odd: ");filterEvenOdd(head);



}

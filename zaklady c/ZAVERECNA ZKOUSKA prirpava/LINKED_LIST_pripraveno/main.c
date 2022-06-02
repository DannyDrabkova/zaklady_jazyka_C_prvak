#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "math.h"

struct node {
    int value;
    struct node *next;
};
typedef struct node node_t;

void printlist(node_t *head) {
    node_t  *temporary = head;
    while (temporary != NULL) {
        printf("%d - ", (temporary->value));
        temporary = temporary->next;
    }
    printf("\n");
}




int someEven(node_t * head ) {
    node_t * temporary = head;
    while(temporary != NULL) {
        if(temporary->value % 2 == 0) {
            printf("\n1(true)\n");
            return 1;
        }

        temporary = temporary->next;
    }


}

int someEven_recursion(node_t * head ) {
    node_t * temporary = head;

    if(temporary != NULL) {
        if(temporary->value % 2 == 0) {
            printf("\n1(true)\n");
            return 1;
        }
        someEven_recursion(temporary);

    }

}

node_t * insert_at_head(node_t *head, node_t *node_to_insert) {
    node_to_insert->next = head;
    return  node_to_insert;
    // node_to_insert  = symplify
    // tmp->next = head;
    //  head = tmp;

}
node_t * create_new_node (int value) { // vrati mi to strukturu...
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;

}




void * insert_at_end (node_t * head, node_t *node_to_insert) {
   node_t *tmp = head;
   while(tmp->next != NULL) {
   tmp = tmp->next;
   }
   tmp->next = node_to_insert;

}

void *insert_after_node(node_t *head, node_t *node_to_insert, int k) { //vloz po prvku cislo "k"
    node_t *tmp = head;
    int count = 0;

    while (tmp != NULL) {
        count++;
        if (count == k) break;
    }
    node_to_insert->next = tmp->next;
    tmp->next = node_to_insert;

}


void squarelist_recursion(node_t* head,double power) {
    node_t  *temporary = head;
    if(temporary != NULL) {
        temporary->value = pow(temporary->value, power);
        temporary = temporary->next;
        squarelist_recursion(temporary, power);
    }

}

int scitani(node_t *head) {
    int num = 0;
    node_t  *temporary = head;
    while (temporary != NULL) {
        num = num + temporary->value;
        temporary = temporary->next;
    }
    return num;
}


void reverse(node_t **head) {  // fungovalo to jen s DVEMA HVEZDICKAMA, PROC???
    node_t *next, *prev = NULL;
    node_t  *current = *head;
    while (current!= NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;

}





void makeloop(node_t ** head, int k)
{
    node_t* temp = *head;
    int count = 1;
    while (count < k) {
        temp = temp->next;
        count++;
    }

    // backup the joint point
    node_t* joint_point = temp;

    // traverse remaining nodes
    while (temp->next != NULL)
        temp = temp->next;

    // joint the last node to k-th element
    temp->next = joint_point;
}


bool isCircular( node_t *head)
{
    node_t *slow = head;
    node_t *fast = head->next;

    while (fast != NULL && fast != slow)
        fast = fast->next;

    return (fast == slow);
}






int main() {

    node_t  *head = NULL;
    node_t  *tmp;

    for (int i = 0; i < 4; i++) { //function, which creates new nodes...
        tmp = create_new_node(i); // tahle vytvori novy node
        head = insert_at_head(head,tmp); // tahle funkce novy noud prida DOPREDU /push
    }

    tmp = create_new_node(10);
    insert_at_end(head,tmp);

    tmp = create_new_node(200);
    insert_after_node(head,tmp,0);

    //tmp = create_new_node(32); // nova funkce je dava NA ZACATEK LISTU...
    //head = tmp;
    //tmp = create_new_node(8);
    // tmp->next = head;
    // head = tmp;


    printlist(head);
    printf("list na mocninu xx: ");squarelist_recursion(head,2);
    printlist(head);
    printf("soucet prku : %d\n", scitani(head));
    reverse(&head);
    printf("obraceny list: ");printlist(head);
    printf("---\n");
    makeloop(&head,1); //
    printf("is a loop 1 yes, 0 no : %d\n", isCircular(head));
    someEven(head);
    someEven_recursion(head);





    return 0;
}

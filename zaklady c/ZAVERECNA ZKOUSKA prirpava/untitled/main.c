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


node_t * create_new_node (int value) { // vrati mi to strukturu...
    node_t *result = malloc(sizeof(node_t));
    result->value = value;
    result->next = NULL;
    return result;

}

node_t *insert_at_head(node_t *head, node_t *node_to_insert) {
   node_to_insert->next = head;
    return  node_to_insert;
    // symplify
   // tmp->next = head;
    //   head = tmp;

}


 void squarelist(node_t* head,double power) {
    node_t  *temporary = head;
   if(temporary != NULL) {
            temporary->value = pow(temporary->value, power);
            temporary = temporary->next;
            squarelist(temporary, power);
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
       tmp = create_new_node(i);
       head = insert_at_head(head,tmp); // tohle zjednodusila funkce insert_a_head

    }

    //tmp = create_new_node(32); // nova funkce je dava NA ZACATEK LISTU...
   // head = tmp;
    //tmp = create_new_node(8);
   // tmp->next = head;
   // head = tmp;


    printlist(head);
    squarelist(head,2);
    printlist(head);
    printf("%d\n", scitani(head));
    reverse(&head);
    printlist(head);
    printf("---\n");
    makeloop(&head,1); //
    printf("is a loop %d\n", isCircular(head));








    return 0;
}

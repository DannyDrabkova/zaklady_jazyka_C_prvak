#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;


};
void makeloop(struct Node** head_ref, int k) /// this WILL MAKE A LOOP !!!!
{
    // traverse the linked list until loop
    // point not found
    struct Node* temp = *head_ref;
    int count = 1;
    while (count < k) {
        temp = temp->next;
        count++;
    }

    // backup the joint point
    struct Node* joint_point = temp;

    // traverse remaining nodes
    while (temp->next != NULL)
        temp = temp->next;

    // joint the last node to k-th element
    temp->next = joint_point;
}


void findloop(struct Node *head) { // THIS WILL SAY IF THERE IS A LOOP
    struct Node *slow, *fast;
    slow = fast = head;

    while(slow && fast && fast->next) {
        /* Slow pointer will move one node per iteration whereas
        fast node will move two nodes per iteration */
        slow = slow->next;
        fast  = fast->next->next;
        if (slow == fast) {
            printf("Linked List contains a loop\n");
            return;
        }
    }
    printf("No Loop in Linked List\n");
}


int main() {

    int item = 10; // prvni polek linked listu
    // pocet prvku v linked listu
    struct Node *arrowPointer, *linkedList, *head; // pointer na strukturu - arrow pointer je pointer,ktery bude prochazet linked list
    linkedList = (struct Node *) malloc(sizeof( struct Node));  //
    linkedList->data = item;
    linkedList->next = NULL;
    head = linkedList; // prvni prvek jsme oznacili jako HEAD...
    arrowPointer = head;


    int arr[] = {2,20,45,63,724,324,7};
    int n = 8;
    for (int i = 0; i < n; i++) {
        linkedList = (struct Node *) malloc(sizeof( struct Node));
        linkedList->data = arr[i];
        linkedList->next = NULL;
        arrowPointer->next = linkedList;
        arrowPointer = arrowPointer ->next;
    };



    arrowPointer = head; // nastavili jsme prochazejici pointer na zacatek...


    while(arrowPointer!= NULL) { // dopokavad arrowpointer neukazuje na nulu - konecny prvek, tak budeme prochazet linked list
        printf("%d ", arrowPointer->data);
        arrowPointer = arrowPointer->next;
    }
    printf("\n");

    makeloop(&head, 4);

    findloop(head);




}
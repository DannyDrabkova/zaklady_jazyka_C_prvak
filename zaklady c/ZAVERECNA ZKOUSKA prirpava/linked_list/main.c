#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node *next;


};

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
    int n = (sizeof(arr)/4);
    for (int i = 0; i < n; i++) {
        linkedList = (struct Node *) malloc(sizeof( struct Node));
        linkedList->data = arr[i];
        linkedList->next = NULL;

        arrowPointer->next = linkedList;
        arrowPointer = arrowPointer ->next;
    };

    arrowPointer = head; // nastavili jsme prochazejici pointer na zacatek...


    int count = 0;
    while(arrowPointer!= NULL) { // dopokavad arrowpointer neukazuje na nulu - konecny prvek, tak budeme prochazet linked list
        printf("%d ", arrowPointer->data);
        arrowPointer = arrowPointer->next;
        count++;
}
    printf("\n");
    printf("Pocet prvku v poli je: %d", count);




}
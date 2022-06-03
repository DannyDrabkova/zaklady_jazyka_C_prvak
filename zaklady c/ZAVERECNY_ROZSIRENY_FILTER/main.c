#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    int value;
    struct node *next;
};

struct evenodd{
     struct node *odd;
        struct node *even;
};

typedef struct node node_t;
typedef struct evenodd EvenOdd;

/**
 * Function creates a new node of linked list
 * @param value of a new node of linkedlist
 * @return  return a new node of linkedlist
 */
node_t *create_new_node(int value) {
    node_t *tmp;
    tmp = malloc(sizeof(node_t));
    tmp->value = value;
    tmp->next = NULL;

    return tmp;
}


 /**
  * Function prints given linkedlist
  * @param head takes a head element of linkedlist
  * @return non return function
  */
void *print_linkedlist(node_t *head) {
    node_t *tmp = head;
    while (tmp != NULL) {
        printf("%d - ", tmp->value);
        tmp = tmp->next;
    }
}

node_t *inser_at_start(node_t *head, node_t *node_to_add) {

    node_to_add->next = head;
    return node_to_add;
}

/**
 * Function iterates through linked list and finds even elements
 * @param head takes head of given linked list
 * @return 0 if there is no even member, 1 if there is even element
 */
int someEven_rec(node_t *head) {
    node_t *temporary = head;
    if (temporary->next != NULL) {
        if (temporary->value % 2 == 0) {
            return 1;
        }
    } else {
        return 0;
    }
    return someEven_rec(head->next);
}


node_t *even_t;
node_t *head_even_t = NULL;
node_t *odd_t;
node_t *head_odd_t = NULL;
EvenOdd evenOdd;


/**
 * Function iterates through linked list, separates even and odd elements. Then copies references of heads elements
 * of a new (odd and even) linked lists into a new structure.
 * @param head takes head of given linked list
 * @return Function returns struct evenodd
 */
struct evenodd* filterEvenOdd(node_t *head) {
    node_t *tmp = head;
    while (tmp->next != NULL) {
        if (tmp->value % 2 == 0) {
            even_t = create_new_node(tmp->value);
            head_even_t = inser_at_start(head_even_t, even_t);
        } else {
            odd_t = create_new_node(tmp->value);
            head_odd_t = inser_at_start(head_odd_t, odd_t);
        }
        tmp = tmp->next;
    }

    evenOdd.even =  malloc(sizeof (node_t));
    memcpy(evenOdd.even,head_even_t,sizeof (*head_even_t));
    evenOdd.odd =  malloc(sizeof (node_t));
    memcpy(evenOdd.odd,head_odd_t,sizeof (*head_odd_t));
    return &evenOdd;


}


int main() {
    node_t *list, *head = NULL;

    for (int i = 0; i <= 8; ++i) {
        list = create_new_node(i);
        head = inser_at_start(head, list);
    }

    printf("Puvodni linked list : ");
    print_linkedlist(head);
    printf("%d obsahuje even? ",someEven_rec(head));
    printf("\n");
    printf("\n-- FUNGUJICI VERZE -- \n");
    filterEvenOdd(head)->even;
    print_linkedlist(head_even_t);
    printf("\n");
    print_linkedlist(head_odd_t);


    printf("\n-- kopirovani do struktur  \n");
    print_linkedlist(evenOdd.even);
    printf("\n");
    print_linkedlist(evenOdd.odd);













}

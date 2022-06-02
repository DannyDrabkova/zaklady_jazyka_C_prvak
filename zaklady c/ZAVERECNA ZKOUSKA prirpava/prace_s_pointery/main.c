#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {



    //prace s pointery a jejich adresou
int a = 10;
int b = 16;
int c = 200;
int * p_p = &a;

p_p = &c;

    printf("adresa drzena v pointeru: %d\n", p_p);
    printf("adresa cisla C je %d\n", p_p);
    printf("Hodnota v pointeru: %d\n", *p_p);


    *p_p = b;

    printf("adresa drzena v pointeru: %d\n", p_p);
    printf("Hodnota v pointeru: %d\n", *p_p);


    //ALOKACE DYNAMICK
/**
  int * tmp = NULL;
  tmp = malloc(100);
  int arr [] = {3,5,6,33,5,7,};

    memmove(tmp,arr,sizeof(arr));


    for (int i = 0; i < sizeof(arr)/4; ++i) {
        printf("%d ", *(tmp+1));

    }

*/

}

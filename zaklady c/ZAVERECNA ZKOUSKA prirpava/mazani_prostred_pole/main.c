#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    int arr [] = {35,3,555,6,3,5,66};
    int size = 0;

  int * dynamic = arr;
    int index = 2;
    int *tmp;
    tmp = malloc(sizeof(arr)-4);

    memmove(tmp,arr,sizeof(int)*index);
    memmove(tmp+index,arr+index+1,sizeof(int)*(7-2));

    printf("%d\n ", tmp); // v pameti 01230
    printf("%d\n ", tmp+1); // v pameti 01234

    for (int i = 0; i < (sizeof(arr)-4)/4; ++i) {
        printf("%d ",*(tmp+i));
    }



}



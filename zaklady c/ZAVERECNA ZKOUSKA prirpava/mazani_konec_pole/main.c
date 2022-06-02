#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {


    int arr[] = {2,5,6,7,33};
    int *copy;
    copy = malloc(sizeof(arr) / sizeof (arr[1]) -1);
    memmove(copy,arr,16);


    printf("%d\n",(sizeof (arr)/4)-1);

    for (int i = 0; i < (sizeof (arr)/4)-1; ++i) {
        printf("%d ", copy[i]);
    }



}

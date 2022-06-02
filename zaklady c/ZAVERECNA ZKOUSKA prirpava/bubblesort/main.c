#include <stdio.h>
void bubble_sort(int *arr, int size, int k) {


    int tmp = 0;
    for (int i = 0; i < size; i++) {
        if(k == i) break;
        for (int j = 0; j < size-1; j++) {
            if (arr[i] > arr[j]) {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }

    }
}



int main() {



    int arr [] = {10,27,4,40,45,208,20};
    int lenght = sizeof(arr)/ sizeof (arr[4]);

    printf("%d\n", lenght);
    bubble_sort(arr,lenght,lenght);

    for (int i = 0; i < lenght; ++i) {
        printf("%d ",arr[i]);
    }



}

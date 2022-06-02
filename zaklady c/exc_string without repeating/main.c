#include <stdio.h>
//Write a C program to find length of the longest substring of a given string without repeating characters. Go to
int main() {
    char string [50]={"abcabc"};
    size_t size = sizeof (string);
    int tmp[50];
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size-1; ++j) {
            if(string[i] == string[j]){
                printf("%c", string[i]);

            }else{
                continue;
            }

        }

    }


}

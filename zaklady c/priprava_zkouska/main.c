#include <stdio.h>
#include <string.h>

int main() {
  char vstup[]={"Hello World! 12345"};
    int size = strlen(vstup);
int count = 0;


    for (int i = 0; i <= size; ++i) {
    if(vstup[i] >= '0' && vstup[i] <='9'){
        count++;
    }
    }
    printf("%s\n",vstup);
    printf("Numbers contained: %d",count);
}

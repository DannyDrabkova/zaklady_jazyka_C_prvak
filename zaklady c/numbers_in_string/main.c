#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


int main() {

    char str[]= "Hello World! 12345773884";
    int pocet = 0;

    for (int i = 0; i < sizeof (str); ++i) {

            if(str[i] >= '0' && str[i]<='9') {
                pocet++;
        }

    }

    printf("%s\n", str);
    printf("Numbers contained: %d", pocet);


}





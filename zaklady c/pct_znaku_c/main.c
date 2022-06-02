#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>


int printText( const char *text) {

    size_t length = strlen(text);
    int pocet= 0;

    for (int i = 0; i < length ; ++i) {
        if(!text) {
            return -1;
        }
        else{
            pocet++;

        }
    }

    return pocet;
}

int main() {

    char str[] = "Ahoj";
    char * p = &str;

    printf("%d",printText(p));

}





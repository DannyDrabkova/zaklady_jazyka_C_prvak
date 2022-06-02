#include <stdio.h>
#include <string.h>

int printText(const char *text) {
    if(*text == NULL){
        return printf("-1");
    }
    size_t size = strlen (text);
    int count = 0;
    for (int i = 0; i < size; ++i) {
        count++;
    }
    return printf("%d",count);
}

int main() {

  const char * znak = "";
   printText(znak);



}

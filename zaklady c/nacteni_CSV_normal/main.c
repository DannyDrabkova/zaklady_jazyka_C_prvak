#include <stdio.h>
#include <malloc.h>
#include <string.h>
int main() {
    char jmeno[40];
 char * buff = malloc(200);
 char * tmp;
 FILE * file = fopen("D:\\PROGRAMOVANI\\zaklady c\\nacteni_CSV_normal\\example.csv", "r");


 fgets(buff,199,file);
 printf("%s\n", buff);
 printf("%d", strlen(buff));


    int i = 0;
    /*while( fgets(buff,199,file)){
        if(strlen(buff) > 0 && (buff[strlen(buff)-1] == "\n" )){
            buff[strlen(buff)-1] = "\0";
        }

        tmp = strtok(buff,",");
        strcpy(jmeno,tmp);
    }
    printf("%s",jmeno);*/



}

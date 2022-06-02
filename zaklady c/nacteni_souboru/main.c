#include <stdio.h>
#include <string.h>
#include <stdlib.h>


// another possible way
//struct User {
//    int age;
//};

typedef struct {
    char name[10];
    int age;
    char street[10];
} User;


User getFirstUser(User users[], size_t length) {
    User first = users[0];

    return first;
}

int main() {
    //User user = {"Adam", 5, "Zlin 152"};
    User user;
    strcpy(user.name, "Adam");
    user.age = 5;
    strcpy(user.street, "Zlin");

    User novy = user;

    user.name[0] = 'O';


    printf("%s\n", user.name);
    printf("%s\n", novy.name);

    User users[10];
    // problem: telefonni seznam





    FILE *bookFile;

    /* allocation of the buffer for every line in the File */
    char *buf = malloc(256);
    char *tmp;

    /* if the space could not be allocaed, return an error */
    if (buf == NULL) {
        printf("No memory\n");
        return 1;
    }

    bookFile = fopen("D:\\PROGRAMOVANI\\zaklady c\\nacteni_souboru\\example.csv", "r");

    if (bookFile == NULL) {
        printf("File could not be opened.\n");
    }

    int i = 0;
    while (fgets(buf, 255, bookFile) != NULL) { // 1. kam to nacitam 2. velikost kam to nacitam 3. z ceho nacitam
        if ((strlen(buf) > 0) && (buf[strlen(buf) - 1] == '\n')) //pokud je delka buf vetsi jak 0 a zaroven je posledni znak = entru
            buf[strlen(buf) - 1] = '\0'; // posledni znak (enter)  nahrad 0

        if (i > 9) {
            printf("%s\n", "ERROR:ABC1234");
            exit(1);
        }

        tmp = strtok(buf, ","); // rozdel string pomoci ,
        //no more delimiters
        if (tmp == NULL) {
            printf("End.\n");
            break;
        }

        strcpy(users[i].name, tmp); // do username 0 vloz

        tmp = strtok(NULL, ",");

        users[i].age = atoi(tmp); // konvertuje string do int - ulozi do age

        tmp = strtok(NULL, ",");
        strcpy(users[i].street, tmp);

        printf("index i= %i  name: %s age: %d street: %s\n", i, users[i].name, users[i].age, users[i].street);
        i++;
    }

    free(buf);

    fclose(bookFile);


    User first = getFirstUser(users, 5);

    printf("%s %s %d\n", first.name, first.street, first.age);

    return 0;
}
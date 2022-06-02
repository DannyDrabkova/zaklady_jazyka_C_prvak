#include <stdio.h>
#include <string.h>


typedef struct {
    char name[50];
    int age;
    char street[50];
} User;

User sort(User users[], size_t lenght) {
    User tmp;
    for (int i = 0; i < lenght; ++i) {
        for (int j = i + 1; j < lenght; ++j) {
            if (strcmp(users[i].name, users[j].name) > 0) {
                tmp = users[i];
                users[i] = users[j];
                users[j] = tmp;
            }
        }
    }
};


int main() {
    User users[2];
    size_t size = sizeof users / sizeof users[0];


    strcpy(users[0].name, "Zaneta");
    users[0].age = 17;
    strcpy(users[0].street, "Albertova");

    strcpy(users[1].name, "Aneta");
    users[1].age = 19;
    strcpy(users[1].street, "Osvoboditelu");

    User temp;
    temp = users[1];

    /*User tmp;
    for (int i = 0; i < 2; ++i) {
        for (int j = i+1; j < 2; ++j) {
            if (strcmp(users[i].name, users[j].name) > 0) {
                tmp = users[i];
                users[i] = users[j];
                users[j] = tmp;
            }
        }
    }*/

    sort(users,size);

    for (int i = 0; i < 2; ++i) {

        printf("%s\n", users[i].name);
        printf("%d\n", users[i].age);
        printf("%s\n", users[i].street);
    }


}

#include <stdio.h>
#include <string.h>
typedef struct {
    char name[50];
    int age;
    char street[50];
} User;

int main() {

    User user[2];
    User tmp;

    strcpy(user[0].name, "Jana");
    user[0].age = 11;
    strcpy(user[0].street, "Albertova");


    strcpy(user[1].name, "Alena");
    user[1].age = 33;
    strcpy(user[1].street, "Albertova");



for(int i = 0; i <= 2; i++){
    for (int j = 0; j <= 2; ++j) {
        if(user[i].name > user[i].name[i+1]){
            tmp = user[i];
           user[i]=user[i+1];
           user[i+1]=tmp;
        }

    }
}
    printf("%s", user[0].name);
}

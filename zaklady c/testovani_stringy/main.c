#include <stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct User {
    char * znamky;

}User;
int main() {

    // me to opravdu doma funguje :D tak snad to bude dobre...  :]:]

    User * user =  (User *) malloc(sizeof(User));
    user->znamky = "Puvodni string 2X...";
    printf("%s\n", user->znamky);


    User *copyUser;
    copyUser =  (User*) malloc(sizeof(User));
    copyUser->znamky =strdup(user->znamky);

    printf("%s\n", copyUser->znamky); //zkopirovany string - test

    copyUser->znamky = "Zmena copy stringu... "; // novy string - test zda prepise...
    printf("%s", copyUser->znamky);



    free(user);
    free(copyUser);


}
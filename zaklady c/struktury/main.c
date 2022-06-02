#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct User {
    char *name;
    int age;
}User;




    char *test = (char*) malloc(12*sizeof(char));
    strcpy(test, "testingonly");
    for (int i = 0; i <20; ++i) {
        printf("%s", *(test +i));

    }


}




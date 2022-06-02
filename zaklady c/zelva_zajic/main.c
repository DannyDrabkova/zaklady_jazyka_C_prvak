#include <stdio.h>
#include "math.h"
#include <float.h>

#define f(x) 2*x*x*x - 13*x*x - 2*x - 50
#define g(x) 6*x*x - 26*x - 2 // derivace funkce sx

double newton(double x0) {
    double f0 = f(x0);
    double g0 = g(x0);
    return x0 - f0/g0; // tohle je dany algoritmus
}

double zelva_zajic(double x0){

    double zelva = newton(x0); //prvni hodnota funkce newton
    double zajic = newton(newton(x0)); // druha hodnota funkce newton

    while(zajic != zelva) {
        zelva = newton(zelva);
        zajic = newton(newton(zajic));
    }

    return zelva;

}



int main() {

    double zkouska = zelva_zajic(8);

    printf("----------\n");
    double n = newton(8);

    for (int i = 0; i < 3; ++i) {
        n = newton(n);
        printf("iterace %i - %.50lf \n", i, n);
    }

    return 0;
}

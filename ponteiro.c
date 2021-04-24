#include <stdio.h>

int main(){
    int x = 47;
    int* y = &x;

    *y = 26;

    printf("Valor atual de x: %i\n", x);

    return 0;
}


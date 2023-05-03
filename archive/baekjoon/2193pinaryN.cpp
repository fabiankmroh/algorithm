#include <stdio.h>

long long pinaryA[91];

int main( void ){
    int input;

    scanf("%d", &input);

    fflush(stdin);

    pinaryA[1] = 1;
    pinaryA[2] = 1;


    for(int i = 3; i <= input; i++){
        pinaryA[i] = pinaryA[i-1] + pinaryA[i-2];
    }

    printf("%d\n", pinaryA[input]);
    return 0;
}
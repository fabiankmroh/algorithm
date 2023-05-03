#include <stdio.h>

int main(void){
    int c[1001];
    int input;
    int i;

    c[0] = 1;
    c[1] = 1;

    scanf("%d", &input);
    for(i = 2; i <= input; i++){
        c[i] = c[i-1] + c[i-2];
        c[i] %= 10007;
    }

    printf("%d\n", c[input]);
}
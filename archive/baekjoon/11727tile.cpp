#include <stdio.h>

int main( void ){
    int n[1001];
    int i; 
    int input;

    scanf("%d", &input);

    n[0] = 1;
    n[1] = 1;
    for(i = 2; i <= input; i++){
        n[i] = 2 * n[i-2]+ n[i-1];
        n[i] %= 10007;
    }

    printf("%d\n", n[input]);
    return 0;
}
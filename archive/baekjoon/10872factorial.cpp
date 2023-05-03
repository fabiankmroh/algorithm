#include <stdio.h>

int main(void){
    int input;
    long long ans = 1;

    scanf("%d", &input);
    for(int i = 1; i <= input; i++){
        ans *= i;
    }
    
    printf("%lld\n", ans);
}
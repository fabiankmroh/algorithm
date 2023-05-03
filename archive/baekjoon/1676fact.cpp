#include <stdio.h>

int main(void){
    int ans = 0;
    int input;
    int i;

    scanf("%d", &input);

    for(i = 5; i<= input; i*=5){
        ans += input / i;
    }
    
    printf("%d\n", ans);
}
#include <stdio.h>

int main(void){
    int input;
    int i;

    scanf("%d\n", &input);
    for(i = 2; i*i <= input; i++){
        while(input % i == 0){
            printf("%d\n", i);
            input /= i;
        }
    }

    if(input > 1){
        printf("%d\n", input);
    }


}
#include <stdio.h>

int main(void){
    long long dig = 1;
    int input;
    int zerocount = 0;
    int i;

    scanf("%d", &input);
    for(i = 1; i <= input; i++){
        dig *= i;
    }

    while(dig){
        int oneD = dig % 10;
        if(oneD == 0){
            zerocount++;
        }

        dig /= 10;
    }

    printf("%d\n", zerocount);
}
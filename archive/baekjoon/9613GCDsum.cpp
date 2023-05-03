#include <stdio.h>

int GCD(int a, int b){
    int r;
    while(b != 0){
        r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int main(void){
    int caseL;


    scanf("%d", &caseL);
    
    while(caseL--){
        int input[111];
        int arrayL;
        int i;
        int j;
        long long sum = 0;

        scanf("%d", &arrayL);

        for(i = 0;i < arrayL; i++){
            scanf("%d", &input[i]);
        }

        for(i = 0; i < arrayL-1; i++){
            for(j = i+1; j < arrayL; j++){
                sum += GCD(input[i], input[j]);
            }
        }

        printf("%lld\n", sum);
    }
    
    return 0;
}
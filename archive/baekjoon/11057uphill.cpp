#include <stdio.h>

int main(void){
    int i;
    int j;
    int k;
    int arrayC[1000][10];
    int input;   

    scanf("%d", &input);

    for(i = 0; i <= input; i++){
        for(j = 0; j <= 9; j++){
            arrayC[i][j] = 1; 
        }
    }

    for(i = 2; i <= input; i++){
        for(j = 2; j <= 9; j++){
            for(k = 0; k <= j; k++){
                arrayC[i][j] += arrayC[i-1][k];
                arrayC[i][j] %= 10007;
            }
        }
    }

    long long ans = 0;
    for(i = 0; i < 10; i++){
        ans += arrayC[input][i];
    }
    ans %= 10007;

    printf("%d\n", ans);
}
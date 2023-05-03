#include <stdio.h>

int main(void){
    char twobitL[1000000];
    int eightbitO[1000000];
    int i;
    int tenbitT = 0;

    scanf("%c\n", twobitL);
    
    i = 0;
    while(twobitL[i] != '\0'){
        tenbitT = tenbitT * 2 + (twobitL[i] - '0');
        i++;
    }
    
    i = 0;
    while(tenbitT > 0){
        int r = tenbitT % 8;
        eightbitO[i] = r;
        i++;
        tenbitT /= 8;
    }

    for(int j = i; j >= 0; j--){
        printf("%d", eightbitO[j]);
    }
    printf("\n");
    
}

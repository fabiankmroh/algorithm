#include <stdio.h>
/* commit trial comment */

int main(void){
    const int MAX = 1000000;
    int primeS[MAX];
    int statusNP[MAX+1] = {false, };
    int pn = 0;
    statusNP[1] = true;

    int i;
    int j;
    int tmpI;

    for(i = 2; i <= MAX; i++){
        if(statusNP[i] == false){
            primeS[pn++] = i;            
            for(j = 2*i; j <= MAX; j+=i){
                statusNP[j] = true;
            }  
        }
    }

    while(true){
        scanf("%d", &tmpI); 

        if(tmpI == 0){
            break;
        }

        for(i = 1; i < pn; i++){
            if(statusNP[tmpI - primeS[i]] == false){
                printf("%d = %d + %d\n", tmpI, primeS[i], tmpI - primeS[i]);
                break;
            }
        }
    }

    return 0;
}
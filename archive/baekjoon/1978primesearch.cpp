#include <stdio.h>

bool isPrime(int input){
    int i;

    if(input < 2){
        return false;
    }

    for(i = 2; i < input; i++){
        if(input % i == 0 ){
            return false;
        }
    }

    return true; 
}

int main(void){
    int numC;
    int tmp;
    int pC = 0;
    int i;

    scanf("%d", &numC);
    for(i = 0; i < numC; i++){
        scanf("%d", &tmp);
        if(isPrime(tmp) == true){
            pC++;
        }
    }

    printf("%d\n", pC);
}
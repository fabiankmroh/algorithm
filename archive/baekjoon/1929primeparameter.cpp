#include <stdio.h>
/* commit trial comment */
bool isPrime(long long input){
    long long i;

    if(input < 2){
        return false;
    }

    for(i = 2; i*i <= input; i++){
        if(input % i == 0 ){
            return false;
        }
    }

    return true; 
}

int main(void){
    long long a, b;
    long long tmp;
    long long pC = 0;
    long long i;

    scanf("%d %d", &a, &b);
    for(i = a; i <= b; i++){
        if(isPrime(i)){
            printf("%lld\n", i);
        }
    }

    return 0;
}
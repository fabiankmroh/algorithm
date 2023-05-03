#include <stdio.h>
#include <math.h>

int main(void){
    long long int dMoon = 384400000000;
    long long int i;

    i = 0;
    while(pow(2, i) <= dMoon){
        i++;
    }

    printf("%lld\n", i);
}
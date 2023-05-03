#include <stdio.h>

int main(void){
    long long two = 0, five = 0;
    long long n,m;
    scanf("%lld %lld", &n, &m);

    for(long long i = 2; i <= n; i*=2){
        two += n / i;
    }
    for(long long i = 2; i <= n-m; i*=2){
        two -= (n-m) / i;
    }
    for(long long i = 2; i <= m; i*=2){
        two -= m/i;
    }
    for(long long i = 5; i <= n; i*=5){
        five += n/i;
    }
    for(long long i = 5; i <= n-m; i*=5){
        five -= (n-m)/i;
    }
    for(long long i = 5; i <= m; i *= 5){
        five -= m/i;
    }

    if(two > five){
        printf("%lld\n", five);
    }
    else{
        printf("%lld\n", two);
    }

    return 0;
}
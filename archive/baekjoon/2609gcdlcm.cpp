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
    int a, b;
    int gcd;
    int lcm;

    scanf("%d %d", &a, &b);

    gcd = GCD(a,b);
    lcm = a * (b/gcd);


    printf("%d\n%d\n", gcd, lcm);
}
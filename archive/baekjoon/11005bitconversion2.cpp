#include <stdio.h>
#include <string>

int main(void){
    int tenN;
    char output[100000];
    int outputC = 0;
    int assignedB;
    int r;
    int i;

    scanf("%d %d", &tenN, &assignedB);

    while(tenN > 0){
        r = tenN % assignedB;

        if(r < 10){
            output[outputC] = (char)(r + '0');
            outputC++;
        }
        else{
            output[outputC] = (char)(r - 10 + 'A');
            outputC++;
        }

        tenN /= assignedB;
    }

    for(i = outputC - 1; i >= 0; i--){
        printf("%c", output[i]);
    }

    printf("\n");
}
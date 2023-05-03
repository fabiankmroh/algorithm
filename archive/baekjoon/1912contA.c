#include <stdio.h>

int main(void){
    int arrayL;
    int array[100000];
    int maxA[100000];
    int i;
    int a;

    scanf("%d", &arrayL);

    for(i = 0; i < arrayL; i++){
        scanf("%d", &array[i]);
    }

    /* Continous Add Logic */
    maxA[0] = array[0];
    for(i = 1; i < arrayL; i++){
        a = array[i] + maxA[i-1];

        if(a < array[i]){
            maxA[i] = array[i];
        }
        else{
            maxA[i] = a;
        }
    }

    /* Extract Maximum from Added Array */
    int max = -9999;
    for(i = 0; i < arrayL; i++){
        if(maxA[i] > max){
            max = maxA[i];
        }
    }

    printf("%d\n", max);
}
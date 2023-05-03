#include <stdio.h>

int main(void){
    int ans = 0;
    char input[100000];
    int i;
    int size;
    int bit;

    scanf("%s %d", input, &bit);


    /* Convert Process */
    for(i = 0; input[i] != '\0'; i++){
        if('0' <= input[i] && input[i] <= '9'){
            ans = ans * bit + (input[i] - '0');
        }
        else{
            ans = ans * bit + (input[i] - 'A' + 10);
        }
    }   

    printf("%d\n", ans);
    return 0;
}
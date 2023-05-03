#include <stdio.h>

int main(void){
    int alphaA[26]; /* -1 default value */
    char input[100];
    int i;

    for(i = 0; i < 26; i++){
        alphaA[i] = -1;
    }

    scanf("%s", input);
    i = 0;

    while(input[i] != '\0'){
        if(alphaA[input[i] - 'a'] == -1){
            alphaA[input[i] - 'a'] = i;
        }

        i++;
    }

    for(i = 0; i < 26; i++){
        printf("%d ", alphaA[i]);
    }
}
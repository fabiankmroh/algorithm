#include <stdio.h>

int main(void){
    char str[1000000];
    
    scanf("%s", str);
    int size = 0;
    while(str[size] != '\0'){size++;}

    if(size % 3 == 1){
        printf("%d", str[0]);
    }
    else if(size % 3 == 2){
        printf("%d", (str[0] - '0')*2 + (str[1] - '0'));
    }

    for(int i = size%3; i < size; i+=3){
        printf("%d", (str[i] - '0')*4 + (str[i+1] - '0')*2 + (str[i+2] - '0'));
    }
    printf("\n");
    return 0;
}
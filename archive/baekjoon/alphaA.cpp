#include <stdio.h>

int main(void){
    char inp[200];
    int alphaS;
    int alphaL;
    int numberQ;
    int spaceQ;
    int i;

    char* p;

    while(gets(inp) != NULL){
        alphaS = 0;
        alphaL = 0;
        numberQ = 0;
        spaceQ = 0;
        p = inp;

        while(*p != '\0'){
            if( *p >= 'a' && *p <= 'z' ){
                alphaS++;
            }
            else if( *p >= 'A' && *p <= 'Z' ){
                alphaL++;
            }
            else if( *p >= '0' && *p <= '9' ){
                numberQ++;
            }
            else if(*p == ' '){
                spaceQ++;
            }

            *p++;
        }

        printf("%d %d %d %d\n", alphaS, alphaL, numberQ, spaceQ);

    }
}
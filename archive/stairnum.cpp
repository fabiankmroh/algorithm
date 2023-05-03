#include <stdio.h>
#include <stdlib.h>

int main(void){
    int input;
    
    scanf("%d", &input);
    int digit[input];
    
    int i;
    int n;
    int digitC = 0;
    int c;
    int stairC = 0;
    bool stairN = true;
    
    for(i = (10^(input-1)); i < (10^input); i++){
        n = input;
        while(n > 0){
            digit[digitC] = i / 10^(n-1);
            digitC++;
            n--;
        }

        /* Check Logic */
        for(c = 1; c <= input; c++){
            if(abs(digit[c] - digit[c-1]) > 1){
                stairN = false;
            }
        }

        /* Increment Logic */
        if(stairN == true){
            stairC++;
        }
    }
    printf("%d\n", stairC % 1000000000);
}
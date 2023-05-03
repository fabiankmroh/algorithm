#include <stdio.h>

int main(void){
    int i;
    int calC = 0;

    scanf("%d", &i);

    for(1;){
        if(i == 1){
            break;
        }

        if(i % 3 == 0){
            i /= 3;
        }
        else if( (i-1) % 3 == 0){
            i -= 1;
        }
        else if(i % 2 == 0){
            i /= 2;
        }
        
    

        calC++;
    
    }

    printf("%d\n", calC);
}
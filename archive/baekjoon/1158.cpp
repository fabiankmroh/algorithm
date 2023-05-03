#include <stdio.h>

int main( void ){
    int array[7000];
    int arrayL;
    int interval;

    int i = 0;
    int tmpC = 0;
    int allZ;

    int c;

    scanf("%d %d", &arrayL, &interval);
    printf("<");
    for(c = 0; c < arrayL; c++){
        array[c] = c+1;
    }


    while(1){
        allZ = 1;
        /* Reset i to 0 if exceeds the limit */
        if(i >= arrayL){
            i = 0;
        }  

        if(array[i] != 0){
            tmpC++;
        }
        /* Pointer has skipped enough to meet the interval */

        if(tmpC == interval){
            tmpC = 0;
            printf("%d, ", array[i]);
            array[i] = 0;
        }
        
        /* Checking array = {all zero} */
        for(c = 0; c < arrayL; c++){
            if(array[i] != 0){
                allZ = 0;
                break;
            }
        }

        /* Breaks the loop if overall completion is done */
        if(allZ == 1){
            break;
        }
        else i++;

    }/* End of While Loop */
    
    printf(">\n");
}
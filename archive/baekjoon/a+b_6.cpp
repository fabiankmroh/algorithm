#include <stdio.h>
#include <stdlib.h>

int main(void){
    char a[3];
    int n[2];
    int nC;
    int m;
    int i;
    int g;
    
    scanf("%d", &m);
    
    for(g = 0; g < m; g++){
        int f = 0;
        scanf("%s", a);
        
        nC = 0;
        for(i = 0; i < 3; i++){
            if(i == 1){
                continue;
            }
            else{
                n[nC] = a[i] - '0';
            }
            nC += 1;
        }
        
        for(i = 0; i < 2; i++){
            f = n[i];
        }
        printf("%d\n", f);
    }
    
    return 0;
}

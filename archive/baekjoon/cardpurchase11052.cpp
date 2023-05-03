#include <stdio.h>

int main(void){
    int i;
    int j;
    int maxL;
    int priceL[2000];
    int mpi[2000];
    int maxPrice = 0;

    scanf("%d", &maxL);
    for(i = 1; i <= maxL; i++){
        scanf("%d", &priceL[i]);
    }

    for(i = 1; i <= maxL; i++){
        for(j = 1; j <= i; j++){
            if(mpi[i] < mpi[i-j] + priceL[j]){
                mpi[i] = mpi[i-j] + priceL[j];
            }
        }
    }

    printf("%d\n", mpi[maxL]);

    return 0;
}
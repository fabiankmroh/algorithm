#include <stdio.h>

int max(int a, int b){
    if(a > b){
        return a;
    }
    else if(a < b){
        return b;
    }
}

int main(void){
    int caseL;
    scanf("%d", &caseL);

    int rowL;
    long long sticker[100001][2];
    long long a[100001][3];

    int i;

    while(caseL--){
        scanf("%d", &rowL);

        /* Sticker Data Input */
        for(i = 1; i <= rowL; i++){
            scanf("%lld", &sticker[i][0]);
        }
        for(i = 1; i <= rowL; i++){
            scanf("%lld", &sticker[i][1]);
        }

        a[0][0] = 0;
        a[0][1] = 0;
        a[0][2] = 0;

        for(i = 1; i <= rowL; i++){
            a[i][0] = max(a[i-1][0], max(a[i-1][1], a[i-1][2]));
            a[i][1] = max(a[i-1][0], a[i-1][1]) + sticker[i][0];
            a[i][2] = max(a[i-1][0], a[i-1][1]) + sticker[i][1];
        }
        long long ans = 0;
        for(i = 1; i <= rowL; i++){
            ans = max(max(ans, a[i][0]), max(a[i][1], a[i][2]));
        }
        printf("%lld\n", ans);
    }
    return 0;
}
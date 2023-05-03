#include <stdio.h>

int main(void){
  int a;
  int b;
  int m;
  int i;

  scanf("%d", &m);

  for(i = 1; i <= m; i++){
    scanf("%d %d", &a, &b);
    printf("Case #%d: %d + %d = %d\n", i, a, b, a+b);
  }

  return 0;
}

#include <stdio.h>

int main(void){
  int sum = 0;
  int i;
  int temp;
  int lim;

  scanf("%d", &lim);

  for(i = 0; i < lim; i++){
    scanf("%1d", &temp);
    sum += temp;
  }
  printf("%d\n", sum);
  return 0;
}

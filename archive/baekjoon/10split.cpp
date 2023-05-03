#include <stdio.h>

int main(void){
  char a[100];
  int i = 0;

  scanf("%s", a);
  while(a[i] != '\0'){
    if(i % 10 == 0 && i != 0)printf("\n");

    printf("%c",a[i]);
    i++;
  }
  printf("\n");
  return 0;
}

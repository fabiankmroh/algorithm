#include <stdio.h>

int main(void){
  int a;
  int b;
  int i;


  while(1){
    scanf("%d %d", &a, &b);
    if(a != 0 && b != 0){
      printf("%d\n", a+b);
    }
    else{
      return 0;
    }
  }

}

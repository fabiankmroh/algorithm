#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct stack{
  char stack[700000];
  int stackL;
}stack;

void push(stack* PoS, char c){
  PoS->stack[PoS->stackL] = c;
  PoS->stackL++;
}

char pop(stack* PoS){
  if(PoS->stackL > 0){
    PoS->stackL--;
    return PoS->stack[PoS->stackL];
  }
}

int isempty(stack* PoS){
  if(PoS->stackL == 0){
    return 1;
  }
  else{
    return 0;
  }
}

int main(void){
  char inputTxt[150000];
  stack lStack, rStack;

  lStack.stackL = 0;
  rStack.stackL = 0;

  int orderC;
  char cmd[1000];
  char addC[3000];

  int i = 0;
  int j, k;

  scanf("%s", inputTxt);
  scanf("%d", &orderC);

  while(inputTxt[i] != '\0'){
    push(&lStack, inputTxt[i]);
    i++;
  }

  for(i = 0; i < orderC; i++){
    scanf("%s", cmd);

    switch(cmd[0]){

      case 'L':
      if(!isempty(&lStack))
        push(&rStack, pop(&lStack));
      break;

      case 'D':
      if(!isempty(&rStack))
        push(&lStack, pop(&rStack));
      break;

      case 'B':
      if(!isempty(&lStack))
        pop(&lStack);
      break;

      case 'P':
      scanf("%s", addC);
      push(&lStack, addC[0]);

      break;
    }
  }

  j = lStack.stackL;
  for(i = 0; i < j; i++){
    push(&rStack, pop(&lStack));
  }

  k = rStack.stackL;
  for(i = 0; i < k; i++){
    printf("%c", pop(&rStack));
  }

  printf("\n");

}

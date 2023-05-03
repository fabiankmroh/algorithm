#include <stdio.h>
#include <string.h>

/* Queue Structure */
typedef struct queue{
    int queue[10000];
    int front;
    int back;
}queue; 

/* Push Function */
void push(queue* p, int enterV){
    /* Standard Push */
    if(p->back < 9999){
        p->back++;
        p->queue[p->back] = enterV;
    }
}

/* Pop Function (from front) */
void pop(queue* p){

    /* If Front & back have intervals */
    if(p->back - p->front > 0){
        p->front++;
        printf("%d\n",p->queue[p->front]);
    }
    else{
        printf("-1\n");
    }
    
}

int size(queue* p){
    return p->back - p->front;
}

int empty(queue* p){
    if(p->back != p->front){
        return 0;
    }
    else return 1;
}

int front(queue* p){
    if(empty(p)){
        return -1;
    }
    return p->queue[p->front+1];
}

int back(queue* p){
    if(empty(p)){
        return -1;
    }
    return p->queue[p->back];
}

int main(void){
    int orderL;
    int orderC;
    char orderS[10];
    int inputV[10];
    queue q;
    q.front = -1;
    q.back = -1;
    
    scanf("%d", &orderL);

    for(orderC = 0; orderC < orderL; orderC++){
        scanf("%s", orderS);
        
        if(!strncmp(orderS, "push", 4)){
            scanf("%d", inputV);
            
            push(&q, inputV[0]);
        }
        else if(!strncmp(orderS, "pop", 3)){
            pop(&q);
        }
        else if(!strncmp(orderS, "size", 4)){
            printf("%d\n", size(&q));
        }
        else if(!strncmp(orderS, "empty", 5)){
            printf("%d\n", empty(&q));
        }
        else if(!strncmp(orderS, "front", 5)){
            printf("%d\n", front(&q));
        }
        else if(!strncmp(orderS, "back", 4)){
            printf("%d\n", back(&q));
        }

    } /* End of for loop */
}
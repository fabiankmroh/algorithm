#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node* nodeA(void){
    Node* node;
    node = (Node*)malloc(sizeof(Node));


    if(node == NULL){
        printf("Memory Allocation Error\n");
    }
    else{
        return node;
    }
}

int main(void){
    int interval;
    int maxN;
    int i;
    int count = 0;

    Node *head, *p, *prev_p;
    
    scanf("%d %d", &maxN, &interval);

    for(i = 0; i < maxN; i++){

        p = nodeA(); /* Node Allocation */
        p->data = i+1; 

        if(i == 0){ /* Creating Beginning Node (Circular) */
            head = p;
            p->right = head;
            p->left = head;
        }
        else{ /* Remaining Nodes. Connecting them with previous nodes */
            prev_p->right = p;
            p->left = prev_p;
            p->right = head;
        }

        prev_p = p;
    }

    /* Creating Circular Connection */
    head->left = p; 
    p = head;


    i = 1; /* Since the # of intervals will be counted from 1,2,3... */
    printf("<");

    /* 
        Count = # of Nodes Removed
        i = # of Nodes Moved
    */
    
    while(count != maxN){
        if(i % interval == 0){ /* Interval Check */
            if(count == maxN-1){ /* End Number */
                printf("%d", p->data);
                break;
            }
            else 
                printf("%d, ", p->data);
            
            p->left->right = p->right; /* Previous Node Link */
            p->right->left = p->left; /* Next Node Link */
            free(p);
            count++;
        }
        p = p->right;
        i++;
    }

    printf(">\n");
}
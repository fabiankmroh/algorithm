#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

int main(void){
    ListNode *p1;
    p1 = (ListNode *)malloc(sizeof(ListNode));

    p1->data = 10;
    p1->link = NULL;

    ListNode *p2;
    p2 = (ListNode *)malloc(sizeof(ListNode));
    p2->data = 20;
    p2->link = NULL;
    p1->link = p2;
}

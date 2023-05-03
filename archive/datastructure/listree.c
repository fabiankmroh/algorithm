#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
} Node;

int main(void){
    Node* n1;
    Node* n2;
    Node* n3;

    n1 = (Node*)malloc(sizeof(Node));
    n2 = (Node*)malloc(sizeof(Node));
    n3 = (Node*)malloc(sizeof(Node));

    n1->data = 10;
    n1->left = n2;
    n1->right = n3;

    n2->left = NULL;
    n2->right = NULL;

    n3->left = NULL;
    n3->right = NULL;

    n2->data = 30;
    n3->data = 40;
}
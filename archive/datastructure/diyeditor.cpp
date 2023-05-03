#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char a[10000];
} element;

typedef struct ListNode {
    element data;
    struct ListNode* link;
} ListNode;

typedef struct{
    ListNode* head;
    int length;
} LinkedList;

void init(LinkedList *list){
    if(list == NULL) return;
    list->length = 0;
    list->head = 0;
}

ListNode *callNode(LinkedList* list, int pos){
    int i;
    ListNode* tmpNode = list->head;

    if(pos < 0) return NULL;

    for(i = 0; i < pos; i++){
        tmpNode = tmpNode->link;
    }

    return tmpNode;
}

void displayContent(LinkedList* list){
    int cnt;
    ListNode* tmpNode;
    tmpNode = list->head;

    for(cnt = 0; cnt < list->length; cnt++){
        printf("%3d: %s", cnt+1, tmpNode->data.a);
        tmpNode = tmpNode->link;
    }
}

void insertNode(ListNode** phead, ListNode* previous, ListNode* new_node){
    if(*phead == NULL){
        new_node->link = NULL;
        *phead = new_node;
    }
    else if(previous == NULL){
        new_node->link = *phead;
        *phead = new_node;
    }
    else{
        new_node->link = previous->link;
        previous->link = new_node;
    }
}

void addNodeData(LinkedList* list, int pos, element data){

    /* Check Position */
    if(pos < 0 || pos > list->length){
        return;
    }

    ListNode* NEW_NODE = (ListNode*)(malloc(sizeof(ListNode)));
    
    /* Allocation Check */
    if(NEW_NODE == NULL){
        printf("Allocation Error\n");
        return;
    }

    NEW_NODE->data = data;
    ListNode* previous = callNode(list, pos-1);
    insertNode((&list->head), previous, NEW_NODE);

    list->length++;
}

void insertLine(LinkedList* list){
    int pos;
    char input[10000];
    element content;

    /* Copied Stuff */
    printf("Enter Line #:: ");
    fgets(input, 9999, stdin);
    sscanf(input,"%d",&pos);

    if(pos > list->length+1 || pos < 1){
        printf("Invalid Line\n");
        return;
    }

    printf("Insert Content:: ");
    fflush(stdin);
    fgets(input, 9999, stdin);

    strcpy(content.a, input);
    addNodeData(list, pos-1, content);
    
    printf("NEW CONTENT::\n");
    displayContent(list);
}


void deleteNode(ListNode** phead, ListNode* p, ListNode* removed){
    if(p == NULL){
        *phead = (*phead)->link;
    }
    else{
        p->link = removed->link;
    }

    free(removed);
}

void deleteLine(LinkedList* list){
    char pos;
    int posI;
    char buf[20];
    ListNode* previous;

    if(list->length > 0){
        printf("Line # to delete:: ");
        fgets(buf, 128, stdin);
        sscanf(buf, "%c", &pos);
    }

    posI = pos - '0';

    if(posI > list->length || posI < 1){
        printf("Invalid Line\n");
        return;
    }
    else{
        /* Delete Sequence */
        previous = callNode(list, posI-2); 
        deleteNode(&(list->head), previous, (previous != NULL) ? previous->link: NULL); 
        list->length--;

        return;
    }
}

void commandA(LinkedList* list, char command){
    switch(command){
        case 'd':
            deleteLine(list);
            break;
        case 'i':
            insertLine(list);
            break;
        case 'p':
            displayContent(list);
            break;
    }
}

void commandL(){
    printf("i: Insert\n");
    printf("d: Delete\n");
    printf("p: Print\n");
    printf("q: Quit\n");
}

int main(void){
    char commandI;
    char inputB[10];
    LinkedList buffer;

    init(&buffer);
    do{
        commandL();
            fgets(inputB, 128, stdin);
            sscanf(inputB, "%c", &commandI);
            commandA(&buffer, commandI);
    }while(commandI != 'q');
}
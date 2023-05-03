#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

void error(char* message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node){
    if(*phead == NULL){
        new_node->link = NULL;
        *phead = new_node;
    }
    else if(p == NULL){
        new_node->link = *phead;
        *phead = new_node;
    }
    else{
        new_node->link = p->link;
        p->link = new_node;
    }
}

void remove_node(ListNode **phead, ListNode *p, ListNode *removed){
    if(p == NULL){
        *phead = (*phead)->link;
    }
    else{
        p->link = removed->link;
    }
    free(removed);
}

void display(ListNode *head){
    ListNode *p = head;
    while(p != NULL){
        printf("%d->", p->data);
        p = p->link;
    }
    printf("\n");
}

ListNode *search(ListNode *head, int x){
    ListNode *p;
    p = head;
    while(p != NULL){
        if(p->data == x) return p;
        p = p->link;
    }
}

ListNode *concat(ListNode *head1, ListNode *head2){
    ListNode *p;
    if(head1 == NULL){
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }
    else{
        p = head1;
        while(p->link != NULL){
            p = p->link;
        }
        p->link = head2;
        return head1;
    }
}

ListNode *reverse(ListNode *head){
    ListNode *p, *q, *r;
    p = head;
    q = NULL;
    while(p != NULL){
        r = q;
        q = p;
        p = p->link;
        q->link = r;
    }
    return q;
}

ListNode *create_node(element data, ListNode *link){
    ListNode *new_node;
    new_node = (ListNode *)malloc(sizeof(ListNode));

    if(new_node == NULL) error("Memory Error");
    new_node -> data = data;
    new_node -> link = link;

    return new_node;
}
typedef struct {
    ListNode *head;
    int length;
}LinkedListType;

int is_empty(LinkedListType *list){
    if(list->head == NULL) return 1;
    else return 0;
}

int get_length(LinkedListType *list){
    return list->length;
}

ListNode *get_node_at(LinkedListType *list, int pos){
    int i;
    ListNode *tmp_node = list->head;

    if(pos < 0) return NULL;
    for(i = 0; i < pos; i++)
        tmp_node = tmp_node->link;
    return tmp_node;
}

void add(LinkedListType *list, int position, element data){
    ListNode *p;
    if((position >= 0) && (position <= list->length)){
        ListNode*node = (ListNode*)malloc(sizeof(ListNode));
        if(node == NULL) error("Memory Allocation Error");
        node->data = data;
        p = get_node_at(list, position-1);
        insert_node(&(list->head), p, node);
        list->length++;
    }
}


void add_last(LinkedListType *list, element data){
    add(list, get_length(list), data);
}

void add_first(LinkedListType *list, element data){
    add(list, 0, data);
}

void Delete(LinkedListType *list, int pos){
    if(!is_empty(list) && (pos >= 0) && (pos < list->length)){
        ListNode *p = get_node_at(list, pos-1);
        remove_node(&(list->head), p, (p != NULL)?p->link: NULL);
        list->length--;
    }
}

element get_entry(LinkedListType *list, int pos){
    ListNode *p;
    if(pos >= list->length) error("Location Error");
    p = get_node_at(list, pos);
    return p->data;
}

void clear(LinkedListType *list){
    int i;
    for(i = 0; i < list->length; i++){
        Delete(list, i);
    }
}

void display(LinkedListType *list){
    int i;
    ListNode *node = list->head;
    printf("(");
    
    for(i = 0;i<list->length; i++){
        printf("%d ", node->data);
        node = node->link;
    }
    printf(")\n");
}


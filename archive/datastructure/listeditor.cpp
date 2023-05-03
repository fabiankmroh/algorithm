#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_CHAR_PER_LINE   1000
#define MAX_NAME    256
#define FALSE   0
#define TRUE    1

void warning(char *message){
    fprintf(stderr, "%s\n", message);
}

void error(char *message){
    fprintf(stderr, "%s\n", message);
    exit(1);
}

typedef struct {
    char a[MAX_CHAR_PER_LINE];
} element;

typedef struct ListNode {
    element data;
    struct ListNode *link;
} ListNode;

typedef struct{
    ListNode *head;
    int length;
} LinkedListType;

void insert_node(ListNode **phead, ListNode *p, ListNode *new_node){
    if(*phead == NULL){
        new_node->link = NULL;
        *phead = new_node;
    }
    else if(p == NULL){      /* why this block ; chester */
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

void init(LinkedListType *list){
    if(list == NULL) return;

    list->length = 0;
    list->head = NULL;
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
    /* else {  }  handling ; chester */ 
}

void add_last(LinkedListType *list, element data){
    add(list, get_length(list), data);
}

void add_first(LinkedListType *list, element data){
    add(list, 0, data);
}

int is_empty(LinkedListType *list){
    if(list->head == NULL){
        return 1;
    }
    else{ 
        return 0;
    }
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

void display(LinkedListType *buffer){
    int i;
    ListNode *tmp_node;
    tmp_node = buffer->head;

    printf("*****************\n");

    for(i = 0; i < buffer->length; i++){
        printf("%.3d: %s", i+1, tmp_node->data.a);
        tmp_node = tmp_node->link;
    }

    printf("*****************\n");
}


void help(){
    printf("*****************\n");
    printf("i: input\n");
    printf("d: delete\n");
    printf("r: read\n");
    printf("w: write\n");
    printf("l: display\n");
    printf("q: quit\n");
    printf("*****************\n");
}

void read_file(LinkedListType *buffer){
    char fname[MAX_NAME];
    FILE *fd;
    element p;

    if(!is_empty(buffer)){
        clear(buffer);
    }
    init(buffer);

    printf("File Name: ");
    scanf("%s", fname);

    if( (fd = fopen(fname, "r")) == NULL ){
        warning("File can not be opened");
        return;
    }

    while(fgets(p.a, MAX_CHAR_PER_LINE, fd)){
        add_last(buffer, p);
    }

    fclose(fd);
    display(buffer);
}

void write_file(LinkedListType *buffer){
    FILE *fd;
    char fname[MAX_NAME];
    element p;
    int i;

    printf("File Name: ");
    scanf("%s", fname);

    if( (fd = fopen(fname,"w")) == NULL ){
        printf("Can't Open File\n");
        return;
    }

    for(i = 0; i < get_length(buffer); i++){
        p = get_entry(buffer,i);
        fputs(p.a, fd);
    }

    fclose(fd);
    display(buffer);
}

void delete_line(LinkedListType *buffer){
    int position;

    if(is_empty(buffer)){
        printf("No Lines to Delete\n");
    }
    else{
        printf("Select Line # to Erase\n");
        scanf("%d", &position);
        Delete(buffer, position);
    }
}

void insert_line(LinkedListType *buffer){
    int position;
    char line[MAX_CHAR_PER_LINE];
    element p;

    printf("Input Entry Line #  : ");
    fgets(line,MAX_CHAR_PER_LINE,stdin); /* line input */
    sscanf(line,"%d",&position); 

    printf("Insert Content : ");
    fflush(stdin);
    fgets(line,MAX_CHAR_PER_LINE,stdin); 
    
    strcpy(p.a, line);
    add(buffer, position, p);
    display(buffer);
}

void display_buffer(LinkedListType *buffer){
    display(buffer);
}

void do_command(LinkedListType *buffer, char command){
    
    switch(command){
        case 'd':
            delete_line(buffer);
            break;
        case 'i':
            insert_line(buffer);
            break;
        case 'r':
            read_file(buffer);
            break;
        case 'w':
            write_file(buffer);
            break;
        case 'l':
            display_buffer(buffer);
            break;
        case 'q':
            break;
    }

}

int main(){
    char command;
    char buf[128];
    LinkedListType buffer;

    init(&buffer);
    do{
        help();
            fgets(buf,128,stdin);
            sscanf(buf,"%c",&command);
            fflush(stdin);
            do_command(&buffer, command);
    }while(command!= 'q');
}
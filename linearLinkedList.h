#ifndef LINEARLINKEDLIST_H_INCLUDED
#define LINEARLINKEDLIST_H_INCLUDED

typedef struct ST_node{
    int data;
    struct ST_node * next;
}ST_node;


typedef struct {
    ST_node * head;
    unsigned char listSize;
}ST_list;

typedef enum {
    FAIL,
    SUCESS
}OP_STATE_TYPE;

OP_STATE_TYPE createList(ST_list *list);
OP_STATE_TYPE insertToList(ST_list *listHead, unsigned char position, int data);
OP_STATE_TYPE deleteFromList(ST_list *listHead, unsigned char position, int* data);
ST_node* searchIntoList(ST_list *listHead, int data);
void printList(ST_list * listHead);
void sortList(ST_list *listHead); //Bonus
void reverseList(ST_list *listHead); //Bonus

#endif // LINEARLINKEDLIST_H_INCLUDED

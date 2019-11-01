

#include "linearLinkedList.h"
#include "stdlib.h"
#include "stdio.h"

OP_STATE_TYPE createList(ST_list *list){
    if(list != NULL){

        list->head = NULL;
        list->listSize = 0;

        return SUCESS;
    }

    return FAIL;
}
OP_STATE_TYPE insertToList(ST_list *listHead, unsigned char position, int data){
    if((position > (listHead->listSize + 1)) || (listHead == NULL)){
        return FAIL;
    }


    unsigned char loopIndex;
    ST_node * tempNode = (ST_node *) malloc(sizeof(ST_node));


    if(listHead->head == NULL){
        listHead->head = tempNode;
        tempNode->data = data;
        tempNode->next = NULL;
        listHead->listSize ++;
        return SUCESS;
    }

    ST_node * nodePtr = listHead->head;

    for(loopIndex = 1; loopIndex < position; loopIndex ++){
        nodePtr = nodePtr->next;
    }

    tempNode->data = data;
    if(nodePtr->next != NULL){
        tempNode->next = nodePtr->next;
    }else{
        tempNode->next = NULL;
    }
    nodePtr->next = tempNode;
    listHead->listSize ++;

    return SUCESS;
}
OP_STATE_TYPE deleteFromList(ST_list *listHead, unsigned char position, int* data){
    if(position > (listHead->listSize)){
        return FAIL;
    }

    if((listHead == NULL) || (listHead->head == NULL)){
        return FAIL;
    }
    if(listHead->listSize <= 1){
        *data = listHead->head->data;
        free(listHead->head);
        listHead->head = NULL;
        return SUCESS;
    }

    unsigned char loopIndex;
    ST_node * nodePtr = listHead->head;
    ST_node * tempNode;
    for(loopIndex = 1; loopIndex < position; loopIndex ++){
        nodePtr = nodePtr->next;
    }

    tempNode = nodePtr->next;

      nodePtr->next = tempNode->next;

    *data = tempNode->data;
    listHead->listSize --;

    free((ST_node*) tempNode);

    return SUCESS;
}
ST_node* searchIntoList(ST_list *listHead, int data){

    if(listHead == NULL){
        return NULL;
    }
    if(listHead->head == NULL){
        return NULL;
    }

    ST_node * ret = NULL;
    ST_node * nodePtr = listHead->head;
    while(nodePtr->next != NULL){
        if(nodePtr->data == data){
           ret = nodePtr;
           break;
        }
        nodePtr = nodePtr->next;
    }

    if((ret == NULL) && (nodePtr->data == data)){
        ret = nodePtr;
    }
    return ret;
}

void printList(ST_list * listHead){
    if(listHead == NULL){
        printf("Wrong Head\r\n");
        return;
    }
    if(listHead->head == NULL){
        printf("Empty List\r\n");
        return;
    }
    ST_node * node = listHead->head;
    do{
        printf("%d, ", node->data);
        node = node->next;
    }while(node != NULL);
}

void sortList(ST_list *listHead) //Bonus
{
    if((listHead == NULL) || (listHead->head == NULL) || (listHead->head->next == NULL)){
        return;
    }

    ST_node * sorted;
    ST_node * unsorted;
    ST_node * ptr1;
    ST_node * ptr2;
    ST_node n1;

    for(sorted = listHead->head; sorted->next != NULL ; sorted = sorted->next){
        for(unsorted = sorted->next; unsorted != NULL; unsorted = unsorted->next){
            if(unsorted->data < sorted->data){
                ptr1 = unsorted->next;
                ptr2 = sorted->next;

                n1 = *unsorted;
                *unsorted = *sorted;
                *sorted = n1;

                unsorted->next = ptr1;
                sorted->next = ptr2;
            }
        }
    }

}

void reverseList(ST_list *listHead) //Bonus
{
    if((listHead == NULL) || (listHead->head == NULL) || (listHead->head->next == NULL)){
        return;
    }



    unsigned short lastIndex = listHead->listSize;
    unsigned short loopIndex = 0;

    ST_node * firstNode = listHead->head;
    ST_node * lastNode = firstNode;
    ST_node * midNode = firstNode;
    ST_node n1;
    ST_node * ptr1;
    ST_node * ptr2;

    if(listHead->listSize == 2){
        lastNode = firstNode->next;

        ptr1 = firstNode->next;
        ptr2 = lastNode->next;

        n1 = *firstNode;
        *firstNode = *lastNode;
        *lastNode = n1;

        firstNode->next = ptr1;
        lastNode->next = ptr2;
        firstNode = firstNode->next;

        return;
    }

    for(loopIndex = 0; loopIndex < ((listHead->listSize / 2)  + (listHead->listSize % 2)); loopIndex ++){
        midNode = midNode->next;
    }

    for(lastIndex = listHead->listSize - 1; lastIndex > ((listHead->listSize / 2)  + (listHead->listSize % 2)); lastIndex --){
        lastNode = midNode;
        for(loopIndex = ((listHead->listSize + 1) / 2); loopIndex < lastIndex; loopIndex ++){
            lastNode = lastNode->next;
        }
        ptr1 = firstNode->next;
        ptr2 = lastNode->next;

        n1 = *firstNode;
        *firstNode = *lastNode;
        *lastNode = n1;

        firstNode->next = ptr1;
        lastNode->next = ptr2;
        firstNode = firstNode->next;
    }

}

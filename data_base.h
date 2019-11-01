#ifndef DATA_BASE_H_INCLUDED
#define DATA_BASE_H_INCLUDED

#include "data_base.h"
#include "linearLinkedList.h"

#define DBs_MAX_NUM 2

OP_STATE_TYPE createDataBase(void);
OP_STATE_TYPE insertToDataBase(unsigned char DB_number, unsigned char position, int data);
OP_STATE_TYPE deleteFromDataBase(unsigned char DB_number, unsigned char position, int * data);
ST_node * searchIntoDataBase(unsigned char DB_number, int data);
void sortTheDataBase(unsigned char DB_number);
long long operationOnTwoNodes(unsigned char firstNode_DB, unsigned char firstNode_Position, char operation, unsigned char secondNode_DB, unsigned char secondNode_position);


#endif // DATA_BASE_H_INCLUDED

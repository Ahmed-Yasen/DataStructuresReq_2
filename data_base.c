

#include "data_base.h"
#include "stdlib.h"


ST_list DBs[DBs_MAX_NUM];


OP_STATE_TYPE createDataBase(void){
    unsigned char loopIndex = 0;
    OP_STATE_TYPE ret = FAIL;
    while(loopIndex < DBs_MAX_NUM){
        ret = createList(&DBs[loopIndex]);
        loopIndex --;
    }

    return ret;
}
OP_STATE_TYPE insertToDataBase(unsigned char DB_number, unsigned char position, int data){
    OP_STATE_TYPE ret = FAIL;

    if((DB_number < 1) || (DB_number > DBs_MAX_NUM)){
        return ret;
    }

    ret = insertToList(&DBs[DB_number - 1], position, data);

    return ret;
}
OP_STATE_TYPE deleteFromDataBase(unsigned char DB_number, unsigned char position, int * data){
    OP_STATE_TYPE ret = FAIL;

    if((DB_number < 1) || (DB_number > DBs_MAX_NUM)){
        return ret;
    }

    ret = deleteFromList(&DBs[DB_number - 1], position, data);

    return ret;
}
ST_node * searchIntoDataBase(unsigned char DB_number, int data){
    ST_node * ret = NULL;
    if((DB_number < 1) || (DB_number > DBs_MAX_NUM)){
        return ret;
    }

    ret = searchIntoList(&DBs[DB_number - 1], data);

    return ret;
}
void sortTheDataBase(unsigned char DB_number){
    if((DB_number < 1) || (DB_number > DBs_MAX_NUM)){
        return;
    }

    sortList(&DBs[DB_number - 1]);
}


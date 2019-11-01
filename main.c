#include <stdio.h>
#include <stdlib.h>
#include "linearLinkedList.h"
#include "data_base.h"



/* #define OPEN_REQ_5 */
 #define OPEN_REQ_6





ST_list list;
ST_node * node;

#ifdef OPEN_REQ_6

int main(void){
    OP_STATE_TYPE state;
    int numberOfDBs = 0;
    ST_node * node;
    int scan_1, scan_2, scan_3;
    unsigned char loopIndex = 0;
    unsigned int numberOfQueries;
    unsigned int choices[6] = {0};
    printf("Please Enter Number of Queries:");
    scanf("%d", &numberOfQueries);
    printf("\r\nPlease choose the queries:\r\n\t1- Create DataBase.\n\t2- Insert to DataBase.\n\t3- Delete from the DataBase.\n\t4- Search into the DataBase.\n\t5- Sort the DataBase.\n\t6- Operation on two nodes.\nWaiting for your response….\r\n");

    for(loopIndex = 0; loopIndex < numberOfQueries; loopIndex ++){
        scanf(" %d", &choices[loopIndex]);
    }



    for(loopIndex = 0; loopIndex < numberOfQueries; loopIndex ++){
        switch(choices[loopIndex]){
            case 1:{

                state = createDataBase();
                if(state == SUCESS){
                    printf("DataBase Created Successfully\r\n");
                    numberOfDBs ++;
                    printf("The number of DBs is %d\r\n", numberOfDBs);
                }else{
                    printf("DataBase Failed to be created!!\r\n");
                }
            }break;
            case 2:{
                printf("Please Select DB to insert: ");
                scanf(" %d", &scan_1);
                printf("Please Enter Position to insert into: ");
                scanf(" %d", &scan_2);
                printf("Please Enter Data to insert: ");
                scanf(" %d", &scan_3);
                state = insertToDataBase(scan_1, scan_2, scan_3);
                if(state == SUCESS){
                    printf("Data Inserted Successfully!!\n");
                }else{
                    printf("Data Not Inserted\n");
                }
            }break;
            case 3:{
                printf("Please Select DB to delete from: ");
                scanf(" %d", &scan_1);
                printf("Please Enter Position to from: ");
                scanf(" %d", &scan_2);
                state = deleteFromDataBase(scan_1, scan_2, &scan_3);
                if(state == SUCESS){
                    printf("Data Deleted: %d\n", scan_3);
                }else{
                    printf("Data Not Deleted\n");
                }
            }break;
            case 4:{
                printf("Please Select DB to delete from: ");
                scanf(" %d", &scan_1);
                printf("Please Enter data: ");
                scanf(" %d", &scan_3);
                node = searchIntoDataBase(scan_1, scan_3);
                if(node != NULL){
                    printf("node found!!\n");
                }else{
                    printf("node not found\n");
                }

            }break;
            case 5:{
                printf("Please Select DB to delete from: ");
                scanf(" %d", &scan_1);
                sortTheDataBase(scan_1);
            }break;
            case 6:{

            }break;
        }
    }
    return 0;
}

#endif // OPEN_REQ_6


#ifdef OPEN_REQ_5
int main()
{
    int loopIndex;
    int data = 10;
    createList(&list);

    for(loopIndex = 0; loopIndex < 2; loopIndex ++){
        insertToList(&list, loopIndex, data --);
    }

    printf("Original List: \r\n");
    printList(&list);

    sortList(&list);
    printf("Sorted List: \r\n");
    printList(&list);

    printf("Reversed List: \r\n");
    reverseList(&list);
    printList(&list);

    return 0;
}
#endif

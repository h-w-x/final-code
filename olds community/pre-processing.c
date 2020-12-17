#include "head.h"

house *mkhouse(){

    house tmp;

    FILE *fp;
    fp = fopen("house.dat", "rb");

    house *head = (head*)malloc(sizeof(head));
    house *pnew = (head*)malloc(sizeof(head));
    head->next = pnew ;

    fread( &tmp , sizeof(house) , 1 , fp );
    *pnew = tmp ;
    while( !feof(fp) ){
        pnew->next = (head*)malloc(sizeof(head));
        pnew = pnew->next ;
        fread( &tmp , sizeof(house) , 1 , fp );
        *pnew = tmp ;
    }
    pnew->next = NULL ;

    fclose(fp);

    return head ;
}



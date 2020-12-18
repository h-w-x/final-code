#include "head.h"

house *mkhouse(){                   //read house data from house.dat and creat a linked list ,return its head pointer
                                    //>>>Attention: the first node in the list _IS_NOT_ data !<<<

    FILE *fp ;
    fp = fopen("house.dat", "rb");

    house *head = (house*)malloc(sizeof(house));
    house *pnew = (house*)malloc(sizeof(house));
    head->next = pnew ;

    house tmp ;
    fread( &tmp , sizeof(house) , 1 , fp );
    *pnew = tmp ;
    while( !feof(fp) ){
        pnew->next = (house*)malloc(sizeof(house));
        pnew = pnew->next ;
        fread( &tmp , sizeof(house) , 1 , fp );
        *pnew = tmp ;
    }
    pnew->next = NULL ;

    fclose(fp) ;

    return head ;
}

void wthouse( house *head ){        //write the house linked list into house.dat then free the list by the head pointer

    FILE *fp ;
    fp = fopen("house.dat", "wb");

    house *pnew = head->next ;
    free(head) ;

    while( pnew != NULL ){
        fwrite( pnew , sizeof(house) , 1 , fp );
        head = pnew ;
        pnew = pnew->next ;
        free(head) ;
    }

    fclose(fp);
}

//>>>
//
//the following functions are almost the same
//you just need to read the two functions upwards
//
//>>>Attention again: the first node in the list _IS_NOT_ data !<<<
//
//<<<






user *mkuser(){                    //read user data from user.dat and creat a linked list ,return its head pointer
                                    //>>>Attention: the first node in the list _IS_NOT_ data !<<<

    FILE *fp ;
    fp = fopen("user.dat", "rb");

    user *head = (user*)malloc(sizeof(user));
    user *pnew = (user*)malloc(sizeof(user));
    head->next = pnew ;

    user tmp ;
    fread( &tmp , sizeof(user) , 1 , fp );
    *pnew = tmp ;
    while( !feof(fp) ){
        pnew->next = (user*)malloc(sizeof(user));
        pnew = pnew->next ;
        fread( &tmp , sizeof(user) , 1 , fp );
        *pnew = tmp ;
    }
    pnew->next = NULL ;

    fclose(fp) ;

    return head ;
}

void wtuser( user *head ){        //write the user linked list into user.dat then free the list by the head pointer

    FILE *fp ;
    fp = fopen("user.dat", "wb");

    user *pnew = head->next ;
    free(head) ;

    while( pnew != NULL ){
        fwrite( pnew , sizeof(user) , 1 , fp );
        head = pnew ;
        pnew = pnew->next ;
        free(head) ;
    }

    fclose(fp);
}


set *mkset(){                       //read set data from set.dat and creat a linked list ,return its head pointer
                                    //>>>Attention: the first node in the list _IS_NOT_ data !<<<

    FILE *fp ;
    fp = fopen("set.dat", "rb");

    set *head = (set*)malloc(sizeof(set));
    set *pnew = (set*)malloc(sizeof(set));
    head->next = pnew ;

    set tmp ;
    fread( &tmp , sizeof(set) , 1 , fp );
    *pnew = tmp ;
    while( !feof(fp) ){
        pnew->next = (set*)malloc(sizeof(set));
        pnew = pnew->next ;
        fread( &tmp , sizeof(set) , 1 , fp );
        *pnew = tmp ;
    }
    pnew->next = NULL ;

    fclose(fp) ;

    return head ;
}

void wtset( set *head ){        //write the set linked list into set.dat then free the list by the head pointer

    FILE *fp ;
    fp = fopen("set.dat", "wb");

    set *pnew = head->next ;
    free(head) ;

    while( pnew != NULL ){
        fwrite( pnew , sizeof(set) , 1 , fp );
        head = pnew ;
        pnew = pnew->next ;
        free(head) ;
    }

    fclose(fp);
}

owner *mkowner(){                       //read owner data from owner.dat and creat a linked list ,return its head pointer
                                    //>>>Attention: the first node in the list _IS_NOT_ data !<<<


    FILE *fp ;
    fp = fopen("owner.dat", "rb");

    owner *head = (owner*)malloc(sizeof(owner));
    owner *pnew = (owner*)malloc(sizeof(owner));
    head->next = pnew ;

    owner tmp ;
    fread( &tmp , sizeof(owner) , 1 , fp );
    *pnew = tmp ;void pt_1_house( house *p );
    while( !feof(fp) ){
        pnew->next = (owner*)malloc(sizeof(owner));
        pnew = pnew->next ;
        fread( &tmp , sizeof(owner) , 1 , fp );
        *pnew = tmp ;
    }
    pnew->next = NULL ;

    fclose(fp) ;

    return head ;
}

void wtowner( owner *head ){        //write the owner linked list into owner.dat then free the list by the head pointer

    FILE *fp ;
    fp = fopen("owner.dat", "wb");

    set *pnew = head->next ;
    free(head) ;

    while( pnew != NULL ){
        fwrite( pnew , sizeof(owner) , 1 , fp );
        head = pnew ;
        pnew = pnew->next ;
        free(head) ;
    }

    fclose(fp);
}

void pt_1_house( house *p ){
    printf("\t\t%-7s   %-25s  %-15s %-15s %-15s\n","Area","Address","Household ID","Resident ID","Monthly rent");
    printf("\t\t%3uM^2    No.%-2d %d/F Area %c Unit %-2d   %05u           %05u           %4u Yuan\n", p->room , p->ID%100 , p->ID/100%10 , 'A' + p->ID/1000%10 , p->ID/10000 , p->owner_ID , p->user_ID , p->fee );
}

void pt_all_house( house *p ){
    p = p->next ;
    if( p == NULL ){
        printf("\t\tNo house!\n");
        return ;
    }
    printf("\t\t%-7s   %-25s  %-15s %-15s %-15s\n","Area","Address","Household ID","Resident ID","Monthly rent");
    while( p!= NULL){
        printf("\t\t%3uM^2    No.%-2d %d/F Area %c Unit %-2d   %05u           %05u           %4u Yuan\n", p->room , p->ID%100 , p->ID/100%10 , 'A' + p->ID/1000%10 , p->ID/10000 , p->owner_ID , p->user_ID , p->fee );
        p = p->next ;
    }
}

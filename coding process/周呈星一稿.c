#include <stdio.h>
#include <stdlib.h>


                //此程序中show函数和两个菜单可能存在未对其的情况，原谅解
struct Set
{
    unsigned int ID;//23410 == 2单元D区4楼10号
    char name[40];
    unsigned int num;
    unsigned int use_ing;
    float fee;
    struct Set *next;
};

typedef struct Set set;

set *mkset(set* head);//file->link

void* wtset(set *head );//link->file

void* addset(set* head);//facility add

void* dtset(set* head);//facility delete

void* chset(set* head);//change facility information

void* show(set* head);//list all the facility information

int main()
{
    system("color f0");
    set* sset =NULL;
    sset = mkset(sset);//initialize and get the link
    fly :
    printf("\t\tPlease enter which part of information you would like to change:\n\t\t");
    int choice;
    printf("\t\t|-------------facility-system-------------|\n");
    printf("\t\t|        1   facility add                    |\n");
    printf("\t\t|        2   facility delete                    |\n");
    printf("\t\t|        3   facility change                 |\n");
    printf("\t\t|        4   facility show                  |\n");
    printf("\t\t|        5   exit                   |\n");
    printf("\t\t|--------------------------------------|\n");
    printf("\n\t\tPlease enter your choice (1-5): ");
    scanf("%d" , &choice);
    switch(choice)
    {
        case 1:
            addset(sset);
            goto fly;
        case 2:
            dtset(sset);
            goto fly;
        case 3:
            chset(sset);
            goto fly;
        case 4:
            show(sset);
            goto fly;
        case 5:
            return 0;
        default :
            printf("\t\tSorry I can't get your command.\n");
            printf("\t\tPlease enter again.");
            goto fly;
    }
}



set *mkset(head)//get link
{                       //read set data from set.dat and creat a linked list ,return its head pointer
                                    //>>>Attention: the first node in the list _IS_NOT_ data !<<<

    FILE *fp ;
    fp = fopen("set.dat", "rb");

    set *head = (set*)malloc(sizeof(set));
    set *pnew = (set*)malloc(sizeof(set));
    head->next = pnew ;

    set tmp ;
    fread( &tmp , sizeof(set) , 1 , fp );
    *pnew = tmp ;
    while( !feof(fp) )
    {
        pnew->next = (set*)malloc(sizeof(set));
        pnew = pnew->next ;
        fread( &tmp , sizeof(set) , 1 , fp);
        *pnew = tmp ;
    }
    pnew->next = NULL ;

    fclose(fp) ;

    return head ;
}



void wtset( set *head )//get file and delete link
{        //write the set linked list into set.dat then free the list by the head pointer

    FILE *fp ;
    fp = fopen("set.dat", "wb");

    set *pnew = head->next ;
    free(head) ;

    while( pnew != NULL )
    {
        fwrite( pnew , sizeof(set) , 1 , fp );
        head = pnew ;
        pnew = pnew->next ;
        free(head) ;
    }

    fclose(fp);
    return;
}



void dtset(set* head)//link->deset->file
{
    set *p = head->next;
    set *q = p;
    printf("\t\tPlease enter the ID of the facility that you would like to delete:\t");
    unsign int target = 0;
    scanf("%u" , &target);
    while(q->next->ID != target)//find where to delete
    {
        q = p->next;
        p = q;
    }
    q = p->next;//q is the position to be deleted
    p->next = q->next;
    free(q);
    wtset(head);
    printf("\t\tDelete finished.\n");
    return;
}



void addset(set* head)//link->addset->file
{
    set* p = head->next ,* pnew;
    while(p->next != NULL)//p is used to find the last position
        p = p->next;
    pnew = (set*)malloc(sizeof(set));
    printf("\n\n\t\tPlease enter the ID of the new facility.\n");
    printf("\t\t");
    scanf("%u" , &pnew->ID);
    printf("\n\n\t\tPlease enter the name of the new facility.\n");
    printf("\t\t");
    scanf("%s" , pnew->name);
    printf("\n\n\t\tPlease enter the number of the new facility.\n");
    printf("\t\t");
    scanf("%s" , &pnew->num);
    pnew->use_ing = 0;
    printf("\n\n\t\tPlease enter the fee(per hour) of the new facility.\n");
    printf("\t\t");
    scanf("%s" , &pnew->fee);
    p->next = pnew;
    pnew->next = NULL;
    wtset(head);
    printf("Add finished");
    return;
}



void chset(set* head)
{
    set *p = head->next;
    printf("\t\tPlease enter the ID of the facility that you would like to delete:\t");
    unsign int target = 0;
    scanf("%u" , &target);
    while(p->ID != target)//find where to change
        p = p->next;
    flag :
    printf("\t\tPlease enter which part of information you would like to change:\n\t\t");
    printf("\t\t|-------------facility-change-system-------------|\n");
    printf("\t\t|        1   ID                    |\n");
    printf("\t\t|        2   name                    |\n");
    printf("\t\t|        3   number                  |\n");
    printf("\t\t|        4   use_ing                  |\n");
    printf("\t\t|        5   fee                |\n");
    printf("\t\t|--------------------------------------|\n");
    printf("\n\t\tPlease enter your choice (1-5): ");
    int choice;
    scanf("%d" , &choice);
    switch(choice)
    {
        case 1:
            printf("\t\tPlease enter the new ID :\n\t\t");
            scanf("%u" , &p->ID);
            wtset(head);
            break;
        case 2:
            printf("\t\tPlease enter the new name :\n\t\t");
            scanf("%s" , p->name);
            wtset(head);
            break;
        case 3:
            printf("\t\tPlease enter the new name :\n\t\t");
            scanf("%u" , &p->num);
            wtset(head);
            break;
        case 4:
            printf("\t\tPlease enter the new use_ing :\n\t\t");
            scanf("%s" , &p->use_ing);
            wtset(head);
            break;
        case 5:
            printf("\t\tPlease enter the new fee :\n\t\t");
            scanf("%s" , &p->fee);
            wtset(head);
            break;
        default :
            printf("\t\t!! wrong !!\n");
            goto flag;
            break;
    }
    printf("\t\tChange finished.");
    return;
}


void show(set *head)
{
    set *q , *p;
    p = head;
    printf("\t\tID   name   number   use_ing    fee\n\n");
    while(p->next != NULL)
    {
        q = p->next;
        printf( "\n\n\t\t%u\t%-12s\t%-2u\t%u\t%u\n" , q->ID , q->name ,
        q->num, q->use_ing , q->fee);
        p = q;
    }
    printf("\t\tthe location :\n\n\t\t");
    p = head;
    while(p->next != NULL)
    {
        q = p->next;
        printf("\t\t%s  :" , q->name);
        int a = q->ID / 10000;
        int b = (q->ID % 10000) / 1000;
        int c = (q->ID %1000) / 100;
        int d = q->ID % 100;
        printf("\t\t%d unit %d area %d floor %-2d number\n" , a , b , c , d);
    }
    printf("Show finished.");
    return;
}
//                  佛祖保佑             永无BUG

//                  佛曰:

//                  写字楼里写字间，写字间里程序员；
//                  程序人员写程序，又拿程序换酒钱。
//                  酒醒只在网上坐，酒醉还来网下眠；
//                  酒醉酒醒日复日，网上网下年复年。
//                  但愿老死电脑间，不愿鞠躬老板前；
//                  奔驰宝马贵者趣，公交自行程序员。
//                  别人笑我忒疯癫，我笑自己命太贱；
//                  不见满街漂亮妹，哪个归得程序员？

/*
_______________#########_______________________
______________############_____________________
______________#############____________________
_____________##__###########___________________
____________###__######_#####__________________
____________###_#######___####_________________
___________###__##########_####________________
__________####__###########_####_______________
________#####___###########__#####_____________
_______######___###_########___#####___________
_______#####___###___########___######_________
______######___###__###########___######_______
_____######___####_##############__######______
____#######__#####################_#######_____
____#######__##############################____
___#######__######_#################_#######___
___#######__######_######_#########___######___
___#######____##__######___######_____######___
___#######________######____#####_____#####____
____######________#####_____#####_____####_____
_____#####________####______#####_____###______
______#####______;###________###______#________
________##_______####________####______________
 */


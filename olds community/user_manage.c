#include "head.h"


void del(user *head1 , house *head2 )//删除user(head1 是user的头  head2是房屋的头)
{
    unsigned int key ;
    unsigned int address ;

    printf("\t\tPlease input the user ID you want:\n\t\t" );

    fflush(stdin);
    scanf("%u",&key) ;

    user *p = head1->next ;
    user *q = head1 ;
    house *j = head2->next ;

    while( p ){
        if( key == p->ID ){
            printf("\t\tUser found.\n");

            while( j ){
                if( address == j->user_ID ){
                    printf("\t\tHouse found.\n");
                    printf("\t\tRemoving from:\n\n");
                    pt_1_house( j );
                    j->user_ID = 0 ;
                }
                j = j->next ;
            }

            q->next = p->next ;
            free(p) ;
            break ;
        }
        q = p ;
        p = p->next ;
    }

    if( p == NULL ){
        printf("No such user!\n");
        system("pause") ;
        return ;
    }

    wtuser( head1 );            //rewrite user.dat
}


void change(user *head)//改
{
    unsigned int key;
    int i,t;
    user *p;
    p=head->next;
    for(i=0;;i++)
    {
        if(p->next==NULL)
        {
            printf("No such user!");
            return;
        }

        if(key==p->ID)
        {
            printf("Please input the houseID,VIP time and entertainment");
            scanf("%u%u%u",&p->houseID,&t,&p->play);
        }
    }
}

void newVIP(user *head,unsigned int key)//新建会员
{
    int t;
    user *p;
    p=head->next;
    printf("Please input the time %d",t);
    scanf("%d",&t);
    while(p)
    {
        if(p->ID==key)
            {
                p->VIP_t=time(NULL)+t*60;
                return;
            }
            p=p->next;
    }
    if(p==NULL)
    {
        printf("No such user!");
        return;
    }
}

void delVIP(user *head,unsigned int key)//删除会员
{
    user *p;
    p=head->next;
    while(p)
    {
        if(p->ID==key)
        {
            p->points=p->VIP_t/10000;//     转换方式未定！！！！！
            p->VIP_t=0;
            return;
        }
        p=p->next;
    }
    if(p=NULL)
    {
        printf("No such user!!");
        return;

    }
}


void renewVIP(user *head)// 会员续费
{
    unsigned int key;
    user *p;
    int t;
    float money;
    printf("Please input the ID of the VIP:");
    scanf("%u",&key);
    p=head->next;
    while(p)
    {
        if(key==p->ID)
        {
            printf("Please input the time you want to add into the VIP:");
            scanf("%d",&t);
            money=t*100;// 多少钱等于多少时长！！！！！！！
            printf("Please pay %f",money);
            p->VIP_t=p->VIP_t+t*60;  // 同上！！！！！！
            printf("Success!!\n");
            return;
        }
        p=p->next;
    }
    if(p=NULL)
    {
        printf("No such user !!");
        return;
    }
}

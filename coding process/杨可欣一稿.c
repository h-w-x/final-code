#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Set{//设施
    unsigned int ID;//地址，方案同上
    char name[40];//名称
    unsigned int num;//总数量
    unsigned int using;//在用数量
    float fee;//费用
    struct Set* next;
};

struct House{//住房
    unsigned int room;//面积
    unsigned int ID;//地址，如：23456->2单元D区4楼56号，获取‘区’的方法是'A'+(ID/1000)%10
    unsigned int owner_ID;//户主ID，未购买初始化为0
    unsigned int user_ID;//住户ID，不入住初始化为0
    unsigned int fee;//月租金，不出租初始化为0
    unsigned int fee_m;//用户要求的最高租金
    struct House* next;
};

struct User{//住户
    unsigned int ID;//住户编号
    time_t VIP_t;//会员结束时间，非会员初始化为0
    unsigned int points;//会员积分
    unsigned int houseID;//住房地址
    unsigned int play;//娱乐设施地址，未在娱乐初始化为0
    struct User* next;
};

struct Owner{//户主
    unsigned int ID;//户主编号，与住户编号不重合
    struct Owner* next;
};

typedef struct House house ;
typedef struct Set set ;
typedef struct User user ;
typedef struct Owner owner ;
void del(user *head1,user *head2);
void change(user *head);
void newVIP(user *head,unsigned int key);
void delVIP(user *head,unsigned int key);
void renewVIP(user *head);


void del(user *head1,user *head2)//删除(head1 是user的头  head2是房屋的头)
{
    unsigned int key;
    unsigned int address;
    printf("Please input the user you want:^%u",key);
    scanf("%u",&key);
    user *p,*j;
    p=head1->next;
    while(p)
    {
        if(key==p->ID)
        {
            address=p->houseID;
            free(p);
        }
        p=p->next;
    }
    if(p==NULL)
    {
        printf("No such user!");
        return;
    }
    j=head2->next;
    while(j)
    {
        if(address==j->ID)
            free(j);
    }
    if(j==NULL)
    {
        printf("Can not find any information about user's House！");
    }
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

//p->VIP_t = time(NULL) + t*60 ;



#endif // HEAD_H_INCLUDED

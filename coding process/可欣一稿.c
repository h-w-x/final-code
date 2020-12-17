#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct Set{//��ʩ
    unsigned int ID;//��ַ������ͬ��
    char name[40];//����
    unsigned int num;//������
    unsigned int using;//��������
    float fee;//����
    struct Set* next;
};

struct House{//ס��
    unsigned int room;//���
    unsigned int ID;//��ַ���磺23456->2��ԪD��4¥56�ţ���ȡ�������ķ�����'A'+(ID/1000)%10
    unsigned int owner_ID;//����ID��δ�����ʼ��Ϊ0
    unsigned int user_ID;//ס��ID������ס��ʼ��Ϊ0
    unsigned int fee;//����𣬲������ʼ��Ϊ0
    unsigned int fee_m;//�û�Ҫ���������
    struct House* next;
};

struct User{//ס��
    unsigned int ID;//ס�����
    time_t VIP_t;//��Ա����ʱ�䣬�ǻ�Ա��ʼ��Ϊ0
    unsigned int points;//��Ա����
    unsigned int houseID;//ס����ַ
    unsigned int play;//������ʩ��ַ��δ�����ֳ�ʼ��Ϊ0
    struct User* next;
};

struct Owner{//����
    unsigned int ID;//������ţ���ס����Ų��غ�
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


void del(user *head1,user *head2)//ɾ��(head1 ��user��ͷ  head2�Ƿ��ݵ�ͷ)
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
        printf("Can not find any information about user's House��");
    }
}


void change(user *head)//��
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

void newVIP(user *head,unsigned int key)//�½���Ա
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

void delVIP(user *head,unsigned int key)//ɾ����Ա
{
    user *p;
    p=head->next;
    while(p)
    {
        if(p->ID==key)
        {
            p->points=p->VIP_t/10000;//     ת����ʽδ������������
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


void renewVIP(user *head)// ��Ա����
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
            money=t*100;// ����Ǯ���ڶ���ʱ����������������
            printf("Please pay %f",money);
            p->VIP_t=p->VIP_t+t*60;  // ͬ�ϣ�����������
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

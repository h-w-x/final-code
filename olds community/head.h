#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct House{           //ס��
    unsigned int room;  //���
    unsigned int ID;    //��ַ���磺23456->2��ԪD��4¥56�ţ���ȡ�������ķ�����'A'+(ID/1000)%10
    unsigned int owner_ID;//����ID��δ�����ʼ��Ϊ0
    unsigned int user_ID;//ס��ID������ס��ʼ��Ϊ0
    unsigned int fee;   //����𣬲������ʼ��Ϊ0
    unsigned int fee_m; //�û�Ҫ���������
    struct House* next;
};

struct Set{             //��ʩ
    unsigned int ID;    //��ַ������ͬ��
    char name[40];      //����
    unsigned int num;   //������
    unsigned int using; //��������
    float fee;          //����
    struct Set* next;
};

struct User{            //ס��
    unsigned int ID;    //ס�����
    time_t VIP_t;       //��Ա����ʱ�䣬�ǻ�Ա��ʼ��Ϊ0
    unsigned int points;//��Ա����
    unsigned int houseID;//ס����ַ
    unsigned int play;  //������ʩ��ַ��δ�����ֳ�ʼ��Ϊ0
    struct User* next;
};

struct Owner{           //����
    unsigned int ID;    //������ţ���ס����Ų��غ�
    struct Owner* next;
};

typedef struct House house ;
typedef struct Set set ;
typedef struct User user ;
typedef struct Owner owner ;

house *mkhouse();
void wthouse( house *head );
user *mkuser();
void wtuser( user *head );
set *mkset();
void wtset( set *head );
owner *mkowner();
void wtowner( owner *head );


#endif // HEAD_H_INCLUDED

#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct House{           //住房
    unsigned int room;  //面积
    unsigned int ID;    //地址，如：23456->2单元D区4楼56号，获取‘区’的方法是'A'+(ID/1000)%10
    unsigned int owner_ID;//户主ID，未购买初始化为0
    unsigned int user_ID;//住户ID，不入住初始化为0
    unsigned int fee;   //月租金，不出租初始化为0
    unsigned int fee_m; //用户要求的最高租金
    struct House* next;
};

struct Set{             //设施
    unsigned int ID;    //地址，方案同上
    char name[40];      //名称
    unsigned int num;   //总数量
    unsigned int using; //在用数量
    float fee;          //费用
    struct Set* next;
};

struct User{            //住户
    unsigned int ID;    //住户编号
    time_t VIP_t;       //会员结束时间，非会员初始化为0
    unsigned int points;//会员积分
    unsigned int houseID;//住房地址
    unsigned int play;  //娱乐设施地址，未在娱乐初始化为0
    struct User* next;
};

struct Owner{           //户主
    unsigned int ID;    //户主编号，与住户编号不重合
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

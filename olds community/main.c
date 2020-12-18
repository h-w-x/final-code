#include "head.h"

int main(){
    srand(time(NULL));
    house tmp1[1500] = {0} ;
    int i ;
    for( i=0 ; i<1500 ; i++ ){
        tmp1[i].room = 80 + rand()%40 ;
        tmp1[i].ID = 10101 + i%12 + (i/12)%6*100 + (i/12/6)%3*1000 + (i/12/6/3)%8*10000 ;
        tmp1[i].fee = rand()%50*2000 + tmp1[i].room*5000 ;
        tmp1[i].next = &tmp1[i+1] ;
    }
    tmp1[1499].next = NULL ;

    wthouse( tmp1 );

    pt_all_house( tmp1 );

    return 0;
}

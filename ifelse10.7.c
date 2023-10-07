#include "stdio.h"
int ifmain(){
    int x;
    scanf_s("%d",&x);

    if (x>90){
    printf("very good");}
    else if (x>80)
    printf("good");
    else if (x>70)
     printf("medium");
    else if (x>60)
     printf("bad");
    else
     printf("very bad");
    return 0;
}


int main(){
    int x;
    scanf_s("%d",&x);
    if (x<0){
        printf("-1");
    }
    else if (x>0) {
        printf("1");
    }
    else{
        printf("0");
    }

}


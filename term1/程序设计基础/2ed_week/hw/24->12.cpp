#include<stdio.h>

int main(void){
    int hour, minute, flag;
    hour = minute = flag = 0;
    scanf("%d %d", &hour, &minute);

    flag = (hour >= 12)? 1 : 0;
    hour = (hour > 12)? hour-12 : hour;
    hour = (hour == 0)? 12 : hour;

    (flag == 0)? printf("%d:%dam", hour, minute) : printf("%d:%dpm", hour, minute);
    return 0;
}

# include<stdio.h>

int main(void){
    int target = 2620;
    int i = 1, sum = 0;
    for ( ; i < target; ++i) {
        (target % i == 0)? sum += i:1;
    }
    printf("%d", sum);
    return 0;
}

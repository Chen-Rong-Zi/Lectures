# include<stdio.h>

int main(void){
    float x = 1.0;
    printf("%d\n", *(unsigned *)&x);
    return 0;
}

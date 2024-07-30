# include<stdio.h>

int main(void){
    int a = 0, b = 0, c = 0;

    scanf("%d %d %d", &a, &b, &c);
    if ( (a ^ b) == 0 ){
        printf("%d", c);
        return 0;
    }
    else if ( (a ^ c) == 0 ){
        printf("%d", b);
        return 0;
    }
    else if ( (b ^ c) == 0 ){
        printf("%d", a);
        return 0;
    }
    return 0;
}

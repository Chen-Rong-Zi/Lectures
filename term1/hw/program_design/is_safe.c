# include<stdio.h>

int main(void){
    int a = 0, b = 0;

    scanf("%d %d", &a, &b);
    if ( a >= 0 && b >= 0 )
        (a + b >= a && a + b >= b)? printf("Safe"):printf("Unsafe");
    else if ( a < 0 && b < 0 )
        (a + b < a && a + b < b)?printf("Safe"):printf("Unsafe");
    else
        printf("Safe");
    return 0;
}

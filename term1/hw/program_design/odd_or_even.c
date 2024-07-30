# include <stdio.h>

int main(void){
    int a = 0;
    scanf("%d", &a);

    if ( (a & 1) == 1 )
        printf("odd");
    else
        printf("even");
    return 0;
}


# include<stdio.h>

int main(void){
    int a = 0;
    int i;
    scanf("%d", &a);
    for (i = 2; i < a; ++i) {
        if ( a % i == 0){
            printf("%d is not sushu\n", a);
            break;
        }
    }
    if ( i == a)
        printf("%d is sushu\n", a);
    return 0;
}

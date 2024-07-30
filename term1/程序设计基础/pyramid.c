# include<stdio.h>

int main(void){
    int i, j, n, k, x, l; i = j = n = k = x = l = 0;
    scanf("%d", &n);
    k = n - 1;
    x = n;
    for ( i = 0; i < x-1; ++i) {
        for ( k = n - 1; k > 0; --k) {
            printf(" ");
        }
        if ( i != 0 )
            printf("*");

        for (j = 0 ; j < 2 * i - 1; ++j) {
            if ( i == 0 )
                break;
            printf(" ");
        }
        printf("*\n");
        n -= 1;
    }
    for ( l = 0; l < 2 * x - 1; ++l) {
        printf("*");
    }
    printf("\n");
    return 0;
}

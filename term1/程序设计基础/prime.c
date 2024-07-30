# include<stdio.h>

int main(void) {
    int i, j, n;
    scanf("%d", &n);
    for ( i = n; ; ++i ) {
        for ( j = 2; j < i; ++j) {
            if ( i % j == 0 )
                break;
        }
        if ( i == j && i != 0){
            printf("%d\n", i);
            return 1;
        }
    }
    return 0;
}


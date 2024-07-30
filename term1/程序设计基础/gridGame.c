# include<stdio.h>

int main(void){
    int n, k, m, i, step; n = k = m = i = step = 0;
    scanf("%d %d %d", &n, &k, &m);
    step = 1;
    for ( ; i < m; ++i) {
        k += step;
        if ( k == n )
            k = 0;
        if ( k == -1 )
            k = n-1;
        if ( k == 0 )
            step = -step;
    }
    printf("%d\n", k);
    return 0;
}

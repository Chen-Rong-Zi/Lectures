# include<stdio.h>

int factor(int n, int sum){
    if ( n == 1 )
        return sum;
    return factor(n-1, sum * n);
}

int main(void)
{
    printf("%d", factor(6, 1));
    return 0;
}

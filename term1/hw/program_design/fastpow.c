# include <stdio.h>
# include <stdlib.h>
# define MOD (long long)(1e9+7)


long long fastpow(int x, int n){
    if ( n == 1 ){
        return x % MOD;
    }
    if ( (n & 1) == 1 ){
        return x * fastpow(x, n-1) % MOD;
    }
    long long temp = fastpow(x, n/2) % MOD;
    return temp * temp % MOD;
}

int main(void){
    int a = 0, n = 0;
    scanf("%d %d", &a, &n);
    printf("%lld", fastpow(a, n));
    return 0;
}

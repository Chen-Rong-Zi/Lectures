# include <stdio.h>
# include <stdlib.h>

long long fib_dp(int n, long long first, long long second){
    if ( n == 1 ) return first;
    return fib_dp(n-1, second, first + second);
}

int main(int arg_number, char **arg_value){
    (arg_number == 2) && (printf("%lld", fib_dp(atoi(arg_value[1]), 0, 1)));
    return 0;
}

# include <stdio.h>

int helper(int n){
    if ( n == 0 || n == 1 ){
        return 1;
    }
    else{
        return helper(n-1) + helper(n-2);
    }

}

int main(void){
    int n = 0;
    scanf("%d", &n);
    printf("%d", helper(n));
    return 0;
}

# include<stdio.h>

int main(void){
    int x, lastDigit, remainDigit, resultDigit, pownet;
    x = lastDigit = remainDigit = resultDigit = 0;
    scanf("%d", &x);
    x = (x > 0)? (pownet=1, x):(pownet=-1, -x);
    while ( x > 0 )
    {
        lastDigit = x % 10;
        remainDigit = x / 10;
        resultDigit = resultDigit * 10 + lastDigit;
        x = x / 10;
    }
    printf("%d\n", resultDigit * pownet);
    return 0;
}

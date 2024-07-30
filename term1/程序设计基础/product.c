# include<stdio.h>

int main(void){
    unsigned x, lastDigit, remainDigit, productDigit = 1, flag = 1;
    x = lastDigit = remainDigit = 0;
    scanf("%d", &x);
    while (flag){
        while ( x > 0 )
        {
            lastDigit = x % 10;
            remainDigit = x / 10;
            productDigit = productDigit * ((lastDigit == 0)?1:lastDigit);
            x = x / 10;
        }
        flag = (productDigit >= 10);
        x = productDigit;
        productDigit = 1;
    }
    printf("%d\n", x);
    return 0;
}

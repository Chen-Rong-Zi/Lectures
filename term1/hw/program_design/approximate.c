# include<stdio.h>
# include<math.h>

int main(void){
    double n = 0.0;
    long x = 0;

    scanf("%lf", &n);
    x = (long)(1000 * n);
//     17.520
    if ( (x % 1000 / 100) <= 4)
        printf("%ld", x / 1000);

    else if ( (x % 1000 / 100) >= 6)
        printf("%ld", x / 1000 + 1);

    else if ( (x % 1000 / 100) == 5){
        if ( x % 100 != 0 )
            printf("%ld", x / 1000 + 1);

        else if ( (x % 10000 / 1000) % 2 == 0 )
            printf("%ld", x / 1000);

        else if ( (x % 10000 / 1000) % 2 != 0 ){
            printf("%ld", x / 1000 + 1);
        }
    }
    return 0;
}

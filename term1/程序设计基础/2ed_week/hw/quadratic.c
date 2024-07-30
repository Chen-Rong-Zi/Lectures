#include<stdio.h>
#include<math.h>

int main(){
    double a, b, c, delta;
    scanf("%lf %lf %lf", &a, &b, &c);
    if ( a == 0 ){
        printf("it is not a quadratic\n");
        if ( b != 0 ){
            printf("answear is %lf\n", c / b);
        }
    }
    else if ( (delta = b * b - 4 * a * c) > 0 ){
        printf("answear is %.3lf and %.3lf\n", (delta) / 2.0 * a, (-b - sqrt(delta) / 2.0 * a));
    }
    else
        printf("no such answear!\n");
    return 0;
}

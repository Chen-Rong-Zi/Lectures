# include<stdio.h>
# include<math.h>

int main(void){
    int k = 0, num = 0, i = 0;
    double result = 0.0;

    scanf("%d %d", &k, &num);
    while ( num != 0 ){
        result += pow(k, i) * (num % 10);
        num /= 10;
        ++i;
    }
    printf("%d\n", (int)result);
    return 0;
}

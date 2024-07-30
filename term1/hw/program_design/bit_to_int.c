# include<stdio.h>
# include<math.h>

int main(void){
    char c = 0, flag = 0;
    double result = 0;
    int i = 0;

    i = 31;
    while ( (c = getchar()) != EOF  && i >= 0)
    {
        if ( c == '1' && i == 31 )
            flag = 1;
        if ( flag == 1 ){
            result += pow(2, i) * (1^(c-48));
        }
        else if ( flag == 0 ){
        result += pow(2, i) * (c-48);
        }
        --i;
    }
    (flag == 1)?printf("%d\n", (int)(-(result+1))):printf("%d\n", (int)(result));
    return 0;
}
//         printf("pow = %lf, result = %lf\n", pow(2, i) * (double)(1^(c-48)), result);

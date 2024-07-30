# include<stdio.h>

void reverse(double array[], int n){
    double temp = 0;
    for ( int i = 0;  i < n/2; ++i){
        temp = array[i];
        array[i] = array[n-1-i];
        array[n-1-i] = temp;
    }
}

int main(void){
    int n = 0;
    double input[100] = {0};
    scanf("%d", &n);
    for ( int i = 0; i < n; ++i){
        scanf("%lf", &input[i]);
    }
    reverse(input, n);
    for ( int i = 0; i < n; ++i){
        printf("%.2lf ", input[i]);
    }
    return 0;
}

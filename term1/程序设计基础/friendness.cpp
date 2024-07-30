# include <iostream>
using namespace std;

int isPrime(int n){
    int i = 0;
    for ( i = 2; i < n; ++i) {
        if ( n % i == 0 )
            break;
    }
    if ( i >= n )
        return 1;
    return 0;
}

double max(double a, double b){
    return (a > b)? a:b;
}


double friendnessOf(int a, int b){
    int bigger = max(a, b);
    int smaller = a + b - bigger;
    int i = smaller;
    int sum = 0;

    for ( ; i <= bigger; ++i){
        if ( isPrime(i) ){
            sum += i;
            printf("friendnessOf(%d, %d), i = %d\n", a, b, i);
        }
    }
//     printf("friendnessOf(%d, %d) = %lf\n", a, b, (sum != 0)?(sum * 1.0) / (a * b):1.0 / (a * b));
    return (sum != 0)?((sum * 1.0) / (double)a / b):(1.0 / (double)a / b);
}

int main(void){
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
    cin >> n1; cin >> n2; cin >> n3; cin >> n4;
    printf("%.6lf", max(friendnessOf(n1, n2), max(friendnessOf(n1, n3), max(friendnessOf(n1, n4), max(friendnessOf(n2, n3), max(friendnessOf(n2, n4), friendnessOf(n3, n4)))))));
    return 0;
}

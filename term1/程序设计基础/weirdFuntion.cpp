# include <iostream>
# include <cmath>
using namespace std;

long times = 0;

long isPrime(long n){
    long i = 0;
    for ( i = 2; i < n; ++i) {
        if ( n % i == 0 )
            break;
    }
    if ( i == n )
        return 1;
    return 0;
}

long onlyint(double x){
    long i = 0;
    for ( i = 0; i < x-1; ++i);
    return i;
}

long f(long x){
    ++times;
    long n1 = 0, n2 = 0;
    n1 = x + onlyint((double )(x)/10) + (double )123456;
    n2 = 2e9 - x;
    return (n1 < n2)? n1:n2;
}

long reversedNumber(long x){
    long lastNum = 0, newNum = 0;
    while ( x > 0 ){
        lastNum = x % 10;
        newNum = newNum * 10 + lastNum;
        x /= 10;
    }
    return newNum;
}

long g(long x){
    ++times;
    long lastNum = 0, newNum = 0, newNewNum = 0, flag = 1, trailZero = 0;
    // 100350060400 --> 60400
    while ( x > 0 ){
        lastNum = x % 10;
        if ( lastNum % 2 == 0 && lastNum != 0 )
            flag = 0;
        if ( flag && lastNum == 0 )
            ++trailZero;
        if ( lastNum % 2 == 0 ){
            newNum = newNum * 10 + lastNum;
        }
        x /= 10;
    }
    while ( newNum > 0 ){
        lastNum = newNum % 10;
        if ( lastNum % 2 == 0 ){ newNewNum = newNewNum * 10 + lastNum; }
        newNum /= 10;
    }
    return newNewNum * pow(10, trailZero);
}


long h(long x){
    return (isPrime(times))? f(g(x)) : g(f(x));
}

int main(void){
    long x = 0, m = 0;
    char i = '0';
    cin >> x, cin >> m;
    while ( cin >> i ){
        if ( i == 'g' ){
            x = g(x);
        }
        else if ( i == 'h' ){
            x = h(x);
        }
        else if ( i == 'f' ){
            x = f(x);
        }
    }
    cout << x << '\n';
    return 0;
}
/*g(x), times = 0, f(g(x)), times = 2, g(f(x))*/

// int main(void){
//     double i = 1.3;
//     int j = 0;
//     for ( ; i < 100; i = i * 2, ++j){
//         printf("i = %lf\t%dth = %ld\n", i, j, (long)floor(i));
//     }
//     return 0;
// }

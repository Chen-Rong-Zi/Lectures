#include <iostream>
using namespace std;

int first = 0;
int trail = 0;

int hasZero(int x){
    if ( x == 0 )
        return 1;
    while ( x >= 10 ){
        if ( x % 10 == 0 )
            return 1;
        x /= 10;
    }
    return 0;
}

int isArithmetic(int n){
    int leftNum = 0, lastNum = 0, oldSubstraction = 0, substraction = 0;
    if ( hasZero(n) || n <= 10 ){
        return 0;
    }
    oldSubstraction = n % 10 - (n / 10) % 10;
    trail = n % 10;
    while ( n > 10 ){
        lastNum = n % 10;
        leftNum = n / 10;
        substraction = lastNum - leftNum % 10;
        if ( (oldSubstraction != substraction) || substraction == 0) {
            return 0;
        }
        oldSubstraction = substraction; first = n / 10; n /= 10;
    }

    first = first + trail;
    return 1;
}

int main(void){
    int i = 0, sum = 0, n = 0;
    cin >> n;
    for ( i = 10; i <= 1e6; ++i){
        if ( isArithmetic(i) && (first == n) ){
            sum += i;
        }
    }
    (sum == 0)? cout << -1:cout << sum;
    return 0;
}

#include <iostream>
using namespace std;

int list[6000] = {0};
int first = 0;
int trail = 0;

int hasZero(int x){
    if ( x == 0 )
        return 1;
    while ( x > 10 ){
        if ( x % 10 == 0 )
            return 1;
        x /= 10;
    }
    return 0;
}


int isArithmetic(int n){
    int leftNum = 0, lastNum = 0, oldSubstraction = 0, substraction = 0;
    if ( hasZero(n) || n <= 10){
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
    int i = 0, line = 0, n = 0;
    cin >> line;
    for (i = 0 ; i < line; ++i) {
        cin >> n;
        list[i] = n;
    }
    for ( i = 0; i < line; ++i) {
        n = list[i];
        if ( isArithmetic(n) ){
            cout << first << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }
    return 0;
}

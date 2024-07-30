#include <iostream>
using namespace std;

int is_prime(int n){
    // *** YOUR CODE HERE ***
    int i = 0;

    if ( n < 2 )
        return 0;
    for ( i = 2; i < n; ++i) {
        if ( n % i == 0 )
            break;
    }
    if ( i >= n )
        return 1;
    return 0;
}

int main(void){
    int n = 0, i = 0;
    cin >> n;
    for ( i = 2; i > 0; ++i) {
        if ( is_prime(i) && is_prime(n-i) ){
            cout << i << ' ' << n-i;
            return 0;
        }
    }
}

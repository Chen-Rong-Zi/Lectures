#include <cmath>
#include <iostream>
using namespace std;

// *** YOUR CODE HERE ***
int invocation_number = 0;

int is_prime(int n){
    // *** YOUR CODE HERE ***
    int i = 0, j = 0;
    for ( i = 0; i < (j=sqrt(n)); ++i) {
        if ( n % i == 0 )
            break;
    }
    if ( i >= j )
        return 1
    return 0
}

int main()
{
    int n;
    while(!cin.eof()){
        cin >> n;
        cout << is_prime(n) << " " << invocation_number << endl;
    }

    return 0;
}


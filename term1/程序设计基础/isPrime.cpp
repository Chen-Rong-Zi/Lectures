#include <iostream>
using namespace std;

// *** YOUR CODE HERE ***
int invocation_number = 0;

int is_prime(int n){
    // *** YOUR CODE HERE ***
    ++invocation_number;
    int i = 0;
    for ( i = 2; i < n; ++i) {
        if ( n % i == 0 )
            break;
    }
    if ( i >= n )
        return 1;
    return 0;
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


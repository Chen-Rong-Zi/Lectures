# include<iostream>
using namespace std;

int main(void){
    unsigned n;
    cin >> n;
    do{
        cout << n % 10 << endl;
        n /= 10;
    }
    while ( n > 0 );
    return 0;
}

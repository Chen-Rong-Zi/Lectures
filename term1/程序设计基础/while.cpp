# include<iostream>
using namespace std;

int main(void){
    unsigned n;
    cin >> n;
    while ( n > 0 ){
        cout << n % 10 << endl;
        n /= 10;
    }
}

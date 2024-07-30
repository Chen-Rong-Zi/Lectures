# include<iostream>
using namespace std;

int main(void){
    unsigned n;
    for (cin >> n; n > 0; n /= 10) {
        cout << n % 10 << endl;
    }
    return 0;
}


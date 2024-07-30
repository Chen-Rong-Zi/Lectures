# include<iostream>
# include<cmath>
using namespace std;

int expomnent(int x){
    int i = 0;
    while ( x > 0 ){
        ++i;
        x /= 10;
    }
    return i;
}

int isFlower(int x){
    int m = expomnent(x), sum = 0, temp = x;
    while ( x > 0 ){
        sum += pow((x % 10), m);
        x /= 10;
    }
    return (sum == temp)? 1:0;
}

int main(void){
    int n = 0, a[6000] = {0}, i = 0;
    cin >> n;
    for ( i = 0; i < n; ++i){
        cin >> a[i];
    }
    for ( i = 0; i < n; ++i){
        cout << isFlower(a[i]) << '\n';
    }

    return 0;
}

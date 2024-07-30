# include<iostream>
# include<cmath>
using namespace std;

int maxSequence(char string[]){
    int i = 0, sum = 1;
    char before = string[0], now = '0';
    for ( i = 1; string[i] != 0; ++i){
        now = string[i];
        if ( now != before ){
            ++sum;
            before = now;
        }
    }
    return sum;
}

int main(void){
    char text[6000] = {0};
    int n = 0, i = 0;
    cin >> n;
    if ( n == 0 ){
        cout << 0;
        return 0;
    }

    for ( i = 0; i < n; ++i){
        cin >> text[i];
    }
    cout << maxSequence(text);
    return 0;
}

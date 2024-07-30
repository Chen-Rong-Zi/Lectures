// 代码模板
#include <iostream>
#include <iomanip>
using namespace std;

// YOUR CODE HERE
int add(int a, int b){
    return a + b;
}

double add(double a, double b){
    return a + b;
}

int add(char *a, char *b){
    int i = 0, j = 0;
    while ( a[i] != '\0' ){++i;};
    while ( b[j] != '\0' ){++j;};
    return i + j;
}
// DONT CHANGE CODE BELOW

int main() {
    int a, b;
    double c, d;
    char x[200];
    char y[200];
    cin >> a >> b;
    cin >> c >> d;
    cin >> x >> y;
    cout << add(a, b) << endl;
    cout << fixed << setprecision(2) << add(c, d) << endl;
    cout << add(x, y) << endl;
}

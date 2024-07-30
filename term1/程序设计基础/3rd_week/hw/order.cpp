#include <iostream>
using namespace std;

int main() {
 int i = 5;
 int j = 10;
 int x = 20;
 int y = 30;
 int result = (i > j) ? ((x > y) ? (i++, x--) : (j--, y++)) : ((i++, x++), (j--, y--));
 cout << "result = " << result << endl;
 cout << "i = " << i << endl;
 cout << "j = " << j << endl;
 cout << "x = " << x << endl;
 cout << "y = " << y << endl;
 return 0;
}

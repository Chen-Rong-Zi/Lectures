#include <iostream>
using namespace std;


int divide(int x, int y) {
    if (y == 0)
        throw 0;
    return x / y;
}

void game() {
    try {
        int a, b;
        cout << "请输入两个数：";
        cin >> a >> b;
        int r = divide(a, b);
        cout << a << "除以" << b << "的商为：" << r << endl;
        return;
    } catch(int) {
        cout << "除数不能为0， 请重新输入两个数：";
        game();
    }
}
int main() {
    game();
    return 0;
}


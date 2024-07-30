#include "MonsterLand.h"

using namespace std;

int arr[105];

int mygcd(int a, int b) {
    int i = (a < b)? a : b;
    for ( ; i > 0; --i )
    {
        if ( a % i != 0 || b % i != 0 )
            break;
    }
    return i + 1;
}

int helper(int n, int *num) {
    if ( n == 2 )
        return mygcd(num[0], num[1]);
    else
        return mygcd(num[0], helper(n - 1, num + 1));
}

void MonsterLand::game(int n, int *num) {
    //TODO 让乐园记录今天的游戏初始状态
    arr[0] = helper(n, num);
}

int MonsterLand::quiz() {
    //TODO 计算出最后留在游戏中的小怪兽的可能的最小宝石数量
    return arr[0];
}

int main()
{
    cout << mygcd(10, 20);
    // int n;
    // cin >> n;
    // for(int i=0;i<n;i++){
        // cin >> arr[i];
    // }
    // MonsterLand s;
    // s.game(n,arr);
    // cout << s.quiz() << endl;
    // return 0;
}

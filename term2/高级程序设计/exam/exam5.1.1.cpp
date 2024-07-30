#include "CallMyName.h"
#include <iostream>
using namespace std;
int funcMyAbs(int a)
{
    return a > 0 ? a : -a;
}
int funcMyAdd(int a, int b)
{
    return a + b;
}
int funcMySub(int a, int b)
{
    return a - b;
}
int funcMyHash(int a, int b)
{
    return a * b % 120;
}
int funcMySum(int a, int b, int c)
{
    return a + b + c;
}
void *functions[5] = {(void *)funcMyAbs, (void *)funcMySub, (void *)funcMyHash, (void *)funcMyAdd,(void *)funcMySum};
int main()
{
    CallMyName call(functions);
    // cout << ((int (*)(int))(functions[0]))  (-1);
    cout << call.call("funcMyAdd(1,2)") << endl; //3
    cout << call.call("funcMySum(1,2,3)") << endl; //6
    cout << call.call("funcMyAbs(-213324)") << endl; //6
    return 0;
}

#include <iostream>
#include "fibnacci.h"
using namespace std;
int main()
{
    static constexpr size_t fib = fibnacci<10>::value;
    cout << fib << endl; // 55
    return 0;
}


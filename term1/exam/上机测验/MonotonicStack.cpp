#include "MonotonicStack.h"
#include <cstdio>

int MonotonicStack::size(){
    // TODO
    return s.size();
}

void MonotonicStack::pop(){
    //TODO
    if ( s.size() !=  0 )
        return s.pop();
    printf("Error! stack explode!\n");
}

int MonotonicStack::top(){
    //TODO
    if ( s.size() > 0 )
        return s.top();
    return 0;
}

int MonotonicStack::push(int element){
    //TODO

    while ( s.size() > 0 && element <= s.top() )
        s.pop();
    int old_top = ((s.size() > 0)? s.top() : 0);
    s.push(element);

    if ( s.size() <= 1 )
        return element;
    // printf("element = %d, old_top = %d\n", element, old_top);
    return s.top() - old_top;
}

int MonotonicStack::function(const int* arr, int n){
    //TODO
    int sum = 0;
    for (  int i = n - 1; i >= 0; --i )
    {
        int value = push(arr[i]);
        // printf("value_arr[%d] = %d\n", i, value);
        sum += value;
    }
    return sum;
}

// *
// 可以使用这个main函数在本地进行调试，但提交时请把这段内容注释
int main() {
    MonotonicStack* ms=new MonotonicStack;
    // int arr[] = {1, 1, 1, 1, 1};
                // 1, 3, 1, 3, 1
    // printf("%d\n", ms->function(arr, 5));
    // delete ms;
    ms->push(1);
    ms->push(2);
    ms->push(3);
    ms->push(4);
    ms->push(5);
    ms->push(6);
    ms->push(7);
    ms->push(8);
    ms->push(9);
    ms->push(10);
    ms->push(11);
    return 0;
}
// */


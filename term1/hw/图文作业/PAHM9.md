##1
```C
# include <stdio.h>
# include <stdlib.h>

long long fib_dp(int n, long long first, long long second){
    if ( n == 1 ) return first;
    return fib_dp(n-1, second, first + second);
}
```
##2
```C
# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int make_random_list(int *array, int lenth){
    int i = 0;
    for ( ; i < lenth; ++i){
        array[i] = rand() % 100;
    }
    return (i == lenth)? 0:1;
}

int select_sort(int *array, int lenth){
    if ( lenth == 0 ) return 0;
    int i = 0, max_index = 0, temp = 0;
    for ( i = 0; i < lenth; ++i){
        (array[i] >= array[max_index]) && (max_index = i);
    }
    if ( array[lenth-1] != array[max_index] ){
        array[lenth-1]   = array[lenth-1] ^ array[max_index];
        array[max_index] = array[lenth-1] ^ array[max_index];
        array[lenth-1]   = array[lenth-1] ^ array[max_index];
    }
    return select_sort(array, lenth-1);
}

int main(void){
    int lst[10] = {0}, i = 0;
    srand(time(NULL));
    make_random_list(lst, 10);
    select_sort(lst, 10);
    for ( ; i < 10; ++i){
        printf("%d\t", lst[i]);
    }
    return 0;
}
```

##3
宏定义不进行类型检查，内联函数则相反。
宏定义文本替换后有可能因为运算符号优先级的原因产生未预期的效果
内联函数可能会增大可执行文件的体积

##4
    1.main函数不能作为内联函数
    2.递归函数无法作为内联函数，否则会一直展开代码

##5
    函数默认参数能够简化函数调用的操作，使得调用者更易使用代码，完善了抽象封装的概念
    函数重载的绑定有以下情况：
            1.参数个数不同
            2.参数类型不同
            3.参数常量性不同

##6



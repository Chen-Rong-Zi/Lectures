# include <iostream>
# include <vector>
# include <functional>
// # include "functional.h"

using namespace std;

void print(...) {
    cout << endl;    // root case
}

template <typename T, typename... Args>
void print(T car, Args... args) {
    cout << car << ' ';
    return print(args...);
}


template <typename F, typename L, typename Y>
Y reduce(F func, L lst, Y initial=0) {
    if ( lst.size() == 0 )
        return initial;

    // 表明了一定是一个迭代器
    L cdr_lst(lst.begin() + 1, lst.end());

    return reduce(func, cdr_lst, func(initial, lst[0]));
}


template <typename F, typename L>
L map(F map_func, L lst) {
    auto func = [&](L pre, auto curr){
        pre.push_back(map_func(curr));
        return pre;
    };
    L empty_list;
    return reduce(func, lst, empty_list);
}

template <typename L, typename F>
L filter(F filter_func, L lst) {
    auto func = [&](L pre, auto curr){
        if ( filter_func(curr) )
            pre.push_back(curr);
        return pre;
    };

    L empty_list;
    return reduce(func, lst, empty_list);
}


template <typename L, typename F>
L compose(F working_list, L initial) {
    auto func = [&](L pre, auto curr){
        return curr(pre);
    };
    return reduce(func, working_list, initial);
}

int add1(int x) {
    return x + 1;
}

int mul2(int x) {
    return x * 2;
}

template <typename F>
class Factor {
    F func;
public:
    Factor(F func) {
        this->func = func;
    }
    auto operator()(auto para) {
            return (this->func)(para);
    }

};

bool is_even(int x) {
    return x % 2 == 0;
}



int mul6(int a1, int a2, int a3, int a4, int a5, int a6) {
    return a1 * a2 * a3 * a4 * a5 * a6;
}

vector<int> mymap(function<int(int)> map_func, vector<int> array) {
    return map(map_func, array);
}

int add3(int a, int b, int c) {
    return a + b + c;
}

template <typename Callable, typename... Params>
auto curry(Callable func, Params... params) {
    if constexpr ( requires { func(params...); } ) {
        return func(params...);
    }
    else {
        return [func, params...] (auto... new_params) {
            return curry(func, params..., new_params...);
        };
    }
}

int main(int arg_number, char **arg_value) {
    vector<int>    array_1 = {0,   1,   2,   3,   4,   5,   6,   7,   8,   9,   10};
    vector<double> array_2 = {0.1, 1.1, 2.1, 3.1, 4.1, 5.1, 6.1, 7.1, 8.1, 9.1, 10.1};

    typedef function<vector<int>(vector<int>)> func;

    print("sdfasdf");
    print("a = ", array_2[10] );
    auto int_add4 = curry(add3)(1)(3);
    auto double_add4 = [&](auto x) {return x + 4;};
    double sum = 0;
    for (auto i : map(double_add4, array_2))
    {
        sum += i;
        print("i = ", i);
        print("没有你我怎么活着啊，燕子！");
    }
    print("sum = ")
    // vector<func> working_list = {
        // curry(filter)(is_even),
        // curry(map)([&](int x){return x * 20;})
    // };
    // auto map_add2 = [&](auto x){return map(add2, array);};

    // for (int i : curry(map_add2)(array))
        // cout << "i = " << i << endl;
    // return 0;
}

# include <iostream>
# include <vector>
# include <functional>
// # include "functional.h"

using namespace std;

void print() {
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

template <typename T>
T max(vector<T> lst) {
    return reduce([&](T a, T b) {return a > b;}, lst, lst[0]);
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

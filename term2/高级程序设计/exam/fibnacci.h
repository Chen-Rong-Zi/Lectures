#ifndef FIBNACCI_H_
#define FIBNACCI_H_
#include <cstdint>

// 你可以根据你的需要,添加fibnacci<n>的各种特化实现
template<size_t n>
struct fibnacci {
    static constexpr size_t value = fibnacci<n - 1>::value + fibnacci<n - 2>::value;
};

template <>
struct fibnacci<1> {
    static constexpr size_t value = 1;
};

template <>
struct fibnacci<0> {
    static constexpr size_t value = 0;
};

#endif

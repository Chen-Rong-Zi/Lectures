#ifndef FIBNACCI_H_
#define FIBNACCI_H_
#include <cstdint>

// 你可以根据你的需要,添加fibnacci<n>的各种特化实现
template<size_t n>
struct fibnacci {
    static constexpr size_t value = 0;
};

#endif

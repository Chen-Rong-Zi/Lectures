#include <memory>
#include <cstring>
#include <iostream>
#define DEBUG 0

// #include <self/functional.h>
// using namespace util;

using namespace std;
struct SliceOutOfBoundError {};

class Slice {
private:
    std::shared_ptr<int> buf;
    size_t base;
    size_t length;
    size_t capacity;

    static void free_buf(int *buf) {
        delete[] buf;
    }

    static std::shared_ptr<int> allocate_buf(size_t size) {
        return std::shared_ptr<int>(new int[size], free_buf);
    }

public:
    int cnt;
    Slice(Slice &other, int base, int len, int capacity) {
        DEBUG && cout << "slice(other, " << base << ", " << len << ", " << capacity << " )"  << endl;
        this->buf      = other.buf;
        this->base     = base;
        this->length   = len;
        this->capacity = capacity;
    }

    Slice(size_t size, int initial = 0) {
        DEBUG && cout << "Slice(" << size << ", " << initial << ")" << endl;
        if ( size > 0 )
            this->buf = Slice::allocate_buf(size * 2);
        else
            this->buf = nullptr;
        this->base     = 0;
        this->length   = size;
        this->capacity = size * 2;
        for ( int i = 0; i < this->length; i += 1 )
            this->buf.get()[i] = initial;
    }

    Slice(const Slice &other) {
        DEBUG && cout << "Slice(other)" << endl;
        // TODO
        // if ( other.buf == this->buf )
            // return;
        this->buf      = other.buf;
        this->base     = other.base;
        this->length   = other.length;
        this->capacity = other.capacity;
    }

    static Slice copy_from(const Slice &other) {
        DEBUG && cout << "copy_from" << endl;
        // TODO
        auto slice = Slice(other.length, 0);
        for ( int i = 0; i < slice.length; i += 1 )
            slice.buf.get()[i] = other.buf.get()[i];
        return slice;
    }

    void operator=(const Slice &other) {
        DEBUG && cout << "operator=" << endl;
        // TODO
        if ( this == &other )
            return;
        this->buf      = other.buf;
        this->base     = other.base;
        this->length   = other.length;
        this->capacity = other.capacity;
    }

    void append(int x) {
        DEBUG && cout << "append"  << " " << x << " " << endl;
        if ( this->base + this->length != this->capacity ) {
            this->buf.get()[this->length] = x;
            this->length += 1;
        } else {
            auto slice = Slice(this->length + 1, 0);
            for ( int i = 0; i < this->length; i += 1 )
                slice[i] = (*this)[i];
            slice[this->length] = x;
            *this = slice;
        }
    }

    Slice operator[](std::pair<size_t, size_t> range) {
        DEBUG && cout << "operator[" << range.first << ", " << range.second << "]" << endl;
        // if ( range.first > range.second ) {
        if ( range.first > range.second || range.second - range.first > this->capacity  ) {
            // cout << "ERROR! operator[" << range.first << ", " << range.second << "]" << endl;
            throw SliceOutOfBoundError();
        }
        /*  这里不应该禁止访问超出数组长度但不超出容量的部分 */
        // else if ( range.second - range.first > this->length ) {
            // auto new_slice = Slice(range.second - range.first);
            // for ( int i = 0; i < this->length; i += 1 )
                // new_slice[i] = (*this)[i];
            // return new_slice;
        // }

        return Slice(*this, this->base + range.first, range.second - range.first, this->capacity - range.first);
    }

    int& operator[](size_t pos) {
        DEBUG && cout << "operator[" << pos << "]" << endl;
        DEBUG && cout << this->base + pos << endl;
        if ( pos >= this->capacity || pos < 0  ) {
            throw SliceOutOfBoundError();
        }
        return this->buf.get()[this->base + pos];
    }

    void print() {
        DEBUG && cout << "print" << "s" << this->cnt << endl;
        for (int i = 0; i < this->length; ++i) {
            std::cout << buf.get()[base + i] << ' ';
        }
        std::cout << '\n';
    }

    size_t len() {
        DEBUG && cout << "len" << endl;
        return length;
    }

    size_t cap() {
        DEBUG && cout << "capacity" << endl;
        return capacity;
    }
};

// int main(const int arg_number, const char **arg_value) {
    // auto s1 = Slice(10, 0);
    // auto s2 = s1[{0, s1.cap()}];
    // cout << s2.len() << endl;
    // cout << s2.cap() << endl;
    // return 0;
// }

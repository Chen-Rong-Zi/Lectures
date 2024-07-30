#include <memory>
#include <cstring>
#include <iostream>

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
    Slice(size_t size, int initial = 0) {
        // TODO
    }

    Slice(const Slice &other) {
        // TODO
    }

    static Slice copy_from(const Slice &other) {
        // TODO
    }

    void operator=(const Slice &other) {
        // TODO
    }

    void append(int x) {
        // TODO 
    }

    Slice operator[](std::pair<size_t, size_t> range) {
        // TODO
    }

    int& operator[](size_t pos) {
        // TODO
    }

    void print() {
        for (int i = 0; i < length; ++i) {
            std::cout << buf.get()[base + i] << ' ';
        }
        std::cout << '\n';
    }

    size_t len() {
        return length;
    }

    size_t cap() {
        return capacity;
    }
};

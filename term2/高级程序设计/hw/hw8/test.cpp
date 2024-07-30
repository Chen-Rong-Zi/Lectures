# include <cstdlib>
# include <cstdio>
# include <self/functional.h>

using namespace util;

class MyArray {
public:
    int *psize;
public:
    MyArray(int size):
    psize(&size)
    {};

    MyArray(int *ps):
    psize(ps)
    {};

    void *operator new(size_t size) {
        return malloc(size);
    }

    void operator delete(void* p) {
        print("delete P");
        delete ((MyArray *)p)->psize;
    }
};

int main(int arg_number, char **arg_value) {
    int a = 20;
    int *psize = new int(0);
    MyArray *pa = new MyArray(psize);
    // printf("pa->size = %d\n", pa->size);
    delete pa;
    return 0;
}

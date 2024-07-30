# include <iostream>
# include <functional>
# include <self/functional.h>

using namespace std;
using namespace util;

class A{
    int n, m;
    public:
    A():n(0), m(0) {
        print("call A()");
        print("return A()");
    }
    A(int n, int m):n(n), m(m) {
        print("call A(int, int)");
        print("return A(int, int)");
    }
    A(const A&a):n(a.n), m(a.m) {
        print("call A(A &)");
        print("return A(A &)");
    }
    ~A() {
        print("call ~A()");
        print("return ~A()");
    }
};

class B: public A{
    int x;
    public:
    B():x(0) {
        print("call B()");
        print("return B()");
    }
    B(int x):x(x) {
        print("call B(int)");
        print("return B(int)");
    }
    B(const B&b) {
        print("call B(const B &)");
        print("return B(const B &)");
    }
    ~B() {
        print("call ~B()");
        print("return ~B()");
    }
};

class C{
    public:
        C() {
        print("call C()");
        print("return C()");
    }
        ~C() {
        print("call ~C()");
        print("return ~C()");
    }
};

class D: public C{
    B b;
    public:
    D() {
        print("call D()");
        print("return D()");
    }
    ~D() {
        print("call ~D()");
        print("return ~D()");
    }
};

int main() {
    D d1;
    {
        print();
        D d2(d1);
        print();
    }
    print();
}


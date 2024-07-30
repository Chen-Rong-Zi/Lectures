# include <self/functional.h>
using namespace util;

class A {
public:
    void f() {
        print("i am A");
    }
    ~A() {
        print("kill A");
    }
};

class B : public A {
public:
    ~B() {
        print("kill B");
    }
};

class C : public A {
public:
    void f() {
        print("i am C");
    }
    ~C() {
        print("kill C");
    }
};


class D : public B, public C {
public:
    void f() {
        print("i am D");
    }
    ~D() {
        print("kill D");
    }
};

void print(A &a) {
    a.f();
}

int main(int arg_number, char **arg_value) {
    D *d = new D;
    d->f();
    delete d;
    return 0;
}

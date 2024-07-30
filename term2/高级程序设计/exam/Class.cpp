#include "Class.h"

void Class::add_function(const Function &f) {
    this->funcs.insert(this->funcs.begin(), f);
    HACK && cout << this->name  << " 增加了一个函数 " << f.name << "(" << f.arg.name << ")" << endl;
}

void Class::inherit(const Class &c) {
    this->funcs = c.funcs;
    this->parent = &c;
    HACK && cout << this->name << "继承了" << c.name << endl;
}

bool arg_equal(Class argument, Class param) {
    return argument == param || argument.is_ancestor(param) ;
}


int count_deep(const Class &argument, const Class &param, int so_far) {
    if ( argument == param ) {
        return so_far;
    }
    else if ( argument.parent == nullptr)
        return 1000;
    return count_deep(*(argument.parent), param, so_far + 1);
}

bool call(CallSite cs) {
    HACK && cout << "调用了"<< cs.base.name << "的" << cs.function_name << "(" << cs.arg.name << ")" << endl;
    bool get_called = false;
    int closest_func_index = -1, closest_func_deep = 1000, func_index = 0;
    for ( const auto &it : cs.base.funcs )
    {
        int deep = count_deep(cs.arg, it.arg, 0);
        // cout << "deep = " << deep << endl;
        if ( deep < closest_func_deep ) {
            // cout << closest_func_index << endl;
            closest_func_index = func_index;
            closest_func_deep  = deep;
        }
        func_index += 1;
    }
    // cout << "closest_func_index = " << closest_func_index << endl;
    if ( closest_func_index >= 0 ) {
        cout << cs.base.name << "::" << cs.function_name << "(" << cs.base.funcs[closest_func_index].arg.name << ")" << endl;
        get_called = true;
    }
    if ( get_called )
        return true;

    if ( cs.base.parent == nullptr ) {
        std::cout << "Funcion not found." << std::endl;
        return false;
    }
    else {
        CallSite new_cs = {*(cs.base.parent), cs.function_name, cs.arg};
        return call(new_cs);
    }
    // std::cout << "有未想到的情况" << std::endl;
    return false;
}

bool Class::is_ancestor(const Class &c) const {
    if ( this->parent == nullptr )
        return false;
    else if ( *(this->parent) == c )
        return true;
    else
        return this->parent->is_ancestor(c);
}

class A {
public:
    A(){};
    void func(A);
};

class B : public A {
public:
    B(){};
    void func(B);
};

class C : public B {
public:
    C(){};
    void func(C);
};

class D : public C {
public:
    D(){};
    void func(D);
};

class E : public C {
public:
    E(){};
    void func(E);
};

class F : public D {
public:
    F(){};
    void func(F);
};

class X : public C {
public:
    X(){};
    void func(A a) {
        cout << "Function not found." << endl;
    }
    void func(E e) {
        cout << "X::func(E)" << endl;
    }
    void func(B b) {
        cout << "X::func(B)" << endl;
    }
    void func(C c) {
        cout << "X::func(C)" << endl;
    }
};

int main(int arg_number, char **arg_value) {
    // A a;
    // B b;
    // C c;
    // D d;
    // E e;
    // F f;
    // X x;
    // x.func(a);
    // x.func(b);
    // x.func(c);
    // x.func(d);
    // x.func(e);
    // x.func(f);
    Class A("A");
    Class B("B");
    Class C("C");
    B.inherit(A);
    C.inherit(B);

    Class D("D");
    D.inherit(C);
    Class E("E");
    E.inherit(C);
    Class F("F");
    F.inherit(D);

    Class X("X");
    X.add_function({"func", A});
    X.add_function({"func", C});

    Class Y("Y");
    Y.inherit(X);
    Y.add_function({"funcc", B});
    call({Y, "func", A});
    call({Y, "func", B});
    call({Y, "func", C});
}

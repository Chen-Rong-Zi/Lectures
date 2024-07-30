#ifndef OBJECT_H
#define OBJECT_H
# include <vector>
# include <string>
# include <map>
# include <utility>

# include "class.h"
using namespace std;




bool get_helper(vector<Class *> parent, string name, Class *qualified_class, int *result) {
    bool res = false;
    for ( auto &it : parent )
    {
        if ( it->variable.find(name) != it->variable.end() ) {
            *result = it->variable[name];
            return true;
        }
        res = res || get_helper(it->parent, name, qualified_class, result);
    }
    return res;
}

bool set_helper(vector<Class *> parent, string name, Class *qualified_class, int value) {
    bool res = false;
    for ( auto &it : parent )
    {
        if ( it->variable.find(name) != it->variable.end() ) {
            it->variable[name] = value;
            return true;
        }
        res = res || set_helper(it->parent, name, qualified_class, value);
    }
    return res;
}





// 你可以根据你的需要增加任何标准库头文件

// 你可以根据你的需要定义各种辅助类和函数

// 对C++中对象的抽象
// 假定所有创建的对象都在类定义的外部
// 你的目标是在object.cpp文件中实现题目要求的函数的所有功能
// 你可以根据你的需要增加任何成员变量和成员函数
class Object {
public:
    /**
     * 构造函数
     * 测试样例会使用这个函数构造Object对象
     * @param construct_class 构造这个对象的类(测试样例保证调用这个函数之后不会再修改construct_class指针指向的Class对象的内容)
    */
    vector<Class *> parent;
    vector<Class *> virtual_parent;
    map<string, int> variable;

    explicit Object(Class *construct_class) {
        this->parent         = construct_class->parent;
        this->virtual_parent = construct_class->virtual_parent;
        this->variable       = construct_class->variable;
    }

    /**
     * 根据传入的成员变量名称，以及名称前面的类限定符，获取这个成员变量的值。
     * @param name 成员变量名称
     * @param qualified_class
     *        表示成员变量名称前面的作用域类限定符
     *        举例:
     *        class X {public: int a; };
     *        class Y: public X {public: int b; };
     *        class Z: public Y {public: int c; };
     *        
     *        int main() {
     *            Z foo;
     *            cout << foo.c << '\n'; // 没有作用域限定符
     *            cout << foo.Y::b << '\n'; // 前面的Y::是作用域类限定符
     *            cout << foo.X::a << '\n'; // 前面的X::是作用域类限定符
     *        }
     *        如果没有限定类,则为nullptr
     *        如果你不清楚作用域限定符,请回顾理论课中继承与多继承的相关课件,也可查阅C++ scope相关文档
     * @param result 如果访问是合法的,你应该把对应成员变量的值传入这个指针中,如果不合法,则指针指向的内容未定义
     * @return 表示这次访问是否合法
    */
    bool get_member_variable(const char* name, Class* qualified_class, int* result) {
        auto it = this->variable.find(string(name));
        if ( it == this->variable.end() ) {
            return get_helper(this->parent, string(name), qualified_class, result);
        } else {
            *result = this->variable[string(name)];
            return true;
        }
    }

    /**
     * 根据传入的成员变量名称，以及名称前面的类限定符，修改这个成员变量的值。
     * @param name 成员变量名称
     * @param qualified_class
     *        表示成员变量名称前面的作用域类限定符
     *        举例:
     *        class X {public: int a; };
     *        class Y: public X {public: int b; };
     *        class Z: public Y {public: int c; };
     *        
     *        int main() {
     *            Z foo;
     *            foo.c = 3; // 没有作用域限定符
     *            foo.Y::b = 1; // 前面的Y::是作用域类限定符
     *            foo.X::a = 2; // 前面的X::是作用域类限定符
     *        }
     *        如果没有限定类,则为nullptr
     *        如果你不清楚作用域限定符,请回顾理论课中继承与多继承的相关课件,也可查阅C++ scope相关文档
     * @param value 如果访问是合法的,那么将对应成员变量的值修改为这个参数的值,否则没有任何成员变量会被修改
     * @return 表示这次访问是否合法
    */
    bool set_member_variable(const char* name, Class *qualified_class, int value) {
        auto it = this->variable.find(string(name));
        if ( it == this->variable.end() ) {
            return set_helper(this->parent, string(name), qualified_class, value);
        } else {
            this->variable[string(name)] = value;
            return true;
        }
    }

    DISALLOW_COPY_AND_ASSIGN(Object)
};

#endif // OBJECT_H


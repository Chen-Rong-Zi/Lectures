# include <vector>
# include <string>
# include <map>
# include <utility>

using namespace std;

#ifndef CLASS_H
#define CLASS_H
// 你可以根据你的需要增加任何标准库头文件

// 这个宏用于禁止Class对象和Object对象的复制和赋值操作
// 所以在题目中,两个地址不同的Class对象对应于C++中不同的类
// 两个地址不同的Object对象对应于不同的C++对象
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
TypeName(TypeName&) = delete;              \
void operator=(TypeName) = delete;

// 你可以根据你的需要定义各种辅助类和函数

// 对C++类的抽象,模拟C++的继承与成员变量访问机制
// 假定所有创建的类都只有默认的无参构造函数
// 假定类中只有成员变量，所有成员变量都是int类型，初始化的默认值均为0，不考虑成员函数。
// 假定所有创建的类的成员变量都是public访问权限,不考虑静态成员
// 你的目标是在class.cpp文件中实现题目要求的函数的所有功能
// 你可以根据你的需要增加任何成员变量和成员函数
class Class {
public:
    /**
     * 声明无参构造函数(因为禁用了复制操作所以隐式的无参构造函数失效了)
     * 测试样例会使用无参构造函数构造Class对象
     * 你可以添加你自己想要的初始化操作,但是不能修改本函数签名
    */
    Class() {};

    vector<Class *> parent;
    vector<Class *> virtual_parent;
    map<string, int> variable;
    /**
     * 增加一个当前类继承的基类.(假定所有的继承都是public继承)
     * @param parent 指向继承来源的Class的指针
     *               测试样例保证:
     *               1. 不会重复添加相同的基类
     *               2. 调用这个函数之后不会再修改parent指针指向的Class对象的内容
     *               3. 不会存在循环继承关系
     * @param is_virtual 当前继承是否是虚继承
    */
    void add_inherit_class(Class *parent, bool is_virtual) {
        if ( is_virtual )
            this->virtual_parent.push_back(parent);
        else {
            this->parent.push_back(parent);
        }
    }

    /**
     * 增加一个成员变量.(简单起见,假定所有成员变量的类型均为int,所有成员变量默认的初始化值为0)
     * @param name 成员变量的变量名(测试样例保证传入的字符串非空,并且单个Class内部定义的所有成员变量名字不重复)
    */
    void add_member_variable(const char* name) {
        this->variable.insert(make_pair(string(name), 0));
    }

    DISALLOW_COPY_AND_ASSIGN(Class)
};

#endif // CLASS_H

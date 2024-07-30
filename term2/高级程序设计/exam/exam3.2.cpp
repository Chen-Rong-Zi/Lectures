# include <iostream>

// MyStack.cpp
#include "MyStack.h"

using namespace std;

// 构造函数
MyStack::MyStack() {
    top=NULL;
    sz=0;
}

// 析构函数
MyStack::~MyStack()
{
    while (top != NULL)
    {
        Node *p = top;
        top = top->next;
        delete p;
    }
}

// 以下是需要补充的成员函数
// 字符c入栈
void MyStack::push(char c)
{
    if ( this->top == NULL ) {
        top          = new Node;
        top->next    = NULL;
        top->content = c;
    }
    else {
        Node *new_node = new Node;
        new_node->content = c;
        new_node->next = this->top;
        this->top      = new_node;
    }
    this->sz += 1;
}

// 栈顶元素出栈，返回出栈元素（我们没有定义空栈pop操作，测试用例中不会涉及）
char MyStack::pop()
{
    char result = 0;
    Node *old_top = this->top;
    result    = this->top->content;
    this->top = this->top->next;
    this->sz -= 1;
    delete old_top;
    return result;
}

// 返回栈的大小（栈内元素数量）
int MyStack::size()
{
    int  result = 0;
    Node *temp  = this->top;
    while ( temp != NULL ) {
        result += 1;
        temp = temp->next;
    }
    return result;
}

int main() {
    MyStack s;
    s.push('N');
    s.push('J');
    s.push('U');
    cout << s.size() << endl; // 3
    cout << s.pop()  << endl; // U
    cout << s.pop()  << endl; // J
    cout << s.pop()  << endl; // N
    cout << s.size() << endl; // 0
    return 0;
}

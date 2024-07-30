// MyQueue.cpp
#include "MyQueue.h"

// 构造函数
MyQueue::MyQueue() {
}

void MyQueue::push(char c) {
    s1.push(c);
}

char MyQueue::pop() {
    if (s2.size() == 0) {
        while (s1.size() != 0) {
            s2.push(s1.pop());
        }
    }
    return s2.pop();
}

int MyQueue::size() {
    return s1.size() + s2.size();
}


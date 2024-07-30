#pragma once
#include<iostream>
using namespace std;

class String
{
private:
	int len;
	char *str_p;

public:
    const char* getStr_p() const { return str_p; };
	String();
	String(const char *s);
	String(const String &s);

    void last_word();
	~String();

	void print();  //输出字符串，最后输出换行符\n

    //重载操作符=，[]
	String& operator=(const String &s);
	String& operator=(const char *s);
	char & operator[](int index); //暂不考虑越界情况，但需清楚该操作可能会导致越界

    //+  返回一个新建字符串，内容为参数字符串拼接，左目在前右目在后。
	String operator + (const String &A);
	//==,!=,<  返回值为bool类型，按照字典序比较
    bool operator == (const String &A);
    bool operator != (const String &A);
    bool operator < (const String &A);
};

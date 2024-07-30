// String.cpp
#include "String.h"

using namespace std;

int strlen(const char s[]) {
    if ( s[0] == '\0' ) {
        return 0;
    }
    return 1 + strlen(s + 1);
}

int strcmp(const char a[], const char b[]) {
    if ( a[0] == '\0' && b[0] == '\0' )
        return 0;
    if ( b[0] == '\0' )
        return 1;
    if ( a[0] == '\0' )
        return -1;
    if ( a[0] < b[0] )
        return -1;
    if ( a[0] > b[0] )
        return 1;
    return strcmp(a + 1, b + 1);
}

void strcopy(char *a, const char *b) {
    if ( *b == '\0' ) {
        *a = *b;
        return;
    }
    *a = *b;
    return strcopy(a + 1, b + 1);
}

void String::last_word() {
    if ( this->str_p != nullptr && this->len != -1 ) {
        this->len = -1;
        delete[] this->str_p;
        this->str_p = nullptr;
    }
}

String::String():
    len(0),
    str_p(new char[1]) {
        this->str_p[0] = '\0';
    };

String::String(const char *s) {
    this->len   = strlen(s);
    this->str_p = new char[this->len + 1];
    strcopy(this->str_p, s);
}

String::String(const String &s) {
    this->len   = s.len;
    this->str_p = new char[this->len + 1];
    strcopy(this->str_p, s.getStr_p());
}

String::~String() {
    this->last_word();
}

void String::print() {
    for ( int i = 0; i < this->len; i += 1 )
    {
        cout << (this->str_p)[i];
    }
    cout << endl;
}

String& String::operator=(const String &s) {
    if ( this->getStr_p() == s.getStr_p() ) {
        return *this;
    }
    this->last_word();
    this->len   = s.len;
    this->str_p = new char[this->len + 1];
    strcopy(this->str_p, s.getStr_p());
    return *this;
}

String &String::operator=(const char *s) {
    this->last_word();
    this->len   = strlen(s);
    this->str_p = new char[this->len + 1];
    strcopy(this->str_p, s);
    return *this;
}

char &String::operator[](const int index) {
    return (this->str_p)[index];
}

String String::operator+(const String &A) {
    char addup[this->len + A.len + 1];
    strcopy(addup, this->getStr_p());
    strcopy(addup + this->len, A.getStr_p());
    addup[this->len + A.len] = '\0';
    return String(addup);
}

bool String::operator==(const String &A) {
    return strcmp(this->str_p, A.getStr_p()) == 0;
}


bool String::operator!=(const String &A) {
    return strcmp(this->str_p, A.getStr_p()) != 0;
}

bool String::operator<(const String &A) {
    return strcmp(this->str_p, A.getStr_p()) < 0;
}


int main(const int arg_number, const char **arg_value) {
    cout << "arg_number = " << arg_number << endl;
    cout << "arg_value[0] = " << arg_value[0] << endl;
    String s0; //构造函数
    s0.print();
    //输出：
    s0="abc";
    s0.print();
    //输出：abc
    String s1(s0);  //构造函数
    s1.print();
    //输出：abc
    s1.~String(); //析构函数，s1的析构不会影响s0
    s0.print();
    //输出：abc
    String s2("d");  //构造函数
    s2.print();
    //输出：d
    String s3 = s2;  //重载 =
    s2.~String();  //析构函数，s2的析构不会影响s3
    s3.print();
    //输出：d
    String s4 = s3 + s3 + s3;  //重载 +，加法会考察连续+，且加法不会影响加数
    s4.print();
    //输出：ddd
    cout << s4[2] << endl;  //重载 []
    //输出：d
    cout << (s4 == s3) << endl;  //重载 ==
    //输出0
    cout << (s4 != s3) << endl;  //重载 !=
    //输出1
    cout << (s4 < s3) << endl;  //重载 <
    //输出0
}

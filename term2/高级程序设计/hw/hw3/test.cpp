#include <iostream>
#include <cstring>
using namespace std;

class Book{
    static int BookCnt;
    char *name;

public:
    Book(const char *_name);
    Book(const Book &book);
    ~Book();
    char *get_name() const;
    void set_name(const char *_name);
};

Book::Book(const Book &other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    Book::BookCnt += 1;
}

int Book::BookCnt = 0;

Book::Book(const char *_name){
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
    Book::BookCnt += 1;
}

Book::~Book(){
    delete []name;
    name = nullptr;
}

char* Book::get_name() const{
    return name;
}

void Book::set_name(const char *_name) {
    delete []name;
    name = new char[strlen(_name) + 1];
    strcpy(name, _name);
}

int main(){
    Book b1("Computer Science");
    Book b2(b1);
    return 0;
}


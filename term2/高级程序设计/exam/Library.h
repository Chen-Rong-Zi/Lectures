#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Library;

class Book {
private:
    string title;
    string author;
    int number_max;

public:
    Book(const string &t, const string &a,int num=1) : title(t), author(a), number_max(num) {};
    // 声明友元函数
    friend int borrowBook(Library &lib, const string &title);
    friend int returnBook(Library &lib, const string &title);
    friend class Library;

};
class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book &book);
    void printBooks();

    // 声明友元函数
    friend int borrowBook(Library &lib, const string &title);
    friend int returnBook(Library &lib, const string &title);
    friend class Book;
    friend vector<Book> &get_book(Library &);
};



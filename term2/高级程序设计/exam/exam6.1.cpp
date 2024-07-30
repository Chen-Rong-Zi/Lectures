#include "Library.h"


void Library::addBook(const Book &book) {
  //TODO
    for ( auto &i : this->books )
    {
        if ( i.title == book.title ) {
            i.number_max += 1;
            return;
        }
    }
    this->books.push_back(book);
}

void Library::printBooks() {
  //TODO
    using namespace std;
    for ( auto &i : this->books )
    {
        cout << i.title << '[' << i.author << ']'<< "Available" << endl;
    }
    return;
}


int borrowBook(Library &lib, const string &title) {
    for ( auto &i : lib.books )
    {
        if ( i.title == title ) {
            i.number_max -= 1;
            return i.number_max;
        }
    }
    return -1;
}


int returnBook(Library &lib, const string &title) {
    for ( auto &i : lib.books )
    {
        if ( i.title == title ) {
            i.number_max += 1;
            return i.number_max;
        }
    }
    return -1;
}

int main(int arg_number, char **arg_value) {
    Library library;
    library.addBook(Book("BOOK1", "Elf1", 2));
    cout<<borrowBook(library, "BOOK1")<<endl;
    cout<<borrowBook(library, "BOOK1")<<endl;
    library.printBooks();
    return 0;
}

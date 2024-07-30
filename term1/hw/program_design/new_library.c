# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <string.h>

typedef struct {
    char name[20];
    int status;             // must be initialized
}Book;

typedef struct {
    int id;
    int book_num;           // must be initialized
    char name[20];
    Book *(*books);       // dynamic array of names of books, must be initialized
}Student;

typedef struct {
    Book *list;
    int book_num;           // must be initialized
}BookList;

typedef struct {
    Student *list;
    int stu_num;            // must be initialized
}StudentList;

BookList book_list;
StudentList stu_list;
int stu_num = 0, book_num = 0, record_num = 0;

int compare_name(const void *a, const void *b) {
    return strcmp(((Student *)a)->name, ((Student *)b)->name);
}

int add_book(Student *pstu, Book *pbook) {
    if ( pbook->status == 0 )
        return -1;

    if ( pstu->book_num != 2 ) {
        pstu->books[pstu->book_num] = pbook;
        pstu->book_num += 1;
    }
    else{
        pstu->books[0]->status = 1;
        pstu->books[0] = pstu->books[1];
        pstu->books[1] = pbook;
    }
    pbook->status = 0;
    return 0;
}

int make_stu(char *name, int id) {
    Student stu = {};
    Book **books = (Book **) malloc(sizeof(Book *) * 2);
    stu.books = books;
    stu.id = id;
    stu.book_num = 0;
    strcpy(stu.name, name);
    stu_list.list[stu_list.stu_num] = stu;
    stu_list.stu_num += 1;
    return 0;
}

int make_book(char *name) {
    Book book = {};
    strcpy(book.name, name);
    book.status = 1;
    book_list.list[book_list.book_num] = book;
    book_list.book_num += 1;
    return 0;
}

int make_record(char people_name[], char book_name[]) {
    Student *pstu;
    Book   *pbook;
    for ( int i = 0; i < 10; ++i )
    {
        if ( strcmp(people_name, stu_list.list[i].name) == 0 ) {
            pstu = &(stu_list.list[i]);
            break;
        }
    }
    for ( int i = 0; i < 20; ++i )
    {
        if ( strcmp(book_name, book_list.list[i].name) == 0 ) {
            pbook = &(book_list.list[i]);
            break;
        }
    }
    add_book(pstu, pbook);
    return 0;
}

int takein() {
    scanf("%d %d", &stu_num, &book_num);
//     printf("\nstu_num = %d, book_num = %d\n", stu_num, book_num);

    // take in student and their id
    for ( int i = 0; i < stu_num; ++i )
    {
        char name[20] = {};
        int id = 0;
        scanf(" %s %d", name, &id);
        make_stu(name, id);
    }

    // take in book name
    for ( int i = 0; i < book_num; ++i )
    {
        char name[20] = {};
        scanf(" %s", name);
        make_book(name);
    }

    // take in record
    scanf(" %d", &record_num);
    for ( int i = 0; i < record_num; ++i )
    {
        char people_name[20] = {0}, book_name[20] = {0};
        scanf(" %s %s", people_name, book_name);
        make_record(people_name, book_name);
    }
    return 0;
}

int cmpstr(char *a, char *b) {
    int i = 0;
    for (  i = 0; a[i] != '\0' && b[i] != '\0'; ++i )
    {
//         printf("\n%s %s\n", a, b);
        if ( a[i] < b[i] )
            return 1;
        else if ( a[i] > b[i] )
            return 0;
    }
    return ( a[i] == '\0' )?1:0;
}

int sort_book(Book **book_list) {
    if ( book_list == NULL )
        return 1;
    for ( int i = 0; i < 2; ++i )
    {
        int min = i;
        for ( int j = i; j < 2; ++j )
        {
            if ( cmpstr((book_list[j])->name, (book_list[min])->name) )
                min = j;
        }
        Book *temp = NULL;
        temp = book_list[min];
        book_list[min] = book_list[i];
        book_list[i] = temp;
    }
    return 0;
}

int sort_stu(void) {
    for ( int i = 0; i < stu_list.stu_num; ++i )
    {
        int min = i;
        for ( int j = i; j < stu_list.stu_num; ++j )
        {
            if ( cmpstr(stu_list.list[j].name, stu_list.list[min].name) )
                min = j;
        }
        if ( min != i )
        {
            Student temp = stu_list.list[i];
            stu_list.list[i] = stu_list.list[min];
            stu_list.list[min] = temp;
       }
    }
    return 0;
}

int output(void) {
    sort_stu();
    for ( int i = 0; i < stu_num; ++i )
    {
        printf("%s %d", stu_list.list[i].name, stu_list.list[i].id);
        if ( stu_list.list[i].book_num == 2 )
            sort_book(stu_list.list[i].books);
        for ( int j = 0; j < stu_list.list[i].book_num; ++j )
        {
            printf(" %s", stu_list.list[i].books[j]->name);
        }
        if ( i != stu_num - 1 )
            printf("\n");
    }
    return 0;
}

int init(void) {
    book_list.list = (Book *) malloc(sizeof(Book ) * 20);
    stu_list.list  = (Student *) malloc(sizeof(Student ) * 20);
    book_list.book_num = 0;
    stu_list.stu_num  = 0;
    return 0;
}

int main(void) {
    init();
    takein();
    output();
    return 0;
}

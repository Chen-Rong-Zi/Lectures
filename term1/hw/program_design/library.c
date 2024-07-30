# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <stdio.h>

typedef struct{
    int hour;
    int minute;
    int second;
}Time;

typedef struct{
    char borrower[20];
    char bookname[20];
    Time borrow_time;
}Record;

typedef struct{
    int    id;
    char   name[20];
    int    record_amount;
    Record records[50];
}Student;

bool is_earlier(Time time1, Time time2) {
    if ( time1.hour < time2.hour )
        return true;
    else if ( time1.minute < time2.minute )
        return true;
    else if ( time1.second < time2.second )
        return true;
    return false;
}

int takein_people(Student people_list[], int people_amount) {
    Student people = {};
    for ( int i = 0; i < people_amount; ++i ) {
        scanf(" %s %d", people.name, &people.id);
        people.record_amount = 0;
        people_list[i]       = people;
    }
    return 0;
}

int find_people(Student people_list[], int people_amount, char name[]) {
    for ( int i = 0; i < people_amount; ++i ) {
        if ( strcmp(name, people_list[i].name) == 0 )
            return i;
    }
    return -1;
}

int takein_record(int record_amount, Student people_list[], int people_amount) {
    int people_index = 0;

    for ( int i = 0; i < record_amount; ++i ) {
        Record record = {};
        scanf(" %s %s %d:%d:%d", record.borrower, record.bookname, &record.borrow_time.hour, &record.borrow_time.minute, &record.borrow_time.second);
        people_index = find_people(people_list, people_amount, record.borrower);

        if (people_list[people_index].record_amount == 3 ) continue;

        people_list[people_index].records[people_list[people_index].record_amount] = record;
        people_list[people_index].record_amount += 1;
    }
    return 0;
}

int output(Student people_list[], int people_amount) {
    for ( int i = 0; i < people_amount; ++i ) {
        Student people = people_list[i];
        printf("%s %d ", people.name, people.id);
            for ( int j = 0; j < people.record_amount; ++j ) {
                Record record = people.records[j];
                printf("%s %.2d:%.2d:%.2d", record.bookname, record.borrow_time.hour, record.borrow_time.minute, record.borrow_time.second);
                if ( j != people.record_amount - 1 )
                    printf(" ");
            }
        if ( i != people_amount - 1 ) printf("\n");
    }
    return 0;
}

int compare_time(Time t1, Time t2) {
    if ( t1.hour < t2.hour )
        return -1;
    else if ( t1.minute < t2.minute )
        return -1;
    else if ( t1.second < t2.second )
        return -1;
    return 1;
}

int compare_record(const void *a, const void *b) {
    Record *precord1 = ((Record *)a);
    Record *precord2 = ((Record *)b);
    if ( strcmp(precord1->bookname, precord2->bookname) == 0 ) {
        return compare_time(precord1->borrow_time, precord2->borrow_time);
    }
    return strcmp(precord1->bookname, precord2->bookname);
}

int compare_name(const void *a, const void *b) {
    return strcmp(((Student *)a)->name, ((Student *)b)->name);
}

int main(void) {
    int people_amount = 0, record_amount = 0;
    Student people_list[10] = {};
    scanf(" %d", &people_amount);
    takein_people(people_list, people_amount);
    scanf(" %d", &record_amount);
    takein_record(record_amount, people_list, people_amount);
    qsort(people_list, people_amount, sizeof(people_list[0]), compare_name);
    for ( int i = 0; i < people_amount; ++i ) {
        qsort(people_list[i].records, people_list[i].record_amount, sizeof(people_list[i].records[0]), compare_record);
    }
    output(people_list, people_amount);
    return 0;
}

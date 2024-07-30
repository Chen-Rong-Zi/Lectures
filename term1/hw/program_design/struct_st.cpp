# include<iostream>
using namespace std;

enum Gender{
    MALE,
    FEMALE
};

struct Student{
    char name[100];
    long long id;
    enum Gender gender;
};

struct Student stu_array[200];

long long initialize(long long n){
    long long i = 0;
    for ( i = 0; i < n; ++i){
        struct Student stu;
        char male = '\0';
        cin >> stu.name >> stu.id >> male;
        stu.gender = ((male == 'f')? (FEMALE):(MALE));
        stu_array[i] = stu;
    }
    return (i == n - 1)? 0:-1;
}


int main(void){
    long long i = 0, n = 0, start = 0, end = 0;

    cin >> n;
    initialize(n);
    scanf(" %lld %lld", &start, &end);
    for ( i = 0; i < n; ++i){
        if ( stu_array[i].id >= start && stu_array[i].id <= end ){
            cout << "name: " << stu_array[i].name << ", id: " << stu_array[i].id << ", gender: ";
            (stu_array[i].gender == MALE)?(cout << "male"):(cout << "female");
            cout << '\n';
        }
    }
    return 0;
}

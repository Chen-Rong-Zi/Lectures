# include<stdio.h>
# include<malloc.h>


enum Gender{
    MALE,
    FEMALE
};

struct Student{
    long long id;
    enum Gender gender;
    char name[];
};

struct Student *(stu_array[200]);

long long initialize(long long n){
    long long i = 0;
    for ( i = 0; i < n; ++i ){
        struct Student *pstu;
        pstu = (struct Student ) malloc(sizeof(struct Student) + 4 * sizeof(int));
        char male = '\0';
        scanf(" %s %lld %c", pstu->name, &pstu->id, &male);
        pstu->gender = ((male == 'f')? (FEMALE):(MALE));
        stu_array[i] = pstu;
    }
    return (i == n - 1)? 0:-1;
}


int main(void){
    long long i = 0, n = 0, start = 0, end = 0;

    scanf(" %lld", &n);
    initialize(n);
    scanf(" %lld %lld", &start, &end);
    for ( i = 0; i < n; ++i ){
        if ( (stu_array[i])->id >= start && (stu_array[i])->id <= end ){
            printf("name: %s, id: %lld, gender: ", (stu_array[i])->name, (stu_array[i])->id);
            ((stu_array[i])->gender == MALE)?(printf("male")):(printf("female"));
            printf("\n");
        }
    }
    return 0;
}

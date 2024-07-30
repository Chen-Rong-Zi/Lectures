# include<stdio.h>
# include<stdlib.h>

typedef struct{
    int score;
    int class_id;
    int class_rank;
    int department_rank;
    long long id;
} Student;

int compare(const void *a, const void *b){
    return ((Student *)b) -> score - ((Student *)a)->score;
}

int compare_id(const void *a, const void *b){
    if ( ((Student *)a)->score == ((Student *)b)->score )
        return ((Student *)b)-> score - ((Student *)a)->score;
    return 0;
}

int rank_in_class(Student stu_list[], int lenth){
    qsort(stu_list, lenth, sizeof(Student), compare);

    // assgine rank the students by score
    for ( int i = 0, j = 1; i < lenth;  ++i ){
        if ( i == 0 ){
            stu_list[i].class_rank = 1;
        }
        else{
            ++j;
            stu_list[i].class_rank = (stu_list[i].score == stu_list[i-1].score)?stu_list[i-1].class_rank:j;
        }
    }
    return 0;
}

int rank_in_department(Student stu_list[], int lenth){
    qsort(stu_list, lenth, sizeof(Student), compare);

    // rank the students by score
    for ( int i = 0, j = 1; i < lenth;  ++i ){
        if ( i == 0 ){
            stu_list[i].department_rank = 1;
        }
        else{
            ++j;
            stu_list[i].department_rank = (stu_list[i].score == stu_list[i-1].score)? stu_list[i-1].department_rank:j;
        }
    }
    qsort(stu_list, lenth, sizeof(Student), compare_id);
    return 0;
}

Student make_stu(int classid){
    Student stu = {};
    scanf(" %lld %d", &stu.id, &stu.score);
    stu.class_id = classid;
    return stu;
}

int output(Student stu_list[], int lenth){
    printf("%d\n", lenth);
    for ( int i = 0; i < lenth; ++i ){
        printf("%lld %d %d %d", stu_list[i].id, stu_list[i].department_rank, stu_list[i].class_id, stu_list[i].class_rank);
        if ( i != lenth - 1 ){
            printf("\n");
        }
    }
    return 0;
}

int main(void){
    int class_total = 0, stu_total_for_each_class = 0, stu_total = 0, i = 0, j = 0;
    Student department_rank_list[3000] = {};

    scanf("%d", &class_total);
    for ( j = 0; j < class_total; ++j ){
        Student class_rank_list[300] = {};
        scanf(" %d", &stu_total_for_each_class);

        for ( i = 0; i < stu_total_for_each_class; ++i ){
            class_rank_list[i] = make_stu(j + 1);
        }
        rank_in_class(class_rank_list, stu_total_for_each_class);

        for ( i = 0 ; i < stu_total_for_each_class; ++i ){
            // add stus to department_rank_list
            department_rank_list[stu_total + i] = class_rank_list[i];
        }
        stu_total += stu_total_for_each_class;
    }
    rank_in_department(department_rank_list, stu_total);
    output(department_rank_list, stu_total);
    return 0;
}

# include <cstdio>
# include <cstring>
#include <assert.h>
#include <iostream>
using namespace std;

// 定义一个结构体表示课程
struct Course {
    char *name;                  // malloc!
    struct Student *students; // (an array to restore all struct student rather than the pointer to struct)
	double average;
	int numStudents;
};

// 定义一个结构体表示学生
struct Student {
    char *name;                // malloc!
	double grade;
    struct Course *course;  // (a poiter to students' course)
};


int compare_course_name(const void *a, const void *b){
    return strcmp(((struct Course *)a)->name, ((struct Course *) b)->name);
}

int compare_student_name(const void *a, const void *b){
    return strcmp(((const struct Student *)a)->name, ((const struct Student *)b)->name);
}

int update_stu(struct Course *cour_list, int index_a, int index_b){
    for ( int stu_num = 0; stu_num < cour_list[index_b].numStudents; ++stu_num )
    {
        cour_list[index_b].students[stu_num].course = &(cour_list[index_a]);
    }
    for ( int stu_num = 0; stu_num < cour_list[index_a].numStudents; ++stu_num )
    {
        cour_list[index_a].students[stu_num].course = &(cour_list[index_b]);
    }
    return 0;
}

int bubble_sort(struct Course *cour_list, int cour_num){
    for ( int left = 0; left < cour_num; ++left )
    {
        int min = left;
        for ( int index = left; index < cour_num; ++index )
        {
            if ( compare_course_name(&cour_list[index], &cour_list[min]) < 0 ){
                min = index;
            }
        }
        update_stu(cour_list, left, min);
        struct Course temp = cour_list[left];
        cour_list[left] = cour_list[min];
        cour_list[min] = temp;
    }
    return 0;
}
int takein(struct Course *cour_list, int m, int n) {
    for ( int i = 0; i < m; ++i )
    {
        /*  init every course  */
        cour_list[i].students = (struct Student *) malloc(sizeof(struct Student ) * n);
        cour_list[i].name = (char *) malloc(sizeof(char) * 20);
        cour_list[i].numStudents = 0;
        scanf(" %s ", cour_list[i].name);
    }
    for ( int i = 0; i < n; ++i )
    {
        char course[20] = {};
        struct Student stu = {};
        stu.name = (char *) malloc(sizeof(char) * 20);
        scanf(" %s %s %lf", stu.name, &course, &stu.grade);
        for ( int l = 0; l < m; ++l )
        {
            if ( strcmp(course, cour_list[l].name) == 0 )
            {
                stu.course = &cour_list[l];
                cour_list[l].students[cour_list[l].numStudents] = stu;
                cour_list[l].numStudents += 1;
                break;
            }
        }
    }
    return 0;
}

int get_average(struct Course *cour_list, int cour_num){
    for ( int i = 0; i < cour_num; ++i )                      // for every course
    {
        double sum = 0;
        for ( int j = 0; j < cour_list[i].numStudents; ++j ) // for every student
        {
            sum += cour_list[i].students[j].grade;
        }
        cour_list[i].average = sum / (cour_list[i].numStudents * 1.0);
    }
    return 0;
}

struct Course *get_courses(int m, int n){
	// write your code here......
    // m for the number of the courses m <= 5
    // n for the number of the student n <= 20
    struct Course *cour_list = (struct Course *) malloc(sizeof(struct Course) * 5);
    takein(cour_list, m, n);
    bubble_sort(cour_list, m);
    for ( int i = 0; i < m; ++i )
    {
        qsort(cour_list[i].students, cour_list[i].numStudents, sizeof(struct Student), compare_student_name);
    }
    get_average(cour_list, m);
    return cour_list;
}

// int main(){
//     int m, n;
//     cin >> m >> n;
//     Course *courses = get_courses(m, n);
//     cout << endl;
//     for(int i = 0; i < m; i++){
//         cout << courses[i].name << ", ";
//         cout << courses[i].average << ", ";
//         cout << courses[i].numStudents << ", ";
//         for(int j = 0; j < courses[i].numStudents; j++){
//             cout << endl;
//             cout << courses[i].students[j].name;
//             if(j != courses[i].numStudents - 1){
//                 cout << ' ';
//             }
// //             assert(courses[i].students[j].course == courses + i);
//             cout << "\n" << courses[i].students[j].name << " is learning " << courses[i].students[j].course->name << ", " << courses[i].name << "\n";
//             printf("assert(courses[i].students[j].course = %p, courses + %d = %p\n", (courses[i].students[j].course), i, courses+i);
//         }
//         cout << endl;
//     }
// }

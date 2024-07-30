# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <assert.h>

typedef struct Node{
    void *content;        // a general pointer pointing to the element
    struct Node *next;
}Node;

typedef struct Course{
    char name[20];
    int credit;           // 每门课的学分
    double sum;              // total grade
    int stu_num;          // how many students are
    struct Student *stu_list[20]; // an array of pointers pointing to student
}Course;


typedef struct Grade{
    struct Course *course;    // an pointer pointing to course
    double grade;
}Grade;

typedef struct Student{
    char name[20];
    double gpa;
    int course_num;       // how many courses are
    Grade grade_list[20]; // an array of pointers pointing to struct Grades
}Student;

/* global vairable */
Node *cour_head = NULL;
Node *stu_head = NULL;

Node *make_node(void *pointer) {
    Node *pnode = (Node *) malloc(sizeof(Node));
    pnode->content = pointer;        // any type is fine, because content is a general pointer
    pnode->next = NULL;
    return pnode;
}

int compare_course_name(const void *a, const void *b) {
    Course *px = (Course *) a;
    Course *py = (Course *) b;
    return strcmp(px->name, py->name);
}

int compare_stu_name(const void *a, const void *b) {
    Student *px = (Student *) a;
    Student *py = (Student *) b;
    return strcmp(px->name, py->name);
}

int append(Node **phead, Node *pnew_node, int (*compare)(const void *a, const void *b)) {
    for ( ; (*phead) != NULL; phead = &((*phead)->next) )
    {
        if ( compare((*phead)->content, pnew_node->content) > 0 ){
            pnew_node->next = (*phead);
            *phead = pnew_node;
            return 0;
        }
    }

    pnew_node->next = (*phead);
    *phead = pnew_node;
    return 0;
}

Course *find_course(char *name) {
    Node *pnode = cour_head;
//     printf("cour_head = %s\n", ((Course *)(cour_head->content))->name);
    for ( ; (pnode != NULL) && strcmp(((Course *)pnode->content)->name, name) != 0; pnode = pnode->next );
    assert(pnode != NULL);
    return (Course *)(pnode->content);
}


double average_grade(Course *pcourse) {
    return pcourse->sum / pcourse->stu_num;
}

int takein(void) {
    int cour_num = 0, stu_num = 0;

    scanf(" %d", &cour_num);
    for ( int i = 0; i < cour_num; ++i ){
        Course *pcourse = (Course *) malloc(sizeof(Course));
        scanf(" %s %d", pcourse->name, &pcourse->credit);
        Node *pnode = make_node(pcourse);
        pcourse->sum = 0;
        pcourse->stu_num = 0;
        append(&cour_head, pnode, compare_course_name);
    }

    scanf(" %d", &stu_num);
    for ( int i = 0; i < stu_num; ++i )
    {
        Student *pstu = (Student *) malloc(sizeof(Student));
        Node *pnode = make_node(pstu);

        scanf(" %s %d", pstu->name, &pstu->course_num);
        append(&stu_head, pnode, compare_stu_name);

        for ( int j = 0; j < pstu->course_num; ++j )
        {
            char cour_name[20] = {};
            double grade = 0;
            scanf(" %s %lf", cour_name, &grade);

            // find the course that has a name "cour_name", and assign a pointer pointing to that course to the student's grade_list's course
            Course *pcourse = find_course(cour_name);
            pcourse->stu_list[pcourse->stu_num] = pstu;
            pcourse->stu_num += 1;
            pcourse->sum += grade;
            Grade stu_grade = {pcourse, grade};
            pstu->grade_list[j] = stu_grade;
        }
    }
    return 0;
}

double gpa(Student *pstu) {
    Grade grade = {};
    int i = 0;
    double sum = 0, result = 0, credit_sum = 0;
    for ( grade = pstu->grade_list[0]; i < pstu->course_num; ++i, (grade = pstu->grade_list[i]) )
    {
//         printf("%s : %lf, credit = %d\n", grade.course->name, grade.grade, grade.course->credit);
//         printf("grade = %p\n", &grade);
        sum += grade.grade * grade.course->credit;
        credit_sum += grade.course->credit;
    }
    result = sum / (credit_sum * 20);
    pstu->gpa = result;
    return result;
}

int output(void) {
    Node *walk = cour_head;
    for ( ; walk != NULL; walk = walk->next )
    {
        Course *pcour = (Course *)(walk->content);
        printf("%s %.2lf\n", pcour->name, average_grade(pcour));
    }

    for ( walk = stu_head; walk != NULL; walk = walk->next )
    {
        Student *pstu = (Student *)(walk->content);
        printf("%s %.2lf", pstu->name, gpa(pstu));
        if ( walk->next != NULL )
            printf("\n");
    }
    return 0;
}

int main(void) {
    takein();
    output();
    return 0;
}

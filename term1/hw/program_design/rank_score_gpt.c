#include <stdio.h>
#include <stdlib.h>

// 定义学生信息的结构体
typedef struct{
    long long studentID;
    int score;
    int classID;
    int classRank;
} Student;

// 比较函数用于排序
int compare(const void *a, const void *b) {
    // 首先按照分数降序排列
    if (((Student *)b)->score != ((Student *)a)->score) {
        return ((Student *)b)->score - ((Student *)a)->score;
    } else {
        // 如果分数相同，按照学号升序排列
        return ((Student *)a)->studentID - ((Student *)b)->studentID;
    }
}

int main() {
    int N; // 班级数
    scanf("%d", &N);

    int totalStudents = 0; // 总学生数
    Student students[300]; // 假设一个班最多有300个学生

    // 读取每个班级的排名表
    for (int i = 0; i < N; ++i) {
        int K; // 班级学生数
        scanf("%d", &K);

        // 读取班级每个学生的信息
        for (int j = 0; j < K; ++j) {
            scanf("%lld %d", &students[totalStudents].studentID, &students[totalStudents].score);
            students[totalStudents].classID = i + 1; // 班级编号
            students[totalStudents].classRank = 0;   // 班级排名初始化为0
            totalStudents++;
        }
    }

    // 对学生数组进行排序
    qsort(students, totalStudents, sizeof(Student), compare);

    // 计算班级排名
    for (int i = 0; i < totalStudents; ++i) {
        if (i == 0 || students[i].score != students[i - 1].score) {
            students[i].classRank = i + 1;
        } else {
            students[i].classRank = students[i - 1].classRank;
        }
    }

    // 输出结果
    printf("%d\n", totalStudents);
    for (int i = 0; i < totalStudents; ++i) {
        printf("%lld %d %d %d\n", students[i].studentID, students[i].classRank, students[i].classID, students[i].classRank);
    }

    return 0;
}


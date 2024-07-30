# include <iostream>
using namespace std;

struct Student{
    int score;
    int class_rank;
    int department_rank;
    int class_id;
    long long id;
};

int rank_department(struct Student stu_list[], int lenth){
    struct Student stu_temp = {};
    for ( int i = 0; i < lenth - 1;  ++i ){
        int max = i;
        for ( int j = i ; j < lenth;  ++j ){
            if ( stu_list[max].score < stu_list[j].score ){
                stu_temp = stu_list[max];
                stu_list[max] = stu_list[j];
                stu_list[j] = stu_temp;
            }
        }

        stu_list[0].department_rank = 1;
        for ( int j = 1, i = 1; i < lenth; ++i ){
            if ( stu_list[i].score == stu_list[i - 1].score ){
                stu_list[i].department_rank = j;
                j += 1;
            }
            else{
                j += 1;
                stu_list[i].department_rank = j;
            }
        }
    }
    return 0;
}

int rank_class(struct Student stu_list[], int lenth){
    struct Student stu_temp = {};
    for ( int i = 0; i < lenth - 1;  ++i ){
        int max = i;
        for ( int j = i ; j < lenth;  ++j ){
            if ( stu_list[max].score < stu_list[j].score ){
                stu_temp = stu_list[max];
                stu_list[max] = stu_list[j];
                stu_list[j] = stu_temp;
            }
        }

        stu_list[0].class_rank = 1;
        for ( int j = 1, i = 1; i < lenth; ++i ){
            if ( stu_list[i].score == stu_list[i - 1].score ){
                stu_list[i].class_rank = j;
                j += 1;
            }
            else{
                j += 1;
                stu_list[i].class_rank = j;
            }
        }
    }
//     for ( int i = 0; i < lenth;  ++i ){
//         cout << "id: " << stu_list[i].id << ", class_rank: " << stu_list[i].class_rank << ", score: " << stu_list[i].score << endl;
//     }
    return 0;
}

int output(struct Student stu_list[], int lenth){
    for ( int i = 0 ; i < lenth; ++i ){
        cout << stu_list[i].id << " " << stu_list[i].department_rank << " " << stu_list[i].class_id << " " << stu_list[i].class_rank;
        if ( i != lenth - 1 )
            printf("\n");
    }
    return 0;
}

int sort_id(struct Student stu_list[], int lenth){
    struct Student stu_temp = {};
    for ( int i = 0; i < lenth; ++i ){
        if ( (stu_list[i].score == stu_list[i+1].score) && (stu_list[i].id >= stu_list[i+1].id) ){
            stu_temp = stu_list[i];
            stu_list[i] = stu_list[i+1];
            stu_list[i+1] = stu_temp;
        }
    }
    return 0;
}

int main(void){
    int class_total = 0, stu_total_in_each_class = 0, stu_total = 0;
    struct Student class_rank_list[300] = {}, department_rank_list[10000] = {};

    cin >> class_total;
    for ( int i = 0; i < class_total; ++i ){

        cin >> stu_total_in_each_class;
        for ( int j = 0; j < stu_total_in_each_class; ++j ){
            struct Student stu = {};
            cin >> stu.id >> stu.score;
            stu.class_id = i + 1;
            class_rank_list[j] = stu;
        }

        rank_class(class_rank_list, stu_total_in_each_class);
        for ( int i = 0; i < stu_total_in_each_class; ++i ){
            department_rank_list[stu_total + i] = class_rank_list[i];
        }
        stu_total += stu_total_in_each_class;

    }
    rank_department(department_rank_list, stu_total);
    sort_id(department_rank_list, stu_total);
    cout << stu_total << "\n";
    output(department_rank_list, stu_total);
    return 0;
}

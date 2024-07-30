# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct{
    int hour;
    int minute;
    int second;
}Time;

typedef struct{
    Time arrive_time;
    int consuming_time;
    int waiting_time;
}Customer;

int takein(Customer people_list[], int total){
    for ( int i = 0; i < total; ++i ){
        Customer people = {};
        scanf(" %d:%d:%d %d", &people.arrive_time.hour, &people.arrive_time.minute, &people.arrive_time.second, &people.consuming_time);
        people.consuming_time *= 60;
        people_list[i] = people;
    }
    return 0;
}

int compare_arrive_time(const void *a, const void *b){
    Customer *pc1 = (Customer *)a;
    Customer *pc2 = (Customer *)b;
    if ( pc1->arrive_time.hour == pc2->arrive_time.hour ){
        if ( pc1->arrive_time.minute == pc2->arrive_time.minute ){
            if ( pc1->arrive_time.minute == pc2->arrive_time.minute ){
                return 0;
            }
            return ( pc1->arrive_time.second < pc2->arrive_time.second )? -1:1;
        }
        return ( pc1->arrive_time.minute < pc2->arrive_time.minute )? -1:1;
    }
    return ( pc1->arrive_time.hour < pc2->arrive_time.hour )? -1:1;
}

int compare_time(Time time1, Time time2){
    if ( time1.hour == time2.hour ){
        if ( time1.minute == time2.minute ){
            if ( time1.second == time2.second ){
                return 0;
            }
            return ( time1.second < time2.second )? -1:1;
        }
        return ( time1.minute < time2.minute )? -1:1;
    }
    return ( time1.hour < time2.hour )? -1:1;
}

Time add_time(Time time){
    time.second += 1;
    time.minute += time.second / 60;
    time.hour   += time.minute / 60;
    time.hour    = time.hour   % 24;
    time.second  = time.second % 60;
    time.minute  = time.minute % 60;
    return time;
}

int simulation(Customer people_list[], int people_total, int windows){
    int state_list[people_total] = {};
    Time start = people_list[0].arrive_time;
    Time open = {8, 0, 0};
    Time end = {17, 0, 1};

    for ( int i = 0; i < people_total; ++i ){ state_list[i] = 0; }

    for ( ; compare_time(start, end) != 0; start = add_time(start) ){

//         printf("[%.2d:%.2d:%.2d]\n", start.hour, start.minute, start.second);
        for ( int i = 0; i < people_total; ++i ){
//             printf("%2d:%.2d\t", i, people_list[i].waiting_time);
        }
//         printf("\n");
//         printf("state: \n");
        for ( int i = 0; i < people_total; ++i ){
//             printf("%4d\t", state_list[i]);
            if ( state_list[i] == 0 && (compare_time(start, people_list[i].arrive_time) == 0)) state_list[i] = 1;
        }
//         printf("\n");
//         printf("\n");

        int windows_left = (compare_time(start, open) >= 0)? windows:0;
        for ( int i = 0; i < people_total; ++i ){
            if (  people_list[i].consuming_time == 0 ){
                state_list[i] = 0;
                continue;
            }

            if ( state_list[i] == 1 ){
                if ( windows_left == 0 ){
                    people_list[i].waiting_time += 1;
                }
                else{
                    people_list[i].consuming_time -= 1;
                    windows_left -= 1;
                }
            }
        }
    }
    return 0;
}

int output(Customer people_list[], int customer_total){
    int sum = 0, waiting_customer = 0;
    for ( int i = 0; i < customer_total; ++i ){
        sum += people_list[i].waiting_time;
        Time end = {17, 0, 0};
        if ( compare_time(end, people_list[i].arrive_time) >= 0 )
            waiting_customer += 1;
    }
    printf("%.1lf", ((double)sum / 60 / ((double)waiting_customer)));
    return 0;
}

int main(void){
    int customer_total = 0, windows = 0;
    Customer people_list[10000] = {};
    scanf("%d %d", &customer_total, &windows);
    takein(people_list, customer_total);
    qsort(people_list, customer_total, sizeof(people_list[0]), compare_arrive_time);
//     for ( int i = 0; i < customer_total; ++i ){
//         printf("%.2d:%.2d:%.2d\n", people_list[i].arrive_time.hour, people_list[i].arrive_time.minute, people_list[i].arrive_time.second);
//     }
    simulation(people_list, customer_total, windows);
    output(people_list, customer_total);
    return 0;
}

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>

typedef struct{
    int hour;
    int minute;
    int second;
}Time;

typedef struct{
    Time checkin;
    Time checkout;
    char id[15];
}Record;

Record make_record(void){
    Record record = {};
    scanf(" %s %d:%d:%d %d:%d:%d", record.id, &record.checkin.hour, &record.checkin.minute, &record.checkin.second, &record.checkout.hour, &record.checkout.minute, &record.checkout.second);
    return record;
}

bool is_earlier(Time time1, Time time2){
    if ( time1.hour < time2.hour )
        return true;
    else if ( time1.minute < time2.minute )
        return true;
    else if ( time1.second < time2.second )
        return true;
    return false;
}

int main(void){
    int record_amount = 0, earliest = 0, latest = 0;
    Record table[100] = {};
    scanf("%d", &record_amount);
    for ( int i = 0; i < record_amount; ++i ){
        table[i] = make_record();
    }
    for ( int i = 0; i < record_amount; ++i ){
        if ( is_earlier(table[i].checkin, table[earliest].checkin) ){
            earliest = i;
        }
        if ( is_earlier(table[latest].checkout, table[i].checkout) ){
            latest = i;
        }
    }
    printf("%s %s", table[earliest].id, table[latest].id);
    return 0;
}

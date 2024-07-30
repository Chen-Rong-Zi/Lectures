typedef struct{
    int hour;
    int minute;
    int second;
}Time;

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

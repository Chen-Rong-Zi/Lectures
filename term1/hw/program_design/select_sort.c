# include <stdio.h>
# include <stdlib.h>
# include <time.h>

int make_random_list(int *array, int lenth){
    int i = 0;
    for ( ; i < lenth; ++i){
        array[i] = rand() % 100;
    }
    return (i == lenth)? 0:1;
}

int select_sort(int *array, int lenth){
    if ( lenth == 0 ) return 0;
    int i = 0, max_index = 0, temp = 0;
    for ( i = 0; i < lenth; ++i){
        (array[i] >= array[max_index]) && (max_index = i);
    }
    if ( array[lenth-1] != array[max_index] ){
        array[lenth-1]   = array[lenth-1] ^ array[max_index];
        array[max_index] = array[lenth-1] ^ array[max_index];
        array[lenth-1]   = array[lenth-1] ^ array[max_index];
    }
    return select_sort(array, lenth-1);
}

int main(void){
    int lst[10] = {0}, i = 0;
    // scanf("%d",  &i);
    srand(time(NULL));
    make_random_list(lst, 10);
    select_sort(lst, 10);
    for ( ; i < 10; ++i){
        printf("%d\t", lst[i]);
    }
    return 0;
}

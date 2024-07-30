# include<stdio.h>
# include<stdbool.h>

bool in_array(int array[], int lenth, int i){
    bool flag = false;
    for ( int j = 0; j < lenth; ++j){
        flag = flag || (array[j] == i);
        printf("array[%d] = %d  ", j, array[j]);
    }
    printf("i = %d, lenth = %d, flag = %d\n", i, lenth, flag);
    return flag;
}

int main(void){
    int array[200] = {0}, n = 0, lenth = 0;
    scanf("%d", &n);
    for ( int i = 0; getchar() != EOF; ++i){
        lenth++;
        scanf("%d", &array[i]);
    }

    for ( int i = 0; i < n+1; ++i){
        if ( !in_array(array, lenth, i) )
            printf("%d ", i);
    }
    return 0;
}

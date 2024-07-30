# include<stdio.h>

int main(void){
    int n = 0, array[100] = {0}, i = 0, temp = 0, k = 0;
    scanf("%d", &n);
    i = 0, temp = n;
    while ( n != 0 ){
        scanf("%d", &array[i]);
        ++i, --n;
    }

    k = temp - 1;
    while ( k > 0 ){
        i = 0;
        while ( i < k ){
            if ( array[i] < array[i+1] ){
                array[i] = array[i]   ^ array[i+1];
                array[i+1] = array[i] ^ array[i+1];
                array[i] = array[i]   ^ array[i+1];
            }
            ++i;
        }
        --k;
    }
    int l = 0;
    for ( l = 0; l < temp; l++){
    //         printf("array[%d] = %d\n", l, array[l]);
    }
    printf("%d %d", array[1], array[temp-2]);
    return 0;
}

# include<stdio.h>
# include<stdbool.h>

void swap(int *x, int *y) {
    int i = 0;
    i  = *x;
    *x = *y;
    *y = i;
}

void bubbleSort(int *pArray, int len) {
    int i; // Iteration variables
    for ( i = len-1; len > 0; --len ) {
        for ( i = 0; i < len-1; ++i ) {
            if ( pArray[i] > pArray[i+1] ) {
                swap(&pArray[i], &pArray[i+1]);
            }
        }
    }
}

bool isDuplicate(int array[], int lenth, int k){
    int sum = 0, i = 0;
    for ( i = 0; i < lenth; ++i){
        if ( k == array[i] )
            sum++;
    }
    return sum > 1;
}

void takein(int array[], int lenth){
    for ( int i = 0; i < lenth; ++i){
        scanf("%d", &(array[i]));
    }
}

void deleteDuplicate(int array[], int lenth){
    for ( int i = 0; i < lenth; ++i){
        if ( isDuplicate(array, lenth, array[i]) ){
            array[i] = -1;
        }
    }
}

int main(void){
    int array[1001] = {0}, lenth = 0;
    scanf("%d", &lenth);
    takein(array, lenth);
    deleteDuplicate(array, lenth);
    bubbleSort(array, lenth);
    for ( int i = 0; i < lenth; ++i){
        if ( array[i] == -1 ) continue;
        printf("%d ", array[i]);
    }
    return 0;
}

# include <stdio.h>

int main(int arg_number, char **arg_value) {
    int n = 11;
    int array[] = {0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    for ( int i = 0; i < n; ++i) {
        int min = i;
        for ( int j = i + 1; j < n; ++j) {
            if ( array[j] > array[min] ) {
                int temp     = array[j];
                array[j]   = array[min];
                array[min] = temp;
                printf("%d ", array[j]);
                if ( j == n - 1 )
                    printf("\n");
            }
        }
    }
    return 0;
}

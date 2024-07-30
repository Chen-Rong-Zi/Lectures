# include <stdlib.h>
# include <stdio.h>
# include <time.h>

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}


int main(int arg_number, char **arg_value) {
    srand(time(NULL));
    int array[50];

    for ( int i = 0 ; i < 50; ++i )
    {
        array[i] = rand() % 20;
    }

    qsort(array, 50, sizeof(int), compare);
    for ( int i = 0; i < 50; ++i ) printf("%d ", array[i]);

    printf("\n");
    int key = 10;
    int *result = (int *)bsearch(&key, array, 50, sizeof(int), compare);

    printf("%d\n", *result);
    return 0;
}

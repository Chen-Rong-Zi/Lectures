# include<stdio.h>

int out(int *array, int range){
    for ( int i = 0; i < range; ++i){
        printf("%d ", *(array+i));
    }
}

int main(void){
    int array[10][10] = {{1}, {3, 4, 5}, {4, 5, 6}};
//     for ( int i; i < 10; ++i){
//         for ( int j = 0; j < 10; ++j){
//             array[i][j] = j * (i + 1);
//             printf("%d\n", array[i][j]);
//         }
//     }
//     for ( int i = 0; i < 100; ++i){
//         printf("%20d", *((*array)+i));
//         if ( (i+1) % 10 == 0 )
//             printf("\n");
//     }
    out(&array, 100);
}

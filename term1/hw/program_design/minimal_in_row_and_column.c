# include<stdio.h>
# include<assert.h>

int array[100][100];

void takein(int row, int column){
    for ( int i = 0; i < row; ++i){
        assert(i < row);
        for ( int j = 0; j < column; ++j){
            assert(j < column);
            scanf("%d", &(array[i][j]));
        }
    }
}

void minimal_in_row(int row, int column){
    int sum = 0, j = 0, i = 0;
    for ( i = 0; i < row; ++i){
        assert(i < row);
        sum = 0;
        for ( j = 0; j < column; ++j){
            assert(j < column);
            if (array[i][j] < 0){
                sum += 1;
            }
        }
        if ( i != row-1 )
            printf("%d ", sum);
    }
    printf("%d\n", sum);
}


void minimal_in_column(int row, int column){
    int sum = 0;
    for ( int j = 0; j < column; ++j){
        assert(j < column);
        sum = 0;
        for ( int i = 0; i < row; ++i){
            assert(i < row);
            if (array[i][j] < 0){
                sum += 1;
            }
        }
        if ( j != column-1 )
            printf("%d ", sum);
        else
            printf("%d", sum);
    }
}

int main(void){
    int row = 0, column = 0;
    scanf("%d %d", &row, &column);
    takein(row, column);
    minimal_in_row(row, column);
    minimal_in_column(row, column);
    return 0;
}

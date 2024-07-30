# include <stdio.h>

int matr_a[100][100] = {};
int matr_b[100][100] = {};
int matr_c[100][100] = {};
int a_row = 0, a_col = 0, b_row = 0;

int takein(void){
    scanf("%d %d %d", &a_row, &a_col, &b_row);
    for ( int i = 0; i < a_row; ++i )
    {
        for ( int j = 0; j < a_col; ++j )
        {
            scanf(" %d", &(matr_a[i][j]));
        }
    }

    for ( int i = 0; i < b_row; ++i )
    {
        for ( int j = 0; j < b_row; ++j )
        {
            scanf(" %d", &(matr_b[i][j]));
        }
    }
    return 0;
}

int product(int row, int col)
{
    int start_row = 0, start_col = 0;
    for ( int i = 0; i < row; ++i )
    {
        for ( int j = 0; j < col; ++j)
        {
            int result = 0;
            for ( int k = 0; k < b_row; ++k )
            {
                for ( int l = 0; l < b_row; ++l )
                {
                    result = result + matr_a[start_row + k][start_col + l] * matr_b[k][l];
                }
            }
            matr_c[i][j] = result;
            ++start_col;
            if ( start_col == col )
                start_col = 0;
        }
        ++start_row;
    }
    return 0;
}

int main(void){
    int c_row, c_col;
    takein();
    c_row = a_row - b_row + 1;
    c_col = a_col - b_row + 1;
    product(c_row, c_col);
    for ( int i = 0; i < c_row; ++i )
    {
        for ( int j = 0; j < c_col; ++j )
        {
            printf("%d ", matr_c[i][j]);
        }
        if ( i != c_row )
            printf("\n");
    }
    return 0;
}

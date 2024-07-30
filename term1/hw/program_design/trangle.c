# include <stdio.h>
# include <math.h>

char map[10000][10000] = {0};

void trangle(int n, int row, int column){
    if ( n == 1 ){
        map[row][column] = '*';
        map[row][column+1] = ' ';
        return;
    }
    else{
        trangle(n-1, row, column);
        trangle(n-1, row, column+pow(2, n-1));
        trangle(n-1, row+pow(2,n-2), column);
    }
}

int main(void){
    int n = 0, shift = 0;
    scanf("%d", &n);
    trangle(n, 0, 0);
    shift = pow(2, n);
    int temp = shift;
    for ( int i = 0; i < shift/2;  ++i){
        for ( int j = 0; j < temp-1; ++j){
            if ( map[i][j] == 0 )
                printf(" ");
            else
                printf("%c", map[i][j]);
        }
        temp = temp - 2;
        printf("\n");
    }
    return 0;
}

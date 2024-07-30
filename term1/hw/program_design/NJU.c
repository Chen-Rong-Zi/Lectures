# include<stdio.h>
# include<stdbool.h>

int row = 0, column = 0;
char map[30][30] = {0};

void takein(){
    scanf("%d %d\n", &row, &column);
    for ( int i = 0; i < row; ++i){
        for ( int j = 0; j < column; ++j){
            if ( j != column - 1 )
                scanf("%c ", &(map[i][j]));
            else
                if ( i == row - 1 )
                    scanf("%c", &(map[i][j]));
                else
                    scanf("%c\n", &(map[i][j]));
        }
    }
}

bool in_map(int i, int j){
    return (i >= 0 && i < row) && (j >= 0 && j < column);
}

int search(){
    int result = 0;
    for ( int i = 0; i < row; ++i){
        for ( int j = 0;  j < column; ++j){
            if ( map[i][j] == 'N' ){
                if ( in_map(i+1, j) && map[i+1][j] == 'J' )
                    if ( in_map(i+2, j) && map[i+2][j] == 'U' )
                        ++result;
                if ( in_map(i-1, j) && map[i-1][j] == 'J' )
                    if ( in_map(i-2, j) && map[i-2][j] == 'U' )
                        ++result;
                if ( in_map(i, j+1) && map[i][j+1] == 'J' )
                    if ( in_map(i, j+2) && map[i][j+2] == 'U' )
                        ++result;
                if ( in_map(i, j-1) && map[i][j-1] == 'J' )
                    if ( in_map(i, j-2) && map[i][j-2] == 'U' )
                        ++result;

                if ( in_map(i+1, j+1) && map[i+1][j+1] == 'J' )
                    if ( in_map(i+2, j+2) && map[i+2][j+2] == 'U' )
                        ++result;
                if ( in_map(i-1, j-1) && map[i-1][j-1] == 'J' )
                    if ( in_map(i-2, j-2) && map[i-2][j-2] == 'U' )
                        ++result;
                if ( in_map(i+1, j-1) && map[i+1][j-1] == 'J' )
                    if ( in_map(i+2, j-2) && map[i+2][j-2] == 'U' )
                        ++result;
                if ( in_map(i-1, j+1) && map[i-1][j+1] == 'J' )
                    if ( in_map(i-2, j+2) && map[i-2][j+2] == 'U' )
                        ++result;
            }
        }
    }
    return result;
}

int main(void){
    takein();
    printf("%d", search());
    return 0;
}

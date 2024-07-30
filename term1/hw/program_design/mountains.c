# include<stdio.h>

int row = 0, column = 0;
int map[10][10] = {0};

void takein(){
    scanf("%d %d", &row, &column);
    for ( int i = 0; i < row; ++i){
        for ( int j = 0;  j < column; ++j){
            scanf("%d", &(map[i][j]));
        }
    }
}

int meter(int i, int j){
    int result = 0;
    if ( i+1 >= row || map[i+1][j] == 0 )
        ++result;
    if ( i-1 < 0 || map[i-1][j] == 0 )
        ++result;
    if ( j+1 >= column || map[i][j+1] == 0 )
        ++result;
    if ( j-1 < 0 || map[i][j-1] == 0 )
        ++result;

    return result;
}

int perimeter(int m[][10]){
    int sum = 0;
    for ( int i = 0; i < row; ++i){
        for ( int j = 0; j < column; ++j){
            if ( map[i][j] != 0 )
                sum += meter(i, j);
        }
    }
    return sum;
}

int main(void){
    takein();
    printf("%d", perimeter(map));
    return 0;
}

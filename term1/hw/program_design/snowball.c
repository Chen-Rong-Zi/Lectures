# include <stdio.h>

int row = 0, column = 0;
char map[100][50] = {0};
void output();
void fall(int, int);

void takein(){
    scanf("%d %d", &row, &column);
    for ( int i = 0; i < row; ++i){
        scanf("%s", map[i]);
    }
}

void ball(int r){
    if ( r == row - 1){
        return;
    }
    ball(r+1);
    for ( int i = 0; i < column; ++i){
        for ( int j = 1; j < row; ++j){
            if ( map[r][i] == 'o' && map[j+1][i] == '.'){
                fall(r, i);
            }
        }
    }
}

void fall(int r, int c){
    if ( r == row - 1 || map[r+1][c] != '.' )
        return;
    else{
        map[r][c] = '.';
        map[r+1][c] = 'o';
        fall(r+1, c);
    }
}

void output(){
    for ( int i = 0; i < row; ++i){
        for ( int j = 0; j < column; ++j){
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}

int main(){
    takein();
    ball(0);
    output();
    return 0;
}

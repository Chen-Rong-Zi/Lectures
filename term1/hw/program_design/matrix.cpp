# include <iostream>
using namespace std;

void print_matr(char matr[][10][10], int row, int column){
    for ( int i = 0; i < row; ++i){
        for ( int j = 0; j < column; ++j){
            cout << matr[i][j];
        }
    }
}

int main(void){
    char matr[10][10][10] = {'\0'};
    int row = 0, column = 0;

    cin >> row >> column;
    for ( int i = 0; i < row; ++i){
        for ( int j = 0; j < column; ++j){
            cin >> matr[i][j];
        }
    }
    print_matr(matr, row, column);
    return 0;
}


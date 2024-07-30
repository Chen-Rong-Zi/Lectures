# include<stdio.h>
# define I 1
# define V 5
# define X 10
# define L 50
# define C 100
# define D 500
# define M 1000

int main(void){
    int temp, currChar, sum, lastChar; currChar = sum = lastChar = temp = 0;
    while ( (currChar = getchar()) != '\n' ){
        if ( currChar == 'I' ) currChar = I;
        else if ( currChar == 'V' ) currChar = V;
        else if ( currChar == 'X' ) currChar = X;
        else if ( currChar == 'L' ) currChar = L;
        else if ( currChar == 'C' ) currChar = C;
        else if ( currChar == 'D' ) currChar = D;
        else if ( currChar == 'M' ) currChar = M;
        temp = currChar;
        if ( lastChar < currChar ){
            currChar = -(2*lastChar) + currChar;
        }
        sum += currChar;
        lastChar = temp;
    }
    printf("%d\n", sum);
    return 0;
}

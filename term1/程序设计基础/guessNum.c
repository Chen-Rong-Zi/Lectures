# include<stdio.h>

int main(void){
    unsigned a, a1, a2, a3, a4, b, b1, b2, b3, b4, A, B, aLastDigit, bLastDigit, sameNum, temp_b, temp_a, i, n, temp1_a;
    a = a1 = a2 = a3 = a4 = b = b1 = b2 = b3 = b4 = A = B = aLastDigit = bLastDigit = sameNum = temp_a = temp_b = i = n = temp1_a = 0;
    scanf("%d", &a);
    scanf("%d", &n);
    for ( ; i < n; ++i) {
        A = B = 0;
        scanf("%d", &b);
        temp_a = a;
        temp_b = b;
        while ( temp_a > 0 && temp_b > 0 ){
            aLastDigit = temp_a % 10;
            bLastDigit = temp_b % 10;
            temp_a = temp_a / 10;
            temp_b = temp_b / 10;
            if ( aLastDigit == bLastDigit )
                A += 1;
        }
        temp1_a = a;
        a1 = temp1_a % 10; temp1_a /= 10;
        a2 = temp1_a % 10; temp1_a /= 10;
        a3 = temp1_a % 10; temp1_a /= 10;
        a4 = temp1_a % 10;
        b1 = b % 10; b /= 10;
        b2 = b % 10; b /= 10;
        b3 = b % 10; b /= 10;
        b4 = b % 10;
        sameNum = ((a1 == b1) || (a1 == b2) || (a1 == b3) || (a1 == b4)) + ((a2 == b1) || (a2 == b2) || (a2 == b3) || (a2 == b4)) + ((a3 == b1) || (a3 == b2) || (a3 == b3) || (a3 == b4)) + ((a4 == b1) || (a4 == b2) || (a4 == b3) || (a4 == b4));
        B = sameNum - A;
        printf("%dA%dB\n", A, B);
    }
    return 0;
}

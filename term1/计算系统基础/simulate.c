# include <stdio.h>
# include <stdlib.h>

int main(int arg_number, char **arg_value){
    int R3 = 0x80000000, R2 = 0, R4 = 0, R1 = atoi(arg_value[1]);
    int j = 0;
    printf("below------------------\n");
    while ( j < 1000 ){
        R4 = R3 & R1;
        if ( R4 != 0 )
            ++R2;
        R1 += R2;
        if ( R1 == 0 )
            break;
        printf("R1 = %d, R2 = %d, R4 = %d\n", R1, R2, R4);
        ++j;
    }
    printf("%d", j != 1000);
}

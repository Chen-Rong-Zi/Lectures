# include <stdio.h>
# include <time.h>
# include <unistd.h>

int main(){
    char c[10000] = {};
    int i = 0;
    for ( i = 0; i != 10000; ++i ){
        c[i] = getchar();
    }

    int j = 0;
    printf("i = %d \n", i);
    while ( j < i ){
        putchar(c[j]);
        fflush(stdout);
        usleep(50);
        ++j;
    }
    return 0;
}

# include <stdio.h>

int func1(unsigned word) {
    return (int) ((word << 24) >> 24);
}

int func2(unsigned word) {
    return ((int) (word) << 24) >> 24;
}

int power(int base, int p) {
    if ( p == 0 )
        return 1;
    return power(base, p - 1) * base;
}

int len(unsigned x) {
    if ( x < 10 )
        return 1;
    return 1 + len(x / 10);
}
int char2int(char source[]) {
    if ( source[1] == '\0' )
        return source[0] - 48;

    int rest = char2int(source + 1);
    return (source[0] - 48) * power(10, len(rest)) + rest;
}

int main(int arg_number, char **arg_value) {
    printf("func1(%d) 机器数 = %08x, 值 = %d\n", char2int(arg_value[1]), func1(char2int(arg_value[1])), func1(char2int(arg_value[1])));
    printf("func2(%d) 机器数 = %08x, 值 = %d\n", char2int(arg_value[1]), func2(char2int(arg_value[1])), func2(char2int(arg_value[1])));
    return 0;
}

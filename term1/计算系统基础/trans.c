# include <stdio.h>

int main(int arg_number, char **argv){
    char c = 0, times = 0, flag = 0;
    while ( (c = getchar()) != EOF ){
        (c == '@') && (printf("0"));
        (c == '*') && (printf("1"));
        (c == ' ') && (printf(" "));
        (c == '\n') && ((flag == 1)? (flag = 0):printf("\n"));
        (c == '0') && (printf("x"), flag = 1);
        (c == 'F') && (printf("4"));
        (c == '<') && (printf("3"));
        (c == '!') && (printf("C"));
        (c == 'J') && (printf("8"));
        (c == 'K') && (printf("A"));
        (c == 'T') && (printf("B"));
        (c == '>') && (printf("D"));
        (c == '-') && (printf("S"));
        (c == 'X') && (printf("U"));
        (c == '\'') && (printf("2"));
        (c == '\"') && (printf("I"));
        (c == '8') && (printf("N"));
        (c == ',') && (printf("O"));
        (c == 'I') && (printf("R"));
        (c == 'W') && (printf("X"));
        (c == 'B') && (printf("L"));
        (c == 'e') && (printf("T"));
        (c == 'R') && (printf("W"));
        (c == '_') && (printf("H"));
        (c == 'C') && (printf("E"));
        (c == 'g') && (printf("Q"));
        (c == '\\') && (printf("j"));
        (c == 'h') && (printf("Z"));
        (c == '9') && (printf("P"));
    }
    return 0;
}

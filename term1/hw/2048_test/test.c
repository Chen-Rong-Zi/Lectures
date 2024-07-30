# include <stdio.h>
# include <string.h>

int main(int arg_number, char **arg_value){
    if ( arg_number == 1 )
        return 0;
    if ( strcmp(arg_value[1], "rongzi") == 0 )
        printf("%s\n", arg_value[1]);
    else
        printf("%s\n", arg_value[0]);
    return 0;
}

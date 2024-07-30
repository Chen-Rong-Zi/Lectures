# include <stdio.h>
# include <stdbool.h>
# include <time.h>

void trans(char gene[200][400], int r) {
    char source[45000] = {};
    scanf("%s", source);
    int i = 0;
    for ( int group = 0;  group < r; ++group )
    {
        for ( int ele = 0; source[group + ele * r] != '\0'; ++ele )
        {
            printf("source[%d] = %c, ascii = %d\n", group + ele * r, source[group + ele * r], source[group + ele * r]);
            gene[group][ele] = source[group + ele * r];
        }
    }
    return ;
}

bool check(char gene[200][400], int r) {
    int lenth1 = 0;
    for ( int i = 0; i < r; ++i )
    {
        int j = 0;
        for (  j = 1; gene[i][j] != '\n' && gene[i][j] != '\0'; ++j )
        {
            if ( gene[i][j - 1] != gene[i][j] )
                return false;
        }
        lenth1 = j;
    }

    int lenth = 0;
    for ( int i = 1; i < r; ++i )
    {
        for ( lenth = 0; gene[i][lenth] != '\n' && gene[i][lenth] != '\0'; ++lenth );
        if ( lenth != lenth1 ) {
           return false;
        }
    }

    return true;
}

int main(int arg_number, char **arg_value) {
    int r = 0;
    scanf("%d", &r);
    char gene[200][400] = {};
    trans(gene, r);

    if ( check(gene, r) )
    {
        for ( int i = 0; i < r; ++i ) {
            for ( int j = 0; gene[i][j] != '\n' && gene[i][j] != '\0'; ++j ) {
                printf("%c", gene[i][j]);
            }
            if ( i != r - 1 )
                printf("\n");
        }
    } else {
        printf("N");
    }
}

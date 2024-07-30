# include<stdio.h>
# include<string.h>
# include<stdbool.h>
# include<stdlib.h>
# define STRLENTH 50

char file[20][STRLENTH] = {'\0'};
int n = 0;

char lower(char x){
    if ( x >= 65 && x <= 90 )
        return (x + 32);
    return x;
}

void takein(){
    scanf("%d", &n);
    for ( int i = 0; i < n; ++i){
        scanf("%s", file[i]);
    }
}

int len(char string[]){
    int lenth = 0;
    for ( lenth = 0; string[lenth] != '\0'; ++lenth){}
    return lenth;
}

void notcopy(char s1[], char s2[]){
    for ( int i = 1; i < len(s1); ++i)
    {
        s2[i-1] = s1[i];
    }
}

bool morePriority(char s1[], char s2[]){
    if ( s1[0] == s2[0] && s1[0] == '\0' )
        return false;
    if ( abs((s1[0] - s2[0])) != 32 )
    {
        if ( lower(s1[0]) < lower(s2[0]) )
            return true;
        else if ( lower(s1[0]) > lower(s2[0]) )
            return false;
    }
    else
    {
        if ( s1[0] < s2[0] )
            return true;
        else if ( s1[0] > s2[0] )
            return false;
    }

    char temp1[STRLENTH] = {'\0'}, temp2[STRLENTH] = {'\0'};
    notcopy(s1, temp1);
    notcopy(s2, temp2);
    return morePriority(temp1, temp2);
}

void sort(){
    int maxIndex = 0, j = 0, i = 0;
    char temp[STRLENTH];
    for ( i = 0; i < n; ++i)
    {
        maxIndex = i;
        for ( j = i; j < n; ++j)
        {
            if ( morePriority(file[j], file[maxIndex]) )
            {
                maxIndex = j;
            }
        }
        strcpy(temp, file[i]);
        strcpy(file[i], file[maxIndex]);
        strcpy(file[maxIndex], temp);
    }
}

void output(){
    for ( int i = 0; i < n; ++i){
        printf("%s ", file[i]);
    }
}

int main(void){
    takein();
    sort();
    output();
    return 0;
}

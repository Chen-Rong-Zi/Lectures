# include<stdio.h>
# include<string.h>
# include<stdbool.h>

bool asSameLen(char a[], char b[]){
    return strlen(a) == strlen(b);
}

long sumLen(char a[], char b[]){
    return strlen(a) + strlen(b);
}

bool isNumber(char string[], int len){
    for ( int i = 0; i < len; ++i){
        if ( string[i] < 48 || string[i] > 57 ){
            return false;
        }
    }
    return true;
}

int minLen(char s1[], char s2[]){
    return (strlen(s1) > strlen(s2))?strlen(s1):strlen(s2);
}

int strToDigit(char string[]){
    int digit = 0;
    for ( int i = 0; i < strlen(string); ++i){
        digit = digit * 10 + (string[i]-48);
    }
    return digit;
}

int findMaxPrefix(char s1[], char s2[]){
    int prefix = 0;
    for ( int i = 0; i < minLen(s1, s2); ++i  ){
        if ( s1[i] == s2[i] )
            prefix++;
        else
            break;
    }
    return prefix;
}

int main(void){
    char a[10] = {0}, b[10] = {0};
    scanf("%s %s", a, b);
    printf("%ld\n", sumLen(a, b));
    printf("%d\n", findMaxPrefix(a, b));
    if ( isNumber(a, strlen(a)) && isNumber(b, strlen(b)) ){
        printf("%d", strToDigit(a) + strToDigit(b));
    }
    else
        printf("%s", strcat(a, b));
    return 0;
}

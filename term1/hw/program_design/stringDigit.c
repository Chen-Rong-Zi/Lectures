# include<stdio.h>
# include<string.h>
# include<math.h>

char s1[100] = {'\0'}, s2[100] = {'\0'}, sum[101] = {'\0'};

int lenth(char s[]){
    int i = 0;
    for ( i = 99; s[i] == '\0'; --i){
    }
    return i+1;
}

void takein(void){
    int len1 = 0, len2 = 0;
    scanf("%s %s", s1, s2);
    len1 = lenth(s1);
    len2 = lenth(s2);
    for ( int i = 0; i < len1/2; ++i){
        s1[i] = s1[i] ^ s1[len1-i-1];
        s1[len1-i-1] = s1[i] ^ s1[len1-i-1];
        s1[i] = s1[i] ^ s1[len1-i-1];
    }
    for ( int i = 0; i < len2/2; ++i){
        s2[i] = s2[i] ^ s2[len2-i-1];
        s2[len2-i-1]  = s2[i] ^ s2[len2-i-1];
        s2[i] = s2[i] ^ s2[len2-i-1];
    }
}

void add(char s1[], char s2[]){
    int len1 = lenth(s1), len2 = lenth(s2), minLen = (len1 > len2)?len2:len1, maxLen = (len1+len2)-minLen;
    for ( int i = 0; i < minLen; ++i){
        sum[i] += s1[i] + s2[i] - 96;
        if ( sum[i] >= 10 ){
            sum[i+1] = sum[i] / 10;
        }
        sum[i] = sum[i] % 10;

    }
    for ( int i = minLen; i < maxLen; ++i){
        if ( maxLen == len1 ){
            sum[i] += s1[i]-48;
            sum[i+1] += sum[i] / 10;
            sum[i] = sum[i] % 10;
        }
        else if ( maxLen == len2 ){
            sum[i] += s2[i]-48;
            sum[i+1] += sum[i] / 10;
            sum[i] = sum[i] % 10;
        }
    }
}

void out(){
    int index = ((lenth(s1) > lenth(s2))?lenth(s1):lenth(s2)) - 1;
    if ( sum[index+1] != 0 ) index = index+1;
    for ( ; index >= 0; --index){
        printf("%d", sum[index]);
    }
}

int main(void){
    takein();
    add(s1, s2);
    out();
    return 0;
}

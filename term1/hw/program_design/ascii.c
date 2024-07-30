# include<stdio.h>

int len(char string[]){
    int lenth = 0;
    for ( lenth = 0; string[lenth] != '\0'; ++lenth){}
    return lenth;
}

int asciiSum(char string[]){
    int sum = 0;
    for ( int i = 0; i < len(string); ++i){
        sum += string[i];
    }
    return sum;
}

int main(void){
    char *a = {"AbC.txt"};
    char *b = {"abc.TXT"};
    char *c = {"aBc.TxT"};
    printf("AbC.txt = %d\n", asciiSum(a));
    printf("abc.TXT = %d\n", asciiSum(b));
    printf("aBc.Txt = %d\n", asciiSum(c));
    return 0;
}

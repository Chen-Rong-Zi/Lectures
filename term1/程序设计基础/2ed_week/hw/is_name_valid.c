# include<stdio.h>

int isNum(int a){
    if (a >='0' && a <= '9')
        return 1;
    return 0;
}


int isAlp(int a){
    if ((a >= 'a' && a <= 'z') || (a >= 'A' && a <= 'Z'))
        return 1;
    return 0;
}

int isSlh(int a){
    if (a == '_')
        return 1;
    return 0;
}

int isVld(int a){
    if (isNum(a) || isSlh(a) || isAlp(a))
        return 1;
    return 0;

}

int main(void){
    char n1, n2, n3;
    n1 = n2 = n3 = '0';
    scanf("%c %c %c", &n1, &n2, &n3);
    if (!(isVld(n1) && isVld(n2) && isVld(n3))){
        printf("no\n");
        return 0;
    }
    if (!(isAlp(n1) || isSlh(n1))){
        printf("no\n");
        return 0;
    }
    printf("yes\n");
    return 0;
}


# include<stdio.h>

int main(void){
    int mooncake, children, rest, sevenLeft;
    mooncake = children = rest = sevenLeft = 0;
    scanf("%d %d", &mooncake, &children);
    if ( mooncake > children * 8 ){
        printf("%d", children - 1);
        return 0;
    }

    rest = mooncake - children;
    sevenLeft = rest / 7;
    if ( (children - sevenLeft) == 1 && (rest - sevenLeft * 7 + 1) == 4 )
        sevenLeft -= 1;

    printf("%d", sevenLeft);
    return 0;
}

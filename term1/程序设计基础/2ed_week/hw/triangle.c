#include<stdio.h>


int main(void){
    int x1, x2, x3, y1, y2, y3;
    x1 = x2 = x3 = y1 = y2 = y3 = 0;
    scanf("%d %d", &x1, &y1);  // A point (x1, y1)
    scanf("%d %d", &x2, &y2);  // B point (x2, y2)
    scanf("%d %d", &x3, &y3);  // C point (x3, y3)
    int cosA = (x2-x1) * (x3-x1) + (y2-y1) * (y3-y1); // cosA == AB(x2-x1, y2-y1) * AC(x3-x1, y3-y1)
    int cosB = (x1-x2) * (x3-x2) + (y1-y2) * (y3-y2); // cosA == AB(x2-x1, y2-y1) * AC(x3-x1, y3-y1)
    int cosC = (x2-x3) * (x1-x3) + (y2-y3) * (y1-y3); // cosA == AB(x2-x1, y2-y1) * AC(x3-x1, y3-y1)
    int AB   = (x1-x2) * (x1-x2) + (y1-y2) * (y1-y2);
    int BC   = (x2-x3) * (x2-x3) + (y2-y3) * (y2-y3);
    int AC   = (x1-x3) * (x1-x3) + (y1-y3) * (y1-y3);
    (cosA < 0  || cosB < 0  || cosC < 0 )? printf("1 ") : printf("0 ");
    (AB == BC  || AB == AC  || BC == AC )? printf("1 ") : printf("0 ");
    (cosA == 0 || cosB == 0 || cosC == 0)? printf("1")  : printf("0" );
    return 0;
}

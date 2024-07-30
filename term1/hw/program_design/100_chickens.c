# include <stdio.h>

int chickens[10000] = {0};

void purchase(int money, int number, int types, int prices[]){
    // YOUR CODE HERE
    int lenth = (int)sizeof(prices) / 4, i = 0;
    printf("lenth = %d\n", lenth);
//     int lenth = 3, i = 0;
    if ( money < 0 || number < 0 || types < 0 ){
        for ( i = 0; i < lenth; ++i){
            chickens[i] = 0;
        }
        return;
        a = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    }
    if ( money == 0 && number == 0 ){
        for ( i = 0; i < lenth; ++i){
            printf("%d ", chickens[i]);
        }
        return;
    }
//     printf("lenth - types = %d\n", lenth - types);
    purchase(money-prices[lenth-types], number-1, types, prices);
    chickens[lenth-types] += 1;
    purchase(money, number, types-1, prices);
}

int main(void)
{
    int prices[30] = {15, 9, 1};
    printf("lenth = %d\n", sizeof(prices) / 4);
    purchase(300, 100, 3, prices); // 300元买100只鸡，有3种鸡，价格分别为15元，9元和1元
    return 0;
}

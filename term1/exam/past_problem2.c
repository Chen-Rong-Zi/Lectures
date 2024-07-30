# include<stdio.h>

int n = 0, a = 0, b = 0, c = 0, x = 0, y = 0, z = 0;

int nextMoney(int money){
    if ( money == a ){
        return b;
    }
    if ( money == b ){
        return c;
    }
    if ( money == c ){
        return 0;
    }
    return 0;
}

int helper(int total, int money, int a_counter, int b_counter, int c_counter){
    if (a_counter > x)
        return 0;
    else if (b_counter > y)
        return 0;
    if (c_counter > z)
        return 0;

    if (money == 0)
        return 0;
    if (total == 0){
        return 1;
    }
    if (total < money)
        return 0;

    if ( money == a ){
        ++a_counter;
        return helper(total - money, money, a_counter, b_counter, c_counter) + helper(total, nextMoney(money), a_counter-1, b_counter, c_counter);
    }
    else if ( money == b ){
        ++b_counter;
        return helper(total - money, money, a_counter, b_counter, c_counter) + helper(total, nextMoney(money), a_counter, b_counter-1, c_counter);
    }
    else if ( money == c ){
        ++c_counter;
        return helper(total - money, money, a_counter, b_counter, c_counter) + helper(total, nextMoney(money), a_counter, b_counter, c_counter-1);
    }
    return 0;
}

int main(void){
    scanf("%d %d %d %d %d %d %d", &n, &a, &b, &c, &x, &y, &z);
    printf("%d\n", helper(n, a, 0, 0, 0));
    return 0;
}

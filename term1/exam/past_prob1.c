# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>


int array[10] = {2, 3, 4, 5, 6, 7};

bool is_possible(int number_of_match, int array[10], int start)
{
    if ( number_of_match == 0 )
        return true;
    if ( start >= 6 || number_of_match < 0 )
        return false;
    bool with_first = is_possible(number_of_match - array[start], array, start);
    bool without_first = is_possible(number_of_match, array, start + 1);
    return with_first || without_first;
}

int corr_number(int n)
{
    if ( n == 0 )
        return 6;
    else if ( n == 1 )
        return 2;
    else if ( n == 2 )
        return 5;
    else if ( n == 3 )
        return 5;
    else if ( n == 4 )
        return 4;
    else if ( n == 5 )
        return 5;
    else if ( n == 6 )
        return 6;
    else if ( n == 7 )
        return 3;
    else if ( n == 8 )
        return 7;
    else if ( n == 9 )
        return 6;
    return 0;
}

int max_number(int number_of_match, int result) // without + and =
{
    if ( number_of_match == 0 )
    {
        return result;
    }
    for ( int i = 9; i >= 0; --i )
    {
        int corr_memory = corr_number(i);
        if ( is_possible(number_of_match - corr_memory, array, 0) )
        {
            return max_number(number_of_match - corr_memory, result * 10 + i);
        }
    }
    return 0;
}

int number_to_match(int number)
{
    if ( number == 0 )
        return corr_number(0);

    int result = 0;
    while ( number != 0 )
    {
        result += corr_number(number % 10);
        number = number / 10;
    }
    return result;
}

int solution(int number_of_match, int max)
{
    int result = 0;
    for ( int i = 0; i <= max; ++i )
    {
        for ( int j = 0; j <= max; ++j )
        {
            if ( number_to_match(i) + number_to_match(j) + number_to_match(i + j) == number_of_match )
            {
//                 printf("sum = %d, ", number_to_match(i) + number_to_match(j) + number_to_match(i + j));
//                 printf("%d + %d == %d\n", i, j, i + j);
                ++result;
            }
        }
    }
    return result;
}

int main(int arg_number, char **arg_value){
    int n = 0;
    scanf("%d", &n);
    printf("%d", solution(n-4, max_number(n - 4, 0)));
//     for ( int i = 0; i < 100; ++i )
//     {
//         for ( int j = 0; j < 100; ++j )
//         {
//             printf("max_number(%d) = %d\n", i + j - 4, max_number(i + j - 4, 0));
//         }
//     }
    return 0;
}

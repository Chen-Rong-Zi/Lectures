# include <stdio.h>
#define max(a,b) ((a>b)?a:b)

long long array[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

long long helper(long long number_of_match, long long array[10], long long start, long long so_far) {
    if ( number_of_match == 0 )
        return so_far;
    if ( start >= 6 || number_of_match < 0 )
        return -1;

    long long with = helper(number_of_match - array[start], array, start, so_far * 10 + start);
    long long without = helper(number_of_match, array, start + 1, start);
    return max(with, without);
}

long long is_possible(long long number_of_match, long long array[10], long long start, long long so_far)
{
    return helper(number_of_match, array, 0, 0);
}

int main(int arg_number, char **arg_value) {
    for ( long long i = 0; i < 100;  ++i )
    {
        printf("%lld\t", is_possible(i, array, 0, 0));
        if ( (i + 1) % 10 == 0 ) printf("\n");
    }
}

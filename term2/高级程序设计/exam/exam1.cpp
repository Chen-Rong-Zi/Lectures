# include <cstdio>
# include <iostream>
# include <vector>
using namespace std;

vector<int> result = {};

vector<int> get_password(int box_number, int count_down, int max) {
    if ( count_down == 0 && box_number == 0 )
        return result;
    else if ( max <= box_number - count_down + 1 ) {
        result.push_back(max);
        return get_password(box_number - max, count_down - 1, max);
    }
    else if ( max > box_number - count_down + 1 ) {
        return get_password(box_number, count_down, max-1);
    }
    return vector<int>();
}

void print_password(int box_number) {
    vector<int> letter_numbers = get_password(box_number, 4, 26);
    for ( int i  : letter_numbers )
        printf("%c", (char)(i + 96));
    result = {};
    cout << '\n';
}

int main(int arg_number, char **arg_value) {
    int box_count, box_number;
    cin >> box_count;
    for (  int i = 0; i < box_count; ++i )
    {
        cin >> box_number;
        print_password(box_number);
    }
    return 0;
}

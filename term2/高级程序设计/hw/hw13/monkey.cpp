# include <iostream>
# include <vector>

int monkey_tail_recursion(int day, int currDay, int soFar) {
    if ( currDay == day )
        return soFar;
    return monkey_tail_recursion(day, currDay - 1, (soFar + 1) * 2);
}

int monkey_recursion(int day, int currDay) {
    if ( currDay == day )
        return 1;
    return (monkey_recursion(day, currDay - 1) + 1) * 2;
}

int monkey_iteration(int day) {
    int sum = 1;
    for ( int i = 0; i < 10 - day; i += 1 )
    {
        sum = (sum + 1) * 2;
    }
    return sum;
}

int peach(int day) {
    return monkey_tail_recursion(day, 10, 1);
}

int main(const int arg_number, const char **arg_value) {
    for ( const auto &it : std::vector<int>({1, 2, 3, 4, 5, 6, 7, 8, 9, 10}) )
    {
        std::cout << "moneky have " << peach(it) << " peaches" << "  ";
        std::cout << monkey_recursion(it, 10) << " peaches" << "  ";
        std::cout << monkey_iteration(it) << " peaches at " << it << "th day" << std::endl;
    }
    return 0;
}

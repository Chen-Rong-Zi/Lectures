#include <stdio.h>

int is_arithmetic(int x) {
    // Check if the number contains a zero or if it's less than 10
    if (x < 10 || x % 10 == 0)
        return -1;

    int last_digit = x % 10;
    int first_digit;
    int diff = -1;  // Initialize with an invalid difference

    while (x > 0) {
        first_digit = x % 10;
        if (diff == -1) {
            diff = last_digit - first_digit;
        }
        else {
            if (last_digit - first_digit != diff)
                return -1;
        }
        last_digit = first_digit;
        x /= 10;
    }

    return last_digit + first_digit;
}

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        int category = is_arithmetic(x);
        printf("%d\n", category);
    }

    return 0;
}


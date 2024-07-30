#include <iostream>

void purchaseHelper(int money, int number, int types, const int prices[], int currentTypes, int currentCounts[], int index) {
    if (index == types) {
        // Base case: reached the end of the prices array
        if (number == 0 && money == 0) {
            // Output the solution
            for (int i = 0; i < types; ++i) {
                std::cout << currentCounts[i] << " ";
            }
            std::cout << std::endl;
        }
        return;
    }

    // Try buying different amounts of current type of chicken
    for (int count = 0; count <= number; ++count) {
        int cost = count * prices[index];
        if (cost <= money) {
            // Update current counts and call recursively for the next type
            currentCounts[currentTypes] = count;
            purchaseHelper(money - cost, number - count, types, prices, currentTypes + 1, currentCounts, index + 1);
        }
    }
}

void purchase(int money, int number, int types, const int prices[]) {
    // Initialize an array to store the counts of each type of chicken
    int currentCounts[types] = {0};
    // Start the recursive process
    purchaseHelper(money, number, types, prices, 0, currentCounts, 0);
}

int main() {
    const int prices[] = {15, 9, 1};
    purchase(300, 100, 3, prices);
    return 0;
}


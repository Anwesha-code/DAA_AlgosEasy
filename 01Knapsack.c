#include <stdio.h>

int max(int a, int b) {
    if (a > b) {
        return a;
    } 
    else {
        return b;
    }
}


int knapsack(int weights[], int values[], int n, int capacity) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= capacity; w++) {
          
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } 
              
            else if (weights[i - 1] <= w) {
                int include = values[i - 1] + dp[i - 1][w - weights[i - 1]];
                int exclude = dp[i - 1][w];
                dp[i][w] = max(include, exclude);
            } 
              
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int capacity = 50;
    int n = sizeof(values) / sizeof(values[0]);

    int MaxValue = knapsack(weights, values, n, capacity);

    printf("Maximum value that can be carried: %d\n", MaxValue);

    return 0;
}

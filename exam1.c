#include <stdio.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int maxReach(int n, int cost[], int quantity[], int reach[], int budget) {
    int dp[budget + 1][n + 1];

    // Initialize dp array
    for (int i = 0; i <= budget; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
        }
    }

    // Calculate maximum reach for each budget value and platform
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= budget; j++) {
            dp[j][i] = dp[j][i - 1];
            for (int k = 1; k <= quantity[i - 1]; k++) {
                if (j - k * cost[i - 1] >= 0) {
                    dp[j][i] = MAX(dp[j][i], dp[j - k * cost[i - 1]][i - 1] + k * reach[i - 1]);
                }
            }
        }
    }

    return dp[budget][n];
}

int main() {
    int n;
    printf("Enter the number of advertising platforms: ");
    scanf("%d", &n);

    int cost[n], quantity[n], reach[n];
    printf("Enter the cost, quantity, and reach for each platform:\n");
    for (int i = 0; i < n; i++) {
        printf("Platform %d: ", i + 1);
        scanf("%d %d %d", &cost[i], &quantity[i], &reach[i]);
    }

    int budget;
    printf("Enter the maximum allocated budget: ");
    scanf("%d", &budget);

    int result = maxReach(n, cost, quantity, reach, budget);
    printf("Maximum reach/impact: %d\n", result);

    return 0;
}

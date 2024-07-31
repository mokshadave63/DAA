#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

typedef struct {
    int impact;
    int cost;
    int qty;
    int price;
} Item;

int knapsack(Item *items, int n, int maxWt) {
    int dp[n + 1][maxWt + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= maxWt; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (items[i].price <= j) {
                dp[i][j] = max(items[i].impact + dp[i - 1][j - items[i].price], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][maxWt];
}

int main() {
    int n;
    printf("Enter number of items: ");
    scanf("%d", &n);
    int maxWt;
    printf("Enter maximum budget: ");
    scanf("%d", &maxWt);

    Item *items = malloc((n + 1) * sizeof(Item));

    for (int i = 1; i <= n; i++) {
        printf("Enter impact, cost, and quantity for item %d: ", i);
        scanf("%d %d %d", &items[i].impact, &items[i].cost, &items[i].qty);
        items[i].price = items[i].cost * items[i].qty;
    }

    int result = knapsack(items, n, maxWt);
    printf("Maximum impact: %d\n", result);

    free(items);
    return 0;
}

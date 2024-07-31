#include <stdio.h>
#include <stdlib.h>

struct Price {
    int day;
    int price;
};

int compare(const void *a, const void *b) {
    struct Price *price1 = (struct Price *)a;
    struct Price *price2 = (struct Price *)b;
    return (price1->price - price2->price);
}

int main() {
    int n;
    printf("Enter the number of days: ");
    scanf("%d", &n);

    struct Price *prices = malloc(n * sizeof(struct Price));

    printf("Enter the prices for each day:\n");
    for (int i = 0; i < n; i++) {
        printf("Day %d: ", i + 1);
        scanf("%d", &prices[i].price);
        prices[i].day = i + 1;
    }

    qsort(prices, n, sizeof(struct Price), compare);

    int maxProfit = 0;
    for (int i = 0; i < n / 2; i++) {
        maxProfit += prices[n - 1 - i].price - prices[i].price;
    }

    printf("Maximum profit is: %d\n", maxProfit);

    free(prices);
    return 0;
}

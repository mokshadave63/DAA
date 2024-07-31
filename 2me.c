#include <stdio.h>
#include <stdlib.h>

typedef struct Asset {
    int id;
    float cost;
    int quantity;
    float returns;
} Asset;

int compare(const void *a, const void *b) {
    Asset *asset1 = (Asset *)a;
    Asset *asset2 = (Asset *)b;
    return (asset1->returns < asset2->returns) ? 1 : -1;
}

int main() {
    int n, budget, months;
    printf("Enter the number of assets: ");
    scanf("%d", &n);

    Asset *assets = malloc(n * sizeof(Asset));

    printf("Enter the details of assets:\n");
    for (int i = 0; i < n; i++) {
        printf("Asset %d: \n", i + 1);
        printf("Cost: ");
        scanf("%f", &assets[i].cost);
        printf("Quantity: ");
        scanf("%d", &assets[i].quantity);
        printf("Returns: ");
        scanf("%f", &assets[i].returns);
        assets[i].id = i + 1;
    }

    printf("Enter the maximum allocated budget: ");
    scanf("%d", &budget);
    printf("Enter the number of months: ");
    scanf("%d", &months);

    qsort(assets, n, sizeof(Asset), compare);

    float totalReturns = 0.0;
    int t = 0;
    for (int i = 0; i < n && budget > 0 && months > 0; i++) {
        if (assets[i].cost <= budget && assets[i].quantity > 0) {
            printf("Month %d: Invested in Asset %d\n", t + 1, assets[i].id);
            totalReturns += assets[i].returns;
            budget -= assets[i].cost;
            assets[i].quantity--;
            months--;
            t++;
        }
    }

    printf("Total expected returns after %d months: %.2f\n", t, totalReturns);

    free(assets);
    return 0;
}

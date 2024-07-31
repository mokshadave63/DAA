#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int id;
    int type;
    int cost;
    int quantity;
} Item;

int compare(const void* a, const void* b) {
    if (((Item*)a)->cost - ((Item*)b)->cost < 0) {
        return -1;
    } else if (((Item*)a)->cost - ((Item*)b)->cost > 0) {
        return 1;
    } else {
        return 0;
    }
}

int maxItems(Item* items, int n, int budget) {
    qsort(items, n, sizeof(Item), compare);

    int remainingBudget = budget;
    int totalQuantity = 0;

    for (int i = 0; i < n; i++) {
        if (remainingBudget >= items[i].cost) {
            int quantityToBuy = (remainingBudget / items[i].cost);
            if (quantityToBuy > items[i].quantity) {
                quantityToBuy = items[i].quantity;
            }
            remainingBudget -= quantityToBuy * items[i].cost;
            totalQuantity += quantityToBuy;
            printf("Item id: %d, Item type: %d\n", items[i].id, items[i].type);
        }
    }
    printf("Total quantity of items bought: %d\n", totalQuantity);
    return totalQuantity;
}

int main() {
    int n, budget;

    printf("Enter the total number of items(Food + Decorations): ");
    scanf("%d", &n);

    Item* items = (Item*)malloc(n * sizeof(Item));

    printf("Enter item details:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d (id, type, cost, quantity): ", i + 1);
        scanf("%d %d %d", &items[i].id, &items[i].type, &items[i].cost, &items[i].quantity);
    }

    printf("\nWhat is your budget?\n");
    scanf("%d", &budget);

    int totalQuantity = maxItems(items, n, budget);
    printf("Total quantity of items bought: %d\n", totalQuantity);

    free(items);
    return 0;
}

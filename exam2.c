#include <stdio.h>
#include <stdlib.h>

struct Item {
    int id;
    int quantity;
    int cost;
    int type;  // 0 for food, 1 for decoration
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item1->cost < item2->cost) ? -1 : 1;
}

int main() {
    int n, m, budget;
    printf("Enter the number of food items: ");
    scanf("%d", &n);
    printf("Enter the number of decoration items: ");
    scanf("%d", &m);

    struct Item *items = malloc((n + m) * sizeof(struct Item));

    printf("Enter the details of food items (quantity, cost):\n");
    for (int i = 0; i < n; i++) {
        items[i].id = i + 1;
        items[i].type = 0;
        printf("Food item %d: ", i + 1);
        scanf("%d %d", &items[i].quantity, &items[i].cost);
    }

    printf("Enter the details of decoration items (quantity, cost):\n");
    for (int i = 0; i < m; i++) {
        items[n + i].id = i + 1;
        items[n + i].type = 1;
        printf("Decoration item %d: ", i + 1);
        scanf("%d %d", &items[n + i].quantity, &items[n + i].cost);
    }

    printf("Enter the total budget: ");
    scanf("%d", &budget);

    qsort(items, n + m, sizeof(struct Item), compare);

    int totalQuantity = 0;
    printf("Items to buy:\n");
    for (int i = 0; i < n + m; i++) {
        if (items[i].cost <= budget) {
            int canBuy = items[i].type == 0 ? budget / items[i].cost : 1;
            if (canBuy >= items[i].quantity) {
                totalQuantity += items[i].quantity;
                budget -= items[i].quantity * items[i].cost;
                printf("Buy %d units of %s %d\n", items[i].quantity, items[i].type == 0 ? "food" : "decoration", items[i].id);
            } else {
                totalQuantity += canBuy;
                budget -= canBuy * items[i].cost;
                printf("Buy %d units of %s %d\n", canBuy, items[i].type == 0 ? "food" : "decoration", items[i].id);
            }
        }
    }

    printf("Total quantity of items bought: %d\n", totalQuantity);

    free(items);
    return 0;
}

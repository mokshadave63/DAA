#include<stdio.h>

typedef struct Item {
    int type; // 0 for food, 1 for decoration
    int id;
    int quantity;
    int cost;
    double rate; // Only applicable for decoration items
} Item;

void enterItems(Item items[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter the type (0 for food, 1 for decoration), quantity, cost, and rate (0 if food) of item %d: ", i + 1);
        scanf("%d %d %d %lf", &items[i].type, &items[i].quantity, &items[i].cost, &items[i].rate);
        items[i].id = i + 1;
    }
}

void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Item items[], int L, int H) {
    double pivot = (items[H].type == 0) ? items[H].cost : (items[H].cost * items[H].rate);
    int j = L - 1;
    for (int i = L; i < H; i++) {
        double item_cost = (items[i].type == 0) ? items[i].cost : (items[i].cost * items[i].rate);
        if (item_cost > pivot) {
            j++;
            swap(&items[i], &items[j]);
        }
    }
    j++;
    swap(&items[H], &items[j]);
    return j;
}

void quick(Item items[], int L, int H) {
    if (L < H) {
        int i = partition(items, L, H);
        quick(items, L, i - 1);
        quick(items, i + 1, H);
    }
}

void printItems(Item items[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Item %d: Type: %s, Quantity: %d, Cost: %d, Rate: %.2lf\n", items[i].id, (items[i].type == 0) ? "Food" : "Decoration", items[i].quantity, items[i].cost, items[i].rate);
    }
}

void maximizeItems(Item items[], int n, int budget) {
    quick(items, 0, n - 1);
    printf("Sorted Items:\n");
    printItems(items, n);

    int totalItems = 0;
    int totalCost = 0;
    for (int i = 0; i < n && totalCost + items[i].cost <= budget; i++) {
        totalCost += items[i].cost;
        totalItems += items[i].quantity;
        printf("Buying item %d (%s) with cost %d\n", items[i].id, (items[i].type == 0) ? "Food" : "Decoration", items[i].cost);
    }

    printf("\nTotal Items: %d\nTotal Cost: %d\n", totalItems, totalCost);
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item items[n];
    enterItems(items, n);

    int budget;
    printf("Enter the total budget: ");
    scanf("%d", &budget);

    maximizeItems(items, n, budget);

    return 0;
}

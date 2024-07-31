#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int quantity;
    double costRate;
} Item;

void swap(Item* a, Item* b) {
    Item temp = *a;
    *a = *b;
    *b = temp;
}

int partition(Item arr[], int low, int high) {
    double pivot = arr[high].costRate;
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j].costRate >= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(Item arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void maximizeItems(Item items[], int n, int budget) {
    quickSort(items, 0, n - 1);

    int totalQuantity = 0;
    double totalCost = 0;

    printf("Items selected:\n");
    for (int i = 0; i < n && totalCost <= budget; i++) {
        if (items[i].costRate <= budget - totalCost) {
            printf("Item %d: Quantity %d, Cost/Rate %.2lf\n", i + 1, items[i].quantity, items[i].costRate);
            totalQuantity += items[i].quantity;
            totalCost += items[i].costRate;
        }
    }

    printf("Total quantity: %d\n", totalQuantity);
}

int main() {
    int n, budget;
    printf("Enter the number of items (food + decoration): ");
    scanf("%d", &n);
    printf("Enter the total budget: ");
    scanf("%d", &budget);

    Item items[n];

    printf("Enter items (quantity, cost/rate):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %lf", &items[i].quantity, &items[i].costRate);
    }

    maximizeItems(items, n, budget);

    return 0;
}

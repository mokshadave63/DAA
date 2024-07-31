#include <stdio.h>
#include <stdlib.h>

struct Item {
    int id;
    float growth_rate;
};

int compare(const void *a, const void *b) {
    struct Item *item1 = (struct Item *)a;
    struct Item *item2 = (struct Item *)b;
    return (item1->growth_rate < item2->growth_rate) ? -1 : 1;
}

int main() {
    int n;
    printf("Enter the number of licenses: ");
    scanf("%d", &n);

    struct Item *items = malloc(n * sizeof(struct Item));

    printf("Enter the growth rates of licenses:\n");
    for (int i = 0; i < n; i++) {
        printf("Growth rate of license %d: ", i + 1);
        scanf("%f", &items[i].growth_rate);
        items[i].id = i + 1;
    }

    qsort(items, n, sizeof(struct Item), compare);

    printf("Order to buy licenses:\n");
    for (int i = 0; i < n; i++) {
        printf("Buy license %d\n", items[i].id);
    }

    free(items);
    return 0;
}

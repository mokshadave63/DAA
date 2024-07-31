#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double rate;
    int name;
} License;

int compare(const void *a, const void *b) {
    return (((License*)b)->rate - ((License*)a)->rate) > 0 ? 1 : ((((License*)b)->rate - ((License*)a)->rate) == 0) ? 0 : -1;
}

double computeOrder(int n, License *licenses) {
    qsort(licenses, n, sizeof(License), compare);

    double cost = 0;
    for(int i = 0; i < n; i++) {
        cost += licenses[i].rate * (i+1) * 100;
    }

    return cost;
}

void main() {
    printf("Krisha Soni  22BCP391\n");
    int n;
    printf("Enter number of licenses: ");
    scanf("%d", &n);

    License licenses[n];

    printf("Enter rates of growth of each license:\n");
    for(int i = 0; i < n; i++) {
        printf("License %d: ", i+1);
        scanf("%lf", &licenses[i].rate);
        licenses[i].name = i+1;
    }

    double cost = computeOrder(n, licenses);

    printf("\n\nThe optimal order to buy licenses to minimise cost is: ");
    for(int i = 0; i < n; i++) printf("%d ", licenses[i].name);
    printf("\nThe total cost is: %.2lf", cost);
}
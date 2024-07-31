#include<stdio.h>

typedef struct List{
    int asset;
    int cost;
    int quantity;
    double returns;
}List;

void enterList(List list[], int n){
    for(int i = 0; i < n; i++){
        printf("Enter the asset number, cost, quantity and returns: ");
        scanf("%d %d %d %lf", &list[i].asset, &list[i].cost, &list[i].quantity, &list[i].returns);
    }
}

void swap(List* a, List* b){
    List temp = *a;
    *a = *b;
    *b = temp;
}

int partition(List list[], int L, int H){
    double pivot = list[H].cost*list[H].returns;
    int j = L-1;
    for(int i = L; i < H; i++){
        if(list[i].cost*list[i].returns > pivot){
            j++;
            swap(&list[i], &list[j]);
        }
    }
    j++;
    swap(&list[H], &list[j]);
    return j;
}

void quick(List list[], int L, int H){
    if(L < H){
        int i = partition(list, L, H);
        quick(list, L, i-1);
        quick(list, i+1, H);
    }
}

void printList(List list[], int n){
    for(int i = 0; i < n; i++){
        printf("%dth: %d\n", i, list[i].asset);
    }
}

void managePortfolio(List list[], int n, int capital, int months){
    quick(list, 0, n-1);
    printList(list, n);
    int totalReturns = 0;
    int t = 0;
    for(int i = 0; i < n; i++){
        while(list[i].cost <= capital && list[i].quantity != 0 && months != 0){
            printf("%dth month: %d invested in %d\n", t, list[i].cost, list[i].asset);
            list[i].quantity--;
            capital -= list[i].cost;
            t++;
            printf("Remaining quantity of %d asset is: %d\n", list[i].asset, list[i].quantity);
            printf("Remaining capital is: %d\n", capital);
        }
    }
}

void main(){
    int n, capital, months;
    printf("Enter the number of stocks: ");
    scanf("%d", &n);
    printf("Enter the total capital: ");
    scanf("%d", &capital);
    printf("Enter the total number of months: ");
    scanf("%d", &months);
    List list[n];
    enterList(list, n);
    printList(list, n);
    managePortfolio(list, n, capital, months);
}
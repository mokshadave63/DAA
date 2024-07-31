#include <stdio.h>

int findmin(int arr[], int start, int n) {
    int min = 999999;
    int index = start;
    for (int i = start; i < n; i++) {
        if (arr[i] >= 0 && arr[i] < min) {
            min = arr[i];
            index = i;
        }
    }
    return index;
}

int findmax(int arr[], int start, int end) {
    int max = -99999;
    int index = start;
    for (int i = start; i < end; i++) {
        if (arr[i] >= 0 && arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

int maxProfit(int arr[], int n) {
    int profit = 0;
    for (int i = 0; i < n / 2; i++) {
        int buy = findmin(arr, 0, n);
        int sell = findmax(arr, buy + 1, n);
        profit = profit + (arr[sell] - arr[buy]);
        printf("%d(%d) - ", arr[sell], sell);
        printf("%d(%d) = ", arr[buy], buy);
        printf("%d \n", arr[sell] - arr[buy]);
        arr[buy] = -1;
        arr[sell] = -1;
    }
    return profit;
}

int main() {
    int price[10] = {10, 15, 7, 20, 5, 25, 30, 12, 18, 22};
    int n = 10;
    int profit = maxProfit(price, n);
    printf("%d", profit);
    return 0;
}

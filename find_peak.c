#include <stdio.h>

int findPeak(int n, int *arr) {
    if(n == 1) return 0;
    if(arr[0] > arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int lo = 1, hi = n-2;

    while(lo <= hi) {
        int mid = (lo+hi)/2;

        if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) return mid;

        // If we are in the left half
        if (arr[mid] > arr[mid-1]) lo = mid + 1;

        // If we are in the right half
        // Or, arr[mid] is a minima:
        else hi = mid - 1;
    }

    return -1;
}

void main() {
    printf("Krisha Soni  22BCP391\n");
    int n;
    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of the array:\n");
    for(int i = 0; i < n; i++) {
        printf("arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    printf("Array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    int peakIdx = findPeak(n, arr);
    printf("\n\nPeak element %d is at index %d", arr[peakIdx], peakIdx);
}
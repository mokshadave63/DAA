#include<stdio.h>
 
int partition(int arr[], int left, int right) {
    int pivot = arr[left];
    int pivotIndex = right; 
 
    for(int i = right; i > left; i--) {
        if(arr[i] > pivot) {
            int temp = arr[pivotIndex];
            arr[pivotIndex] = arr[i];
            arr[i] = temp;
            pivotIndex--;
        }
    }
    int temp = arr[pivotIndex];
    arr[pivotIndex] = arr[left];
    arr[left] = temp;
 
    return pivotIndex;
}
 
void quickSort(int arr[], int left, int right) {
    if(left < right) {
        int partitionIndex = partition(arr, left, right);
 
        quickSort(arr, left, partitionIndex-1);
        quickSort(arr, partitionIndex+1, right);
    }
    return;
}
 
void main() {
    printf("Moksha Dave\n");
    printf("Enter size of array: ");
 
    int n;
    scanf("%d", &n);
    int arr[n-1];
 
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
 
    quickSort(arr, 0, n-1);
 
    printf("\nSorted array:  ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return;
}

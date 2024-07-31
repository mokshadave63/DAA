#include<stdio.h>
 
void merger(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid-left+1;
    int n2 = right-mid;
 
    int arr1[n1], arr2[n2];
 
    for(i = 0; i < n1; i++) {
        arr1[i] = arr[left+i];
    }
    for(i = 0; i < n2; i++) {
        arr2[i] = arr[mid+1+i];
    }
 
    i = 0;
    j = 0;
    k = left;
    while(i < n1 && j < n2) {
        if(arr1[i] < arr2[j]) {
            arr[k] = arr1[i++];
        }
        else {
            arr[k] = arr2[j++];
        }
        k++;
    }
 
    while(i < n1) {
        arr[k++] = arr1[i++];
    }
    while(j < n2) {
        arr[k++] = arr2[j++];
    }
 
    return;
}
 
void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int mid = (left+right)/2;
 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
 
        merger(arr, left, mid, right);
    }
    return;
}
 
void main() {
    printf("Moksha Dave 22BCP366\n");
    printf("Enter size of array: ");
 
    int n;
    scanf("%d", &n);
    int arr[n];
 
    printf("Enter the elements of the array:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
 
    mergeSort(arr, 0, n-1);
 
    printf("\nSorted array:  ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return;
}
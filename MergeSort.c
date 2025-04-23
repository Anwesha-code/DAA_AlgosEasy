#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n = mid - left + 1;
    int m = right - mid;

    int Left[n], Right[m];

    for(i = 0; i< n; i++){
        Left[i] = arr[left + i];
    }
  
    for(j = 0; j< m; j++){
        Right[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while(i< n && j< m) {
        if(Left[i] <= Right[j]){
            arr[k++] = Left[i++];
        }
        else{
            arr[k++] = Right[j++];
        }
    }

    while(i< n){
        arr[k++] = Left[i++];
    }
    while(j< m){
        arr[k++] = Right[j++];
    }
}

void MergeSort(int arr[], int left, int right) {
    if(left< right) {
        int mid = left + (right - left) / 2;

        MergeSort(arr, left, mid);
        MergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for(int i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }

    MergeSort(arr, 0, n - 1);

    printf("\nSorted array:   ");
    for(int i = 0; i< n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

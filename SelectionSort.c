#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;
    for(i =0 ; i< n-1; i++){           
        minIndex = i;
        for(j= i+1; j<n; j++){                   
            if(arr[j]< arr[minIndex]){ 
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex]= arr[i];            
        arr[i]= temp;
    }
}


void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {78, 91, 45, 12, 56, 985, 32, 123, 65, 50};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}

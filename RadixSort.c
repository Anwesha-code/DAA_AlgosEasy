#include <stdio.h>

int getMax(int arr[], int n) {
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n, int place) {
    int output[n];
    int count[10] = {0};

    for(int i = 0; i < n; i++){
        count[(arr[i] / place) % 10]++;
    }

    for(int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }

    for(int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / place) % 10;
        output[--count[digit]] = arr[i];
    }

    for(int i = 0; i < n; i++){
        arr[i] = output[i];
    }
}

void radixSort(int arr[], int n) {
    int max = getMax(arr, n);

    for(int place = 1; max / place > 0; place *= 10){
        countingSort(arr, n, place);
    }
}

int main() {
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    radixSort(arr, n);

    printf("\nSorted array:   ");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}

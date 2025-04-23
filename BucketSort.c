#include <stdio.h>
#include <stdlib.h>

#define BUCKETS 10

void selectionSort(float arr[], int n) {
    for(int i = 0; i < n - 1; i++) {
        int minIdx = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        float temp = arr[i];
        arr[i] = arr[minIdx];
        arr[minIdx] = temp;
    }
}

void bucketSort(float arr[], int n) {
    float *buckets[BUCKETS];
    int bucketCount[BUCKETS] = {0};

    for(int i = 0; i < BUCKETS; i++)
        buckets[i] = (float*)malloc(n * sizeof(float));

    for(int i = 0; i < n; i++) {
        int index = arr[i] * BUCKETS;
        buckets[index][bucketCount[index]++] = arr[i];
    }

    for(int i = 0; i < BUCKETS; i++){
        selectionSort(buckets[i], bucketCount[i]);
    }

    int k = 0;
    for(int i = 0; i < BUCKETS; i++) {
        for(int j = 0; j < bucketCount[i]; j++) {
            arr[k++] = buckets[i][j];
        }
        free(buckets[i]);
    }
}

int main() {
    float arr[] = {0.42, 0.32, 0.23, 0.52, 0.25, 0.47, 0.51};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for(int i = 0; i < n; i++){
        printf("%.2f ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array:   ");
    for(int i = 0; i < n; i++){
        printf("%.2f ", arr[i]);
    }

    return 0;
}

#include <stdio.h>

struct Item {           
    int value;
    int weight;
    float ratio;            
};

void sort(struct Item items[], int n) {       
    for (int i = 0; i< n-1; i++) {
        for (int j = i+1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];            
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
}

float FractionalKnapsack(int capacity, struct Item items[], int n) {            
    sort(items, n);       

    int currentWeight = 0;                  
    float TotalValue = 0.00;                        

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight<= capacity) {
            currentWeight = currentWeight + items[i].weight;
            TotalValue = TotalValue + items[i].value;
        }
        else {
            int remainingWeight = capacity - currentWeight;
            TotalValue = TotalValue + items[i].value * ((float)remainingWeight / items[i].weight);
            break; 
        }
    }
    return TotalValue;
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    struct Item items[n];                

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight for item %d: ", i + 1);
        scanf("%d %d", &items[i].value, &items[i].weight);

        items[i].ratio = (float)items[i].value/ items[i].weight;         
    }

    float maxValue = FractionalKnapsack(capacity, items, n);              

    printf("Maximum value in the knapsack = %.2f\n", maxValue);

    return 0;
}

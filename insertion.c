#include<stdio.h>

int main() {
    int numbers[100], key, i, j, n;
    
    printf("Enter the dimension of the array: ");
    scanf("%d", &n);
    
    for(i = 0; i < n; i++) {
        printf("Enter numbers[%d]: ", i);
        scanf("%d", &numbers[i]);
    }
    
    for(j = 1; j < n; j++) {
        key = numbers[j];
        i = j - 1;
        
        while (i >= 0 && numbers[i] > key) {
            numbers[i + 1] = numbers[i];
            i = i - 1;
        }
        numbers[i + 1] = key;
    }
    
    for(i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    return 0;
}
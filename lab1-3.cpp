#include <stdio.h>
#include <stdlib.h>
#include "dslab1.h"
int linearSearch(int arr[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    return -1;
}
int binarySearch(int arr[], int n, int key) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        }
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    int choice, n, key;
    int binaryResult;
    int linearResult;
    
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the elements of the array: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    do {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice (1/2/3): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the key to search: ");
                scanf("%d", &key);
                linearResult = linearSearch(arr, n, key);
                if (linearResult != -1) {
                    printf("Key found at index %d (0-based).\n", linearResult);
                } else {
                    printf("Key not found in the array.\n");
                }
                break;

            case 2:
               
                printf("Array sorted for Binary Search.\n");
                printf("Enter the key to search: ");
                scanf("%d", &key);
                bubblesort(arr,n);
                binaryResult = binarySearch(arr, n, key);
                if (binaryResult != -1) {
                    printf("Key found at index %d (0-based).\n", binaryResult);
                } else {
                    printf("Key not found in the array.\n");
                }
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// Function prototype
int playersleft(int arr[], int a[], int ngrps);

int main() {
    int testcases, npos, ngrps;
    
    // Prompt user to enter number of test cases
    printf("Enter number of test cases: ");
    scanf("%d", &testcases);
    
    // Loop through each test case
    for (int i = 0; i < testcases; i++) {
        
        // Prompt user to enter number of positions
        printf("Enter number of positions: ");
        scanf("%d", &npos);
        int arr[npos]; // Array to store positions
        
        // Prompt user to enter number of groups
        printf("Enter number of groups: ");
        scanf("%d", &ngrps);
        int a[ngrps]; // Array to store number of players in each group
        
        // Input positions
        for (int i = 0; i < npos; i++) {
            printf("Enter position %d: ", i + 1);
            scanf("%d", &arr[i]);
        }
        
        // Input number of players in each group
        for (int i = 0; i < ngrps; i++) {
            printf("Enter number of players in group %d: ", i + 1);
            scanf("%d", &a[i]);
        }
    
        // Call function to determine number of winners
        playersleft(arr, a, ngrps);
    }
}

// Function to determine the number of winners in each group
int playersleft(int arr[], int a[], int ngrps) {
    for (int i = 0; i < ngrps; i++) {
        // Check if number of players in group is greater than or equal to the first position value
        if (a[i] >= arr[0]) {
            printf("Number of winners are: %d\n", arr[0] - 1);
        } else {
            printf("Number of winners are: %d\n", a[i]);
        }
    }
}
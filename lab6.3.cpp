#include<stdio.h>
#include<stdlib.h>
#define MAX 5   // Define maximum stack size

// Stack class to represent a stack data structure
class stack {
private:
    int stackarr[MAX];  // Array to hold stack elements
    int top;            // Index of the top element in the stack

public:
    // Constructor to initialize stack
    stack() {
        top = -1;   // Stack is initially empty
    }

    // Function declarations
    int is_Full();   // Check if stack is full
    int is_Empty();  // Check if stack is empty
    void push(int data);  // Add element to stack
    int pop();            // Remove and return top element
    int peek();            // Get top element without removing
    void print();          // Print all elements
};

// Function to check if stack is full
int stack::is_Full() {
    if (top == MAX - 1) {
        return 1;   // Stack is full
    } else {
        return 0;   // Stack is not full
    }
}

// Function to check if stack is empty
int stack::is_Empty() {
    if (top == -1) {
        return 1;   // Stack is empty
    } else {
        return 0;   // Stack has elements
    }
}

// Push function to add an element to the stack
void stack::push(int data) {
    if (is_Full()) {
        // Stack overflow case - cannot add more elements
        printf("Error: Stack Overflow! Cannot push %d\n", data);
        return;
    } else {
        top = top + 1;               // Increment top index
        stackarr[top] = data;         // Place new element at the top
        printf("%d is pushed into the stack\n", data);
    }
}

// Pop function to remove and return the top element from stack
int stack::pop() {
    if (top == -1) {
        // Stack underflow case - cannot remove from empty stack
        printf("Error! Stack Underflow! Cannot pop.\n");
        exit(1);   // Exit program to indicate fatal error
    } else {
        int value = stackarr[top];   // Get the top element
        top = top - 1;                // Move top index down
        return value;                 // Return the popped element
    }
}

// Function to print all elements from top to bottom
void stack::print() {
    if (is_Empty()) {
        // Stack is empty - nothing to print
        printf("Stack empty\n");
        return;
    }
    printf("Stack elements (top to bottom): ");
    for (int i = top; i >= 0; i--) {
        printf("%d\t", stackarr[i]);
    }
    printf("\n");
}

// Function to return the top element without removing it
int stack::peek() {
    if (is_Empty()) {
        // Cannot peek if stack is empty
        printf("Error: Stack Underflow! No top element\n");
        exit(1);   // Exit program to indicate fatal error
    } else {
        return stackarr[top];  // Return the top element
    }
}

// Main function - Menu-driven program for stack operations
int main() {
    int choice;   // User menu choice
    int data;     // Data to be pushed/popped
    stack a;      // Stack object

    do {
        // Display menu options
        printf("\n==== Stack Menu ====\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Print\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            case 1:
                // Push operation
                printf("Enter element to be pushed: ");
                scanf("%d", &data);
                a.push(data);
                break;

            case 2:
                // Pop operation
                data = a.pop();
                printf("The popped element is %d\n", data);
                break;

            case 3:
                // Peek operation
                printf("The top element: %d\n", a.peek());
                break;

            case 4:
                // Print stack elements
                printf("The elements of stack array are: ");
                a.print();
                break;

            case 5:
                // Exit program
                printf("Exiting program...\n");
                return 0;

            default:
                // Invalid choice handling
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 5);  // Loop until user chooses to exit

    return 0;   // End of program
}



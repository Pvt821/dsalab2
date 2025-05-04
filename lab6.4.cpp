// """LINKED LIST -STACK"""
// why linked list representation?
// ?use inkedlist representation when size of stack is not know in advance
// in array top is last element pushed but in linked list it is the beginning element
// push fn-insert node at beginning,pop fn-delete frst node
// we prefer insert and deleteing node at beginning only not at an end because of timecomplexiy is o(1).
// stack underflow-when top=null overflow when top=max-1

#include<stdio.h>
#include<stdlib.h>

// Class representing a Stack implemented using Linked List
class stack {
    // Node structure to represent each element in the stack
    struct node {
        int data;              // Data part
        struct node* next;      // Pointer to the next node
    } *top = NULL;               // Pointer to the top of stack

    // Function to check if stack is empty
    int is_empty() {
        if (top == NULL) {
            return 1;  // Stack is empty
        } else {
            return 0;  // Stack is not empty
        }
    }

public:
    // Function to push (insert) an element into the stack
    void push(int value) {
        struct node* newnode = (node*)malloc(sizeof(struct node));  // Allocate memory for new node

        if (newnode == NULL) {
            // Memory allocation failed - stack overflow
            printf("Stack Overflow\n");
            exit(1);
        }

        newnode->data = value;    // Assign data
        newnode->next = top;      // Link new node to the current top
        top = newnode;            // Update top to new node

        printf("%d is inserted at beginning\n", value);
    }

    // Function to pop (remove) the top element from the stack
    int pop() {
        if (is_empty()) {
            // Stack underflow case - cannot pop from empty stack
            printf("Stack Underflow\n");
            exit(1);
        }

        struct node* temp = top;  // Temporary pointer to hold the top node
        int value = temp->data;   // Get data of top node

        top = top->next;          // Move top to next node
        free(temp);                // Free memory of removed node
        temp = NULL;                // Avoid dangling pointer

        return value;              // Return popped value
    }

    // Function to return the top element without removing it (peek)
    int peek() {
        if (is_empty()) {
            // Cannot peek from an empty stack
            printf("The stack is underflow\n");
            exit(1);
        }
        return top->data;  // Return data of top node
    }

    // Function to print all stack elements from top to bottom
    void print() {
        if (is_empty()) {
            // Stack is empty - nothing to print
            printf("Stack Underflow\n");
            exit(1);
        }

        struct node* temp = top;  // Start from top

        while (temp) {
            printf("%d\n", temp->data);  // Print current node data
            temp = temp->next;           // Move to next node
        }
    }
};

// Main function - Menu driven program for stack operations
int main() {
    stack a;  // Stack object
    int choice, value, res;

    do {
        // Display menu options
        printf("\n=== Stack Menu ===\n");
        printf("1. Push\n2. Pop\n3. Peek\n4. Print\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Process user choice
        switch (choice) {
            case 1:
                // Push operation
                printf("Enter the element to be pushed: ");
                scanf("%d", &value);
                a.push(value);
                break;

            case 2:
                // Pop operation
                res = a.pop();  // Corrected the missing object call
                printf("The deleted element is %d\n", res);
                break;

            case 3:
                // Peek operation
                printf("The topmost element is %d\n", a.peek());
                break;

            case 4:
                // Print stack elements
                printf("The elements in the stack are:\n");
                a.print();
                break;

            case 5:
                // Exit the program
                printf("Exiting the program....\n");
                return 0;

            default:
                // Invalid input case
                printf("Invalid Choice\n");
        }

    } while (choice != 5);  // Continue until user chooses to exit

    return 0;
}




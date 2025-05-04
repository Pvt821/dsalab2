#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Stack class definition
class Stack {
    struct Node {
        char data;
        Node* next;
    };
    Node* top;

public:
    // Constructor to initialize stack
    Stack() {
        top = NULL;
    }

    void push(char value);  // Push character onto stack
    char pop();  // Pop character from stack
    void display();  // Display the final string
};

// Define a global stack object
Stack obj;

// Function to push a character onto the stack
void Stack::push(char value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

// Function to pop a character from the stack
char Stack::pop() {
    if (top == NULL) {  // If stack is empty, return null character
        return '\0';
    }
    Node* temp = top;
    char removed = top->data;
    top = top->next;
    free(temp);
    return removed;
}

// Function to display the processed string
void Stack::display() {
    if (top == NULL) {
        printf("The final string is empty.\n");
        return;
    }

    // Store characters in a temporary array for correct order
    char result[100];
    int index = 0;
    Node* temp = top;

    while (temp != NULL) {
        result[index++] = temp->data;
        temp = temp->next;
    }

    // Print characters in reverse order (since stack is LIFO)
    printf("Output: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%c", result[i]);
    }
    printf("\n");
}

// Function to process the input string
void processString(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '+') {
            obj.pop();  // Use global stack object
        } else {
            obj.push(str[i]);  // Use global stack object
        }
    }
}

// Main function to take input and process the string
int main() {
    char input[100];
    printf("Enter the input string: ");
    scanf("%s", input);

    processString(input);  // Process input string
    obj.display();  // Display the final result using global stack

    return 0;
}

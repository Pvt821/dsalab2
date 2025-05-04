#include <cstdio>
#include <iostream>
using namespace std;

#define max 100  // Maximum size of the stack

// Stack class to check for balanced parentheses
class stack {
    char stackarr[max];  // Stack array to hold characters
    int top;              // Top pointer to track stack position

public:
    // Constructor to initialize stack
    stack() {
        top = -1;
    }

    // Function to check if given string has balanced parentheses
    bool isbalance(string);

    // Function to push a character onto the stack
    bool push(char);

    // Function to pop a character from the stack
    bool pop();
};

// Main function with menu-driven interface
int main() {
    stack obj;  // Stack object
    int choice, result, value;
    string str;

    // Menu loop to perform stack operations
    do {
        cout << "\n==== Menu Card ====\n";
        cout << "Enter 1: To check whether the string is balanced" << endl;
        cout << "Enter 2: To End the program\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                // Check if string is balanced
                cout << "Enter the string with parentheses: ";
                cin >> str;
                if (obj.isbalance(str)) {
                    cout << "The given input is balanced.\n";
                } else {
                    cout << "The given input is NOT balanced.\n";
                }
                break;

            case 2:
                // Exit the program
                cout << "Program ended\n" << endl;
                break;

            default:
                // Invalid choice handling
                cout << "Invalid choice" << endl;
                cout << "Enter a choice between 1 to 2" << endl;
                break;
        }
    } while (choice != 2);  // Loop until user chooses to exit

    return 0;
}

// Function to check if a string of parentheses is balanced
bool stack::isbalance(string str) {
    int i = 0;

    // Iterate through each character in the string
    while (str[i] != '\0') {
        if (str[i] == '(') {
            // Push opening parenthesis onto the stack
            if (!push(str[i])) {
                return false;  // Stack overflow
            }
        } else if (str[i] == ')') {
            // If stack is empty when closing parenthesis is found, it's unbalanced
            if (top < 0) {
                return false;
            }
            pop();  // Pop matching opening parenthesis
        }
        i++;
    }

    // Stack should be empty if balanced (all open have matching close)
    return (top == -1);
}

// Function to push a character onto the stack
bool stack::push(char ch) {
    if (top == max - 1) {
        // Stack overflow - cannot add more elements
        cout << "Error: Stack overflow! Cannot add " << ch << " to the stack.\n";
        return false;
    } else {
        // Add character to stack
        top++;
        stackarr[top] = ch;
    }
    return true;
}

// Function to pop a character from the stack
bool stack::pop() {
    if (top == -1) {
        // Stack underflow - cannot remove from empty stack
        cout << "Error: Stack underflow! Nothing to pop.\n";
        return false;
    }
    top--;  // Remove top character
    return true;
}

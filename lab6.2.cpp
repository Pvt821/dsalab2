#include <cstdio>
#include <iostream>
#include <cmath>
#include "stack.h"
using namespace std;

// Global variables to hold infix and postfix expressions
string infix, postfix;

// Function prototypes
int getinfix();             // Function to input infix expression from the user
void convertinfix();        // Function to convert infix to postfix
int precedence(char symbol); // Function to get precedence of operators
int evaluatePostfix();      // Function to evaluate the postfix expression

// Main function with menu-driven interface
int main() {
    int choice, result;

    do {
        // Displaying menu to the user
        cout << "\n==== Menu Card ====\n";
        cout << "Enter 1: To Input Infix Expression" << endl;
        cout << "Enter 2: To Convert Infix to Postfix" << endl;
        cout << "Enter 3: To Evaluate the Postfix Expression" << endl;
        cout << "Enter 4: Exit the Program\n" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch case to handle user choice
        switch (choice) {
            case 1:
                getinfix();
                break;

            case 2:
                convertinfix();
                cout << "Postfix Expression: " << postfix << endl;
                break;

            case 3:
                result = evaluatePostfix();
                cout << "Evaluation Result: " << result << endl;
                break;

            case 4:
                cout << "Program ended\n" << endl;
                break;

            default:
                cout << "Invalid choice" << endl;
                cout << "Enter a valid choice between 1 to 4" << endl;
        }
    } while (choice != 4);  // Loop until the user chooses to exit

    return 0;
}

// Function to take infix expression input from user
int getinfix() {
    cout << "Enter the Infix expression: ";
    cin >> infix;
    return 0;
}

// Function to convert infix expression to postfix expression using stack
void convertinfix() {
    stack s;  // Stack object for operator handling
    postfix = "";  // Initialize postfix string to empty

    for (int i = 0; i < infix.length(); i++) {
        char symbol = infix[i];

        switch (symbol) {
            case '(':
                s.push(symbol);  // Push opening parenthesis onto stack
                break;

            case ')':
                // Pop all operators until matching '(' is found
                while (!s.isempty() && s.peek() != '(') {
                    postfix += s.pop();
                }
                if (!s.isempty()) s.pop();  // Pop the '(' itself
                break;

            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                // Pop operators of higher or equal precedence
                while (!s.isempty() && precedence(s.peek()) >= precedence(symbol)) {
                    postfix += s.pop();
                }
                s.push(symbol);  // Push current operator onto stack
                break;

            default:
                // If operand (number/variable), directly add to postfix
                postfix += symbol;
                break;
        }
    }

    // Pop remaining operators from the stack
    while (!s.isempty()) {
        postfix += s.pop();
    }
}

// Function to evaluate the postfix expression using stack
int evaluatePostfix() {
    stack s;  // Stack to hold operands

    for (int i = 0; i < postfix.length(); i++) {
        if (isdigit(postfix[i])) {
            // Convert character to integer and push onto stack
            s.push(postfix[i] - '0');
        } else {
            // Operator encountered - pop two operands
            if (s.isempty()) {
                cout << "Error: Invalid postfix expression!\n";
                return -1;
            }
            int a = s.pop();

            if (s.isempty()) {
                cout << "Error: Invalid postfix expression!\n";
                return -1;
            }
            int b = s.pop();

            // Perform operation based on operator type
            switch (postfix[i]) {
                case '+':
                    s.push(b + a);
                    break;
                case '-':
                    s.push(b - a);
                    break;
                case '*':
                    s.push(b * a);
                    break;
                case '/':
                    if (a == 0) {
                        cout << "Error: Division by zero!\n";
                        return -1;
                    }
                    s.push(b / a);
                    break;
                case '^':
                    s.push(pow(b, a));  // Power function for '^'
                    break;
                default:
                    cout << "Error: Invalid operator encountered!\n";
                    return -1;
            }
        }
    }

    // Final result should be the only element left in the stack
    if (!s.isempty()) {
        return s.pop();
    } else {
        cout << "Error: Malformed expression!\n";
        return -1;
    }
}

// Function to return precedence of operators
int precedence(char symbol) {
    switch (symbol) {
        case '^':
            return 3;  // Highest precedence
        case '*':
        case '/':
            return 2;
        case '+':
        case '-':
            return 1;  // Lowest precedence
        default:
            return 0;  // For non-operators
    }
}

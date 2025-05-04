#include<stdio.h>
#include<stdlib.h>

#define max 5  // Define the maximum size of the queue

// Queue class definition
class queue {
    int front, rear;  // Indices to track front and rear of the queue
    int arr[max];  // Array to store queue elements

public:
    // Constructor to initialize queue
    queue() {
        rear = -1;
        front = -1;
    }

    void enqueue(int value);  // Function to insert an element
    void dequeue();  // Function to remove an element
    void peek();  // Function to get the front element
    void display();  // Function to display queue elements
};

// Function to insert an element into the queue
void queue::enqueue(int value) {
    if (rear == max - 1) {  // Check if the queue is full
        printf("Overflow\n");
    }


    else if (rear == -1 && front == -1) {  // If queue is empty, initialize front and rear
        rear++;
        front++;
        arr[rear] = value;
    }


    else {  // Otherwise, insert at rear position
        rear++;
        arr[rear] = value;
    }
}

// Function to remove an element from the queue
void queue::dequeue() {
    if (front == -1 || rear == -1) {  // Check if the queue is empty
        printf("The queue is empty\n");
    } else {
        printf("The element dequeued is %d\n", arr[front]);  // Display the removed element
        if (front == rear) {  // If last element is dequeued, reset queue
            front = -1;
            rear = -1;
        } else {
            front = front + 1;  // Move front pointer forward
        }
    }
}

// Function to display all elements in the queue
void queue::display() {
    if (front == -1 && rear == -1) {  // Check if queue is empty
        printf("The queue is empty\n");
    }
    else {
        for (int i = front; i <= rear; i++) {  // Iterate through queue elements
            printf("%d\t", arr[i]);
        }
        printf("\n");
    }
}

// Function to get the front element without removing it
void queue::peek() {
    if (rear == -1 && front == -1) {  // Check if queue is empty
        printf("The queue is empty\n");
    }
    else {
        printf("The peek element is %d\n", arr[front]);  // Print front element
    }
}

// Main function to run the menu-driven queue operations
int main() {
    queue q;  // Create queue object
    int choice, value;

    do {
        // Display menu options
        printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Validate user input
        if (choice < 1 || choice > 5) {  
            printf("Enter a valid choice\n");
            continue;  // Skip the invalid input
        }

        // Perform operations based on user choice
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &value);
                q.enqueue(value);  // Call enqueue function
                break;
            case 2:
                q.dequeue();  // Call dequeue function
                break;
            case 3:
                q.peek();  // Call peek function
                break;
            case 4:
                q.display();  // Call display function
                break;
            case 5:
                printf("Exiting the program...\n");  // Exit message
                return 0;
        }
    } while (choice != 5);  // Repeat until user chooses to exit
}


// all operations except display() run in constant time O(1), making this queue implementation efficient for insertion and deletion.

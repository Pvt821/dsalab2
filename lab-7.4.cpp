#include <stdio.h>
#include <stdlib.h>

// Queue class definition using linked list
class queue {
    struct node {
        int data;
        node* next;
    };
    node* front;
    node* rear;

public:
    // Constructor to initialize queue
    queue() {
        front = NULL;
        rear = NULL;
    }

    void enqueue(int value);  // Insert element
    int dequeue();  // Remove element
    int peek();  // Get front element
    void display();  // Display queue elements
};

// Function to insert an element into the queue
void queue::enqueue(int value) {
    node* newnode = (node*)malloc(sizeof(node));
    newnode->data = value;
    newnode->next = NULL;

    if (rear == NULL) {  // If queue is empty, initialize front and rear
        front = newnode;
        rear = newnode;
    } else {
        rear->next = newnode;
        rear = newnode;
    }
    printf("%d enqueued to queue\n", value);
}

// Function to remove an element from the queue
int queue::dequeue() {
    if (front == NULL) {  // Check if the queue is empty
        printf("The Queue is Empty.\n");
        return -1;  // Return sentinel value
    }

    int result = front->data;
    node* temp = front;

    if (front == rear) {  // If single element is in the queue
        front = NULL;
        rear = NULL;
    } else {
        front = front->next;
    }

    free(temp);  // Free memory
    printf("%d dequeued from queue\n", result);
    return result;
}

// Function to get the front element without removing it
int queue::peek() {
    if (front == NULL) {
        printf("The queue is empty\n");
        return -1;
    } else {
        return front->data;
    }
}

// Function to display all elements in the queue
void queue::display() {
    if (front == NULL) {
        printf("The queue is empty\n");
        return;
    }

    node* temp = front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function for menu-driven queue operations
int main() {
    queue q;
    int choice, value;

    do {
        // Display menu
        printf("\nMENU\n1.Enqueue\n2.Dequeue\n3.Peek\n4.Display\n5.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Validate user input
        if (choice < 1 || choice > 5) {
            printf("Enter a valid choice\n");
            continue;
        }

        // Perform operations based on user choice
        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                printf("The element at front: %d\n", q.peek());
                break;
            case 4:
                q.display();
                break;
            case 5:
                printf("Exiting program...\n");
                return 0;
        }
    } while (choice != 5);  // Loop until exit

    return 0;
}

// operations timecomplexities
// Enqueue	O(1)
// Dequeue	O(1)
// Peek	O(1)
// Display	O(n)
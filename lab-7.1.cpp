#include<cstdio>
#define size 5
class queue{
    int arr[size];
    int front;
    int rear;
public:
queue(){
    front =-1;
    rear = -1;
}
int enqueue(int);
int dequeue();
int peek();
void Display();

};
int main(){
    queue obj;
    int choice,value;
    do{
        printf("\n=====MENU CARD=====\n");
        printf("Enter 1: To Insert the element into the Queue.\n");
        printf("Enter 2: To Delete the first element in the Queue.\n");
        printf("Enter 3: To Display the first element in the Queue.\n");
        printf("Enter 4:To Display all the elements of the queue:\n");
        printf("Enter 5: To End the Program.\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element to Enqueue: ");
            scanf("%d",&value);
            obj.enqueue(value);
            break;
            case 2:
            value = obj.dequeue();
            if(value!=0){
                printf("The Dequeue element in the Queue is: %d\n",value);
            }
            break;
            case 3:
            value = obj.peek();
            if(value!=0){
                printf("The first element in the Queue is: %d\n",value);
            }
            break;
            case 4:
            obj.Display();
            break;
            case 5:
            printf("Program Ended\n");
            break;
            default :
            printf("Invalid choice\n");
            printf("Enter the choice between 1 to 3\n");
            break;
        }
            }while(choice!=4);
}

// Function to insert the element at the end of teh queue
int queue :: enqueue(int value){
    if(front == (rear+1)%size){
        printf("The Queue is full!\n");
        return 0;
    }
    if (front==-1 && rear==-1){
        front++;
        rear = (rear+1)%size;
        arr[rear]= value;
        return 0;
    }
       rear = (rear+1)%size;
        arr[rear]= value;
        return 0;
}

// Function to Delete a element from the front of the Queue
int queue :: dequeue(){
    if(front==-1 && rear==-1){
        printf("The Queue is empty!\n");
        return 0;
    }
    if(rear == front){
        int result = arr[front];
        rear =-1;
        front =-1;
        return result;
    }
    else{
    int result = arr[front];
    front = (front+1)%size;
    return result;
}}

// Function to Display the First element of the Queue
int queue :: peek(){
     if(front ==-1){
        printf("The Queue is empty!\n");
        return 0;
    }
    return arr[front];}

    // Function to display all elements in the queue
void queue::Display() {
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
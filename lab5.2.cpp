//Circular linked list
#include <cstdio>
#include <cstdlib>

class list{
    private:
        int value, count, found;
        struct node{
            int data;
            struct node *next;
        }*head;
    public:
        int size=0;
        list(){
            head=NULL;
        };
        void insertbeg(int num);
        void insertend(int num);
        void insertpos(int num,int pos);
        int deletebeg();
        int deleteend();
        int deletepos(int pos);
        int search(int num);
        void display();
};

int main(){
    list l1;
    int choice, num, pos, val;
    do{
        printf("\tMENU\n");
        printf("1.Insert at beginning\n2.Insert at end\n3.Insert at specified position\n");
        printf("4.Delete beginning\n5.Delete end\n6.Delete specified position\n");
        printf("7.Search\n8.Display\n9.Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:     //inserting new data at the beginning of the list
                printf("Enter the Number: ");
                scanf("%d", &num);
                l1.insertbeg(num);
                break;
            case 2:     //inserting new data at the ebding of the list
                printf("Enter the Number: ");
                scanf("%d", &num);
                l1.insertend(num);
                break;
            case 3:     //inserting new data at a specified position
                printf("Enter the number: ");
                scanf("%d", &num);
                printf("Enter the position: ");
                scanf("%d", &pos);
                l1.insertpos(num, pos);
                break;
            case 4:     //deleting data at the beginning of the list
                num = l1.deletebeg();
                printf("Deleted element: %d\n", num);
                break;
            case 5:     //deleting data at the ending of the list
                num = l1.deleteend();
                printf("Deleted element: %d\n", num);
                break;
            case 6:     //deleting the data at the specified position of the list
                printf("Enter the position: ");
                scanf("%d", &pos);
                num = l1.deletepos(pos);
                printf("Deleted element: %d\n", num);
                break;
            case 7:     //searching for the specified number in the list
                printf("Enter number to search: ");
                scanf("%d", &num);
                val = l1.search(num);
                printf(val == -1 ? "Element not found\n" : "Element found at index %d\n", val);
                break;
            case 8:     //displaying the data of the list
                l1.display();
                break;
            case 9:     //Exiting the program
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid Input!\n");
        }
    } while(choice != 9);
    return 0;
}
//This function is used to insert a element in the beginning
void list::insertbeg(int num){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *last = head;
    temp->data = num;
    
    if (head == NULL) {
        temp->next = temp;
        head = temp;
    } else {
        while (last->next != head) {  // Find the last node
            last = last->next;
        }
        temp->next = head;
        head = temp;
        last->next = head;
    }
    size++;
}
//This function is used to insert a element in the end
void list::insertend(int num){
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    struct node *last = head;
    temp->data = num;
    
    if (head == NULL) {
        temp->next = temp;
        head = temp;
    } else {
        while (last->next != head) {  // Find the last node
            last = last->next;
        }
        last->next = temp;
        temp->next = head;
    }
    size++;
}
//This function is used to insert a number in a specific position
void list::insertpos(int num, int pos){
    if (pos < 0 || pos > size) {
        printf("Invalid position!\n");
        return;
    }
    if (pos == 0) {
        insertbeg(num);
    } else if (pos == size) {
        insertend(num);
    } else {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        struct node *curr = head;
        temp->data = num;
        for (int i = 0; i < pos - 1; i++) {
            curr = curr->next;
        }
        temp->next = curr->next;
        curr->next = temp;
        size++;
    }
}
//This function is used to delete a element in the beginning
int list::deletebeg(){
    if (head == NULL) return -1;
    struct node *temp = head;
    struct node *last = head;
    
    if (size == 1) {
        value = head->data;
        free(head);
        head = NULL;
    } else {
        while (last->next != head) {
            last = last->next;
        }
        value = head->data;
        head = head->next;
        last->next = head;
        free(temp);
    }
    size--;
    return value;
}
//This function is used to delete a element from the end
int list::deleteend(){
    if (head == NULL) return -1;
    struct node *temp = head;
    struct node *prev = NULL;
    
    if (size == 1) {
        value = head->data;
        free(head);
        head = NULL;
    } else {
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        value = temp->data;
        prev->next = head;
        free(temp);
    }
    size--;
    return value;
}
//This function is used to delete a element in a specific position
int list::deletepos(int pos){
    if (pos < 0 || pos >= size) {
        printf("Invalid position!\n");
        return -1;
    }
    if (pos == 0) return deletebeg();
    if (pos == size - 1) return deleteend();
    
    struct node *temp = head;
    struct node *prev = NULL;
    for (int i = 0; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = temp->next;
    value = temp->data;
    free(temp);
    size--;
    return value;
}
//This function is used to search a element in the linked list
int list::search(int num){
    struct node *temp = head;
    for (int i = 0; i < size; i++) {
        if (temp->data == num) {
            return i;
        }
        temp = temp->next;
    }
    return -1;
}
//This function is used to print the elements in the circular linked list
void list::display(){
    if (head == NULL) {
        printf("[]\n");
        return;
    }
    struct node *temp = head;
    printf("[");
    for (int i = 0; i < size; i++) {
        printf(" %d", temp->data);
        temp = temp->next;
    }
    printf(" ]\n");
}
// doubly linked list
// with maintaining tail
#include<cstdio>
#include<cstdlib>

class list{
    private:
        struct node{
            struct node *prev;
            int data;
            struct node *next;
        }*head, *tail;
    public:
        int size =0, value;
        list(){
            head = NULL;
            tail = NULL;
        };
        void Insert_beg(int);
        void Insert_end(int);
        void Insert_pos(int, int);
        void Delete_beg();
        void Delete_end();
        void Delete_pos(int);
        int Search(int);
        void Display();
};

int main(){
    list l1;
    int choice, num, pos, found =0;
    do{
        printf("\tMENU\n");
        printf("\t----\n");
        printf("1.Insert at beginning\n2.Insert at ending\n3.Insert at specified position\n");
        printf("4.Delete beginning\n5.Delete ending\n6.Delete specified position\n");
        printf("7.Search\n8.Display\n");
        printf("Enter your choice:");
        scanf("%i", &choice);

        switch (choice){
            case 1:     //inserting new data at the beginning of the list
                printf("Enter the number to be inserted:");
                scanf("%i", &num);
                l1.Insert_beg(num);
                printf("Number inserted successfully!\n\n");
                break;
            case 2:     //inserting new data at the ebding of the list
                printf("Enter the number to be inserted:");
                scanf("%i", &num);
                l1.Insert_end(num);
                printf("Number inserted successfully!\n\n");
                break;
            case 3:     //inserting new data at a specified position
                printf("Enter the number to be inserted:");
                scanf("%i", &num);
                printf("Enter the index at which number is to be inserted (based on zero index):");
                scanf("%i", &pos);
                if(pos<0 || pos>l1.size){
                    printf("Ivalid index!\n");
                }
                else{
                    l1.Insert_pos(num, pos);
                    printf("Number inserted successfully!\n\n");
                }
                break;
            case 4:     //deleting data at the beginning of the list
                if(l1.size){
                    l1.Delete_beg();
                    printf("Number deleted successfully!\n\n");
                }
                else{
                    printf("List is empty!\nData cannot be deleted!\n");
                }
                break;
            case 5:     //deleting data at the ending of the list
                if(l1.size){
                    l1.Delete_end();
                    printf("Number deleted successfully!\n\n");
                }
                else{
                    printf("List is empty!\nData cannot be deleted!\n");
                }
                break;
            case 6:     //deleting the data at the specified position of the list
                printf("Enter the poition at which the data should be deleted:");
                scanf("%i", &pos);
                if(pos<0 || pos>l1.size){
                    printf("Invalid position!\n");
                }
                else{
                    l1.Delete_pos(pos);
                    printf("Number deleted successfully!\n\n");
                }
                break;
            case 7:     //searching for the specified number in the list
                printf("Enter the number to be found:");
                scanf("%i", &num);
                found = l1.Search(num);
                if(found){
                    printf("number found at position %i!\n", found);
                }
                else{
                    printf("number not found!\n");
                }
                break;
                case 8:     //displaying the data of the list
                    if(l1.size){
                        l1.Display();
                    }
                    else{
                        printf("List is empty!");
                    }
                    break;
                case 9:     //Exiting the program
                    printf("Exiting the program!\n");
                    break;
                default:
                    printf("Invalid choice!");
        }
    }while(choice != 9);
    return 0;
}
//this function is used to insert a given data at the beginning of the list
void list::Insert_beg(int num){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    if(head){
        newnode->prev = NULL;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    else{
        newnode->prev = NULL;
        head = newnode;
        newnode->next = NULL;
        tail = newnode;
    }
    size++;
    Display();
    printf("\n");
}
//this function is used to insert a given data at the ending of the list
void list::Insert_end(int num){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    if(head){
        newnode->prev = tail;
        tail->next = newnode;
       newnode->next = NULL;
       tail = newnode;
    }
    else{
       newnode->prev = NULL;
        head = newnode;
        newnode->next = NULL;
        tail = newnode;
    }
    size++;
    Display();
    printf("\n");
}
//this function is used to insert a given number at the specified position
void list::Insert_pos(int num, int pos){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = num;
    if(pos == 1){
        Insert_beg(num);
    }
    else if(pos == size){
        Insert_end(num);
    }
    else{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp = head;
        for(int i=1;i<pos;i++){
            temp = temp->next;
        }
        newnode->prev = temp->prev;
        temp->prev->next = newnode;
        newnode->next = temp;
        temp->prev = newnode;
        size++;
        Display();
        printf("\n");
    }
}
//this function is used to delete the data at the beginning of the list
void list::Delete_beg(){
    value = head->data;
    head = head->next;
    head->prev->next = NULL;
    head->prev = NULL;
    size--;
    Display();
    printf("\n");
}
//this function is used to delete the data at the ending of the list
void list::Delete_end(){
    value = tail->data;
    tail = tail->prev;
    tail->next->prev = NULL;
    tail->next = NULL;
    size--;
    Display();
    printf("\n");
}
//this function is used to delete the data at a speified position in the list
void list::Delete_pos(int pos){
    if(pos==1){
        Delete_beg();
    }
    else if(pos==size){
        Delete_end();
    }
    else{
        struct node *temp1 = (struct node*)malloc(sizeof(struct node));
        struct node *temp2 = (struct node*)malloc(sizeof(struct node));
        temp1 = head;
        temp2 = head;
        for(int i=0;i<pos;i++){
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        value = temp1->data;
        temp1 = temp1->prev;
        temp1->next = temp1->next->next;
        temp1 = temp1->next;
        temp1->prev = temp2->prev;
        temp2->prev = NULL;
        temp2->next = NULL;
        size--;
        Display();
        printf("\n");
    }
}
//this function is used to search a specified number in the list
int list::Search(int num){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    int actual_pos = 1;
    while(temp->next){
        if(temp->data == num){
            return actual_pos;
        }
        else{
            temp = temp->next;
            actual_pos++;
        }
    }
}
//this function is used to display the data of the list
void list::Display(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    printf("Current list:");
   while(temp->next){
    printf("%i -> ", temp->data);
    temp = temp->next;
   }
   printf("%i", temp->data);
   printf("\n");
}
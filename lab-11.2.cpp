#include<iostream>
using namespace std;
#define size 7
class hashtable{
    int table[size];
    public:
    hashtable(){
        for(int i =0;i<size;i++){
            table[i]=-1;
        }
    }
    int hashfunction(int);
    int insert(int);
    int search(int);
    int Delete(int);
    void display();

};
int main(){
    hashtable obj;
    int choice,value,result;
    do{
        printf("\n=====MENU CARD=====\n");
        printf("Enter 1: To Insert the element into the Hash table.\n");
        printf("Enter 2: To Delete the element from the Hash table.\n");
        printf("Enter 3: To search an element in the Hash table.\n");
        printf("Enter 4: To Display the elements in the Hash table\n");
        printf("Enter 5: To End the Program.\n");
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            printf("Enter the element to insert: ");
            scanf("%d",&value);
            obj.insert(value);
            break;
            case 2:
            printf("Enter the element to insert Delete: ");
            scanf("%d",&value);
            result = obj.Delete(value);
            if(result!=-1){
                printf("%d is Deleted\n",result);
            }
            else{
                printf("The element is not found\n");
            }
            
            break;
            case 3:
            printf("Enter the element to insert: ");
            scanf("%d",&value);
            result = obj.search(value);
            if(result!=-1){
                printf("The element is found at the index %d!\n",result);
            }
            else{
                printf("The element is not found\n");
            }
            break;
            case 4:
            obj.display();
            break;
            case 5:
            printf("Program Ended\n");
            break;
            default :
            printf("Invalid choice\n");
            printf("Enter the choice between 1 to 4\n");
            break;
        }
            }while(choice!=5);

}
// Function to calculate the key value
int hashtable::hashfunction(int key ){
    return key %size;
}
int hashtable:: insert(int key){
    int index = hashfunction(key);
    int i =0;
    while(table[(index+i*i)%size]!=-1 && i<size){
        i++;
    }
    if(i==size){
        printf("Hash table is full.Cannot insert %d\n",key);
    }
    else{
        table[(index+i*i)%size]= key;
    }
    return 0;
}
// Function to search an element
int hashtable::search(int key) {
    int index = hashfunction(key);
    int i = 0;
    while (table[(index + i * i) % size] != -1 && i < size) {
        if (table[(index + i * i) % size] == key) {
            return (index + i * i) % size;
        }
        i++;
    }
    return -1;
}

// Function to delete an element
int hashtable::Delete(int key) {
    int index = hashfunction(key);
    int i = 0;
    while (table[(index + i * i) % size] != -1 && i < size) {
        if (table[(index + i * i) % size] == key) {
            int value = table[(index + i * i) % size];
            table[(index + i * i) % size] = -1;
            return value;
        }
        i++;
    }
    return -1;
}

// Function to display the table
void hashtable::display() {
    cout << "\nHash Table:\n";
    for (int i = 0; i < size; i++) {
        printf("%d -> ", i);
        if (table[i] != -1)
            printf("%d", table[i]);
        else
            printf("Empty");
        printf("\n");
    }
}
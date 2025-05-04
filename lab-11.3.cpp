#include <iostream>
#include <list>
using namespace std;
#define SIZE 7

class HashTable {
    list<int> table[SIZE];

public:
int hashFunction(int);
    int insert(int);
    int search(int);
    int Delete(int);
    void display();
    
};

int main() {
    HashTable obj;
    int choice, value, result;

    do {
        printf("\n===== MENU CARD =====\n");
        printf("Enter 1: To Insert the element into the Hash table.\n");
        printf("Enter 2: To Delete the element from the Hash table.\n");
        printf("Enter 3: To Search an element in the Hash table.\n");
        printf("Enter 4: To Display the elements in the Hash table.\n");
        printf("Enter 5: To End the Program.\n");
        printf("Enter the choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &value);
            obj.insert(value);
            break;
        case 2:
            printf("Enter the element to delete: ");
            scanf("%d", &value);
            result = obj.Delete(value);
            if (result != -1) {
                printf("%d is Deleted\n", result);
            } else {
                printf("The element is not found\n");
            }
            break;
        case 3:
            printf("Enter the element to search: ");
            scanf("%d", &value);
            result = obj.search(value);
            if (result != -1) {
                printf("The element is found in bucket %d!\n", result);
            } else {
                printf("The element is not found\n");
            }
            break;
        case 4:
            obj.display();
            break;
        case 5:
            printf("Program Ended\n");
            break;
        default:
            printf("Invalid choice\n");
            printf("Enter the choice between 1 to 5\n");
            break;
        }
    } while (choice != 5);

    return 0;
}
int HashTable ::hashFunction(int key) {
    return key % SIZE;
}
// Function to insert a key
int HashTable::insert(int key) {
    int index = hashFunction(key);
    table[index].push_back(key);
    printf("Inserted %d in bucket %d\n", key, index);
return 0;
}

// Function to search for a key
int HashTable::search(int key) {
    int index = hashFunction(key);
    for (int val : table[index]) {
        if (val == key)
            return index;
    }
    return -1;
}

// Function to delete a key
int HashTable::Delete(int key) {
    int index = hashFunction(key);
    for (auto it = table[index].begin(); it != table[index].end(); ++it) {
        if (*it == key) {
            table[index].erase(it);
            return key;
        }
    }
    return -1;
}

// Function to display the table
void HashTable::display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d -> ", i);
        for (int val : table[i]) {
            printf("%d -> ", val);
        }
        printf("NULL\n");
    }
}

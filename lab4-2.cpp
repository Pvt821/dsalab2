//usinh head.h for gathering the functions of the class
#include <iostream>
#include "head.h"
using namespace std;

int main() {
    List list1, list2, list3;
    int choice, value;

    do {
        cout << "1. Insert into List1\n";
        cout << "2. Insert into List2\n";
        cout << "3. Merge into List3\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter value to insert in List1: ";
                cin >> value;
                list1.insertAscending(value);
                break;
            case 2:
                cout << "Enter value to insert in List2: ";
                cin >> value;
                list2.insertAscending(value);
                break;
            case 3:
                list3 = List::mergeLists(list1, list2);
                cout << "Lists merged successfully.\n";
                break;
            case 4:
                cout << "List1: ";
                list1.display();
                cout << "List2: ";
                list2.display();
                cout << "List3 (Merged): ";
                list3.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

// Constructor initializes head to nullptr
List::List(){
    head=NULL;
} 

// Deconstructor clears the free space
List::~List() {
    Node* current = head;
    while (current) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
} 

//get head function for the getting the address of the each head of the list
List::Node* List::getHead() const {
    return head;
}

//inserting all the values only in ascending order
void List::insertAscending(int value) {
    Node* newNode = (Node*)malloc(sizeof(int));

    if (!head || head->data >= value) {  
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next && current->next->data < value) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

//displaying the values of the list
void List::display() {
    Node* current = head;
    while (current) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << "NULL\n";
}

//merges two lists into a third list
List List::mergeLists(const List& list1, const List& list2) {
    List mergedList;
    Node* l1 = list1.getHead();
    Node* l2 = list2.getHead();

    while (l1) {
        mergedList.insertAscending(l1->data);
        l1 = l1->next;
    }

    while (l2) {
        mergedList.insertAscending(l2->data);
        l2 = l2->next;
    }

    return mergedList;
}

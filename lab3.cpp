#include <iostream>
using namespace std;
#define MAX_SIZE 5
class ListADT {
private:
    int arr[MAX_SIZE];
    int size;

public:
    ListADT(){
        size=0;
    }

    void insertBeginning(int value) {
        if (size == MAX_SIZE) {
            cout << "List is full!\n";
            return;}
            
        for (int i = size; i > 0; --i)
            arr[i] = arr[i - 1];
        arr[0] = value;
        size++;
    }

    void insertEnd(int value) {
        if (size == MAX_SIZE) {
            cout << "List is full!\n";
            return;
        }
        arr[size++] = value;
    }

    void insertAtPosition(int pos, int value) {
        if (size == MAX_SIZE || pos < 1 || pos > size + 1) {
            cout << "Invalid position or list is full!\n";
            return;
        }
        for (int i = size; i >= pos; --i)
            arr[i] = arr[i - 1];
        arr[pos - 1] = value;
        size++;
    }

    void deleteBeginning() {
        if (size == 0) {
            cout << "List is empty!\n";
            return;
        }
        for (int i = 0; i < size - 1; ++i)
            arr[i] = arr[i + 1];
        size--;
    }

    void deleteEnd() {
        if (size == 0) {
            cout << "List is empty!\n";
            return;
        }
        size--;
    }

    void deleteAtPosition(int pos) {
        if (size == 0 || pos < 1 || pos > size) {
            cout << "Invalid position!\n";
            return;
        }
        for (int i = pos - 1; i < size - 1; ++i)
            arr[i] = arr[i + 1];
        size--;
    }

    void search(int value) {
        for (int i = 0; i < size; ++i) {
            if (arr[i] == value) {
                cout << "Element found at position " << i + 1 << "\n";
                return;
            }
        }
        cout << "Element not found!\n";
    }

    void display() {
        if (size == 0) {
            cout << "List is empty!\n";
            return;
        }
        cout << "List: ";
        for (int i = 0; i < size; ++i)
            cout << arr[i] << " ";
        cout << "\n";
    }

    // Rotate Method 1: Using Extra Array (O(n) space)
    void rotateExtraArray(int k) {
        k %= size;
        int temp[MAX_SIZE];
        for (int i = 0; i < size; ++i)
            temp[(i + k) % size] = arr[i];
        for (int i = 0; i < size; ++i)
            arr[i] = temp[i];
    }

    // Rotate Method 2: Using Reversal Algorithm (O(1) space)
    void reverse(int start, int end) {
        while (start < end)
            swap(arr[start++], arr[end--]);
    }
    void rotateReversal(int k) {
        k %= size;
        reverse(0, size - 1);
        reverse(0, k - 1);
        reverse(k, size - 1);
    }

    // Rotate Method 3: Using Cyclic Replacement (O(1) space)
    void rotateCyclic(int k) {
        k %= size;
        int count = 0;
        for (int start = 0; count < size; ++start) {
            int current = start;
            int prev = arr[start];
            do {
                int next = (current + k) % size;
                swap(arr[next], prev);
                current = next;
                count++;
            } while (start != current);
        }
    }
};

int main() {
    ListADT list;
    int choice, value, pos, k;
    while (true) {
        cout << "\nMenu:\n1. Insert Beginning\n2. Insert End\n3. Insert Position\n4. Delete Beginning\n5. Delete End\n6. Delete Position\n7. Search\n8. Display\n9. Rotate\n10. Exit\nEnter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter value: "; 
            cin >> value;
            list.insertBeginning(value);
            break;
        case 2:
            cout << "Enter value: "; cin >> value;
            list.insertEnd(value); 
            break;
        case 3:
            cout << "Enter position and value: ";
             cin >> pos >> value;
            list.insertAtPosition(pos, value); 
            break;
        case 4:
            list.deleteBeginning();
             break;
        case 5:
            list.deleteEnd();
             break;
        case 6:
            cout << "Enter position: "; cin >> pos;
            list.deleteAtPosition(pos); 
            break;
        case 7:
            cout << "Enter value to search: "; cin >> value;
            list.search(value);
             break;
        case 8:
            list.display(); 
            break;
        case 9:
            cout << "Enter k for rotation: "; cin >> k;
            cout << "Choose rotation method:\n1. Extra Array\n2. Reversal Algorithm\n3. Cyclic Replacement\nEnter choice: ";
            int method; cin >> method;
            if (method == 1) list.rotateExtraArray(k);
            else if (method == 2) list.rotateReversal(k);
            else if (method == 3) list.rotateCyclic(k);
            else cout << "Invalid method!\n";
            break;
        case 10:
            return 0;
        default:
            cout << "Invalid choice!\n";
        }
    }
}

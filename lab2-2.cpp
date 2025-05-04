#include <iostream>
#include <cmath>
using namespace std;
bool isPalindrome(int* num) {
    int* original = new int(*num);
    int* reversed = new int(0);
    int* digit = new int(0);
    while (*num > 0) {
        *digit = *num % 10;
        *reversed = *reversed * 10 + *digit;
        *num /= 10;
    }
    *num = *original;  // Restore original number
    bool result = (*original == *reversed);
    delete original; delete reversed; delete digit;
    return result;
}
bool isArmstrong(int* num) {
    int* original = new int(*num);
    int* sum = new int(0);
    int* digits = new int(0);
    int* temp = new int(*num);
    while (*temp > 0) {
        (*digits)++;
        *temp /= 10;
    }
    *temp = *num;
    while (*temp > 0) {
        int* digit = new int(*temp % 10);
        *sum += pow(*digit, *digits);
        *temp /= 10;
        delete digit;
    }
    bool result = (*sum == *original);
    delete original; delete sum; delete digits; delete temp;
    return result;
}
bool isPerfect(int* num) {
    int* sum = new int(0);
    int* original = new int(*num);
    for (int* i = new int(1); *i <= *original / 2; (*i)++) {
        if (*original % *i == 0)
            *sum += *i;
        delete i;
        i = new int(*i + 1);
    }
    bool result = (*sum == *original);
    delete sum; delete original;
    return result;
}
int main() {
    int* choice = new int;
    do {
        cout << "\nMenu:";
        cout << "\n1. Check Palindrome";
        cout << "\n2. Check Armstrong Number";
        cout << "\n3. Check Perfect Number";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        cin >> *choice;
        if (*choice >= 1 && *choice <= 3) {
            int* num = new int;
            cout << "Enter a number: ";
            cin >> *num;

            if (*num <= 0) {
                cout << "Invalid input! Enter a positive integer." << endl;
            } else {
                switch (*choice) {
                    case 1:
                        cout << (isPalindrome(num) ? "The number is a Palindrome." : "The number is not a Palindrome.") << endl;
                        break;
                    case 2:
                        cout << (isArmstrong(num) ? "The number is an Armstrong number." : "The number is not an Armstrong number.") << endl;
                        break;
                    case 3:
                        cout << (isPerfect(num) ? "The number is a Perfect number." : "The number is not a Perfect number.") << endl;
                        break;
                }
            }
            delete num; // Free allocated memory
        } else if (*choice != 4) {
            cout << "Invalid choice! Please enter a valid option." << endl;
        }
    } while (*choice != 4);
    cout << "Exiting program..." << endl;
    delete choice;
    return 0;
}

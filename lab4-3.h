// program that can insert values in ascending order and merge two lists 
#ifndef LIST_H
#define LIST_H

#include <iostream>

class List {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) { 
            data=val;
            next=nullptr; 
        }
    };

    Node* head;

    Node* getHead() const; // Private function to return head pointer

public:
    List();   
    ~List();  

    void insertAscending(int value); 
    void display() ;  
    static List mergeLists(const List& list1, const List& list2); 
};

#endif 
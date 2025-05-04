//c++ program to do different functions using singly linked list

#include <iostream>
using namespace std;

struct node{
    int data;
    node *next;
};

class linklist{
    private:
        node *head;
    public:
        linklist(){head=NULL;}
        void insertbeg(int);
        void display();
        void insertend(int val);
        void insertpos(int val,int pos);
        int delbeg();
        int delend();
        int delpos(int pos);
        void search(int val);
        void revdisplay();
        void revdisplay(node* head);
        void reverselink();
};

int main(){
    linklist list;
    int ch,val,pos,k;
    do{
        cout <<"\nMENU: \n";
        cout <<"1.Insert Beginning\n 2.Insert End\n 3.Insert Position\n 4.Delete Beginning\n 5.Delete End\n 6.Delete Position\n 7.Search\n 8.Display \n 9.Display Reverse\n 10.Reverse Link\n 11.Exit\n";
        cout <<"Enter the choice: ";
        cin >>ch;
        switch(ch){
            case 1:
                cout <<"Enter value: ";
                cin >>val;
                list.insertbeg(val);
                cout <<"The list will be: ";
                list.display();
                cout <<"\n";
                break;
            case 2:
                cout <<"Enter value: ";
                cin >>val;
                list.insertend(val);
                cout <<"The list will be: ";
                list.display();
                cout <<"\n";
                break;
            case 3:
                cout <<"Enter value and position: ";
                cin >>val>>pos;
                list.insertpos(val,pos);
                cout <<"The list will be: ";
                list.display();
                cout <<"\n";
                break;
            case 4:
                k=list.delbeg();
                cout <<"The deleted value is: "<<k<<"\n";
                cout <<"The list will be: ";
                list.display();
                cout <<"\n";
                break;
            case 5:
                k=list.delend();
                cout <<"The deleted value is: "<<k<<"\n";cout <<"\n";
                cout <<"The list will be: ";
                list.display();
                cout <<"\n";
                break;
            case 6:
                cout <<"Enter position to be deleted: ";
                cin >> pos;
                k=list.delpos(pos);
                cout <<"The deleted value is: "<<k<<"\n";
                cout <<"The list will be: ";
                list.display();
                cout <<"\n";
                break;
            case 7:
                cout <<"Enter value to be searched: ";
                cin >> val;
                list.search(val);
                break;
            case 8:
                cout <<"The list will be: ";
                list.display();
                cout <<"\n";
                break;
            case 9: 
                cout <<"The list will be: ";
                list.revdisplay();
                list.display();
                cout<<"\n";
            case 10:
                list.reverselink();
                cout <<"The list will be: ";
                list.display();
                cout <<"\n";
                break;
            case 11:
                cout <<"Exiting..\n";
                break;
            default:
                cout <<"Invalid input, TRY AGAIN\n";
                break;;
        }
    }while(ch!=11);
    return 0;
}

//insert a single element at the beginning
void linklist::insertbeg(int val){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=head;
    head=newnode;
}

//display the elements of the list
void linklist::display(){
    if(head==NULL){
        cout <<"List is empty!!";
        return;
    }
    node *temp=head;
    while(temp){
        cout <<temp->data <<" ";
        temp=temp->next;
    }
}

//insert a single element at the end
void linklist::insertend(int val){
    node *newnode=(node*)malloc(sizeof(node));
    newnode->data=val;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        return;
    }
    node *temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    return;
}

//insert a element at a particular position
void linklist::insertpos(int val,int pos){
    if(pos==1){
        insertbeg(val);
        return;
    }
    node *newnode=(node*)malloc(sizeof(node));
    node *temp=head;
    for(int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->data=val;
    newnode->next=temp->next;
    temp->next=newnode;
    return;
}

//delete a single element at the beginning of the list
int linklist::delbeg(){
    node *temp=head;
    head=head->next;
    int k=temp->data;
    free(temp);
    return k;
}

//delete a single element at the end of the list
int linklist::delend(){
    if(head->next==NULL){
        int val=head->data;
        free(head);
        head=NULL;
        return val;
    }
    node *temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    node *delnode=temp->next;
    int v=delnode->data;
    free(delnode);
    temp->next=NULL;
    return v;
} 

//delete a single element from a given position of the list
int linklist::delpos(int pos){
    if(head->next==NULL){
        int v=head->data;
        head=NULL;
        return v;
    }
    node *temp=head;
    for(int i=1;i<pos-1;i++){
        if(temp->next==NULL){
            cout <<"Index out of range";
            return 0;
        }
        temp=temp->next;
    }
    int val=temp->next->data;
    temp->next=temp->next->next;
    return val;
}

//searching and returning the position of the element in a given list
void linklist::search(int val){
    node *temp=head;
    int i=1;
    while(temp){
        if (temp->data==val){
            cout <<"The value is found at: "<<i<<" index.\n";
            i++;
            return;
        }
    }
    cout <<" The value is not found\n";
    return;
}

//printing the data in the reverse without changing the order
void linklist::revdisplay(node* head) {
    if (head == NULL) return;
    revdisplay(head->next);
    cout << head->data << " ";
}

void linklist::revdisplay() {
    revdisplay(head);
}


//reverselinking all elements of the list using loop and display in reverse order
void linklist::reverselink(){
    node *prev=NULL,*curr=head, *next=NULL;
    while (curr){
        next=curr->next;
        curr->next=prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}
#include <iostream>
using namespace std;

int main(){
    int size;
    cout<<"Enter the size of the array:";
    cin>>size;
    int arr[size];
    for (int i=0;i<size;i++){
        int val;
        cout<<"Enter number:";
        cin>>val;
        arr[i]=val;
    }
    int index=0;
    for (int i=1;i<size;i++){
        while (arr[index]<arr[i]){
            arr[index]=arr[index]+1;
            arr[i]=arr[i]-1;
        }
    }
    cout<<arr[0]<<"\n";
}

#include<iostream>
using namespace std;
#define max 100
class priorityQueue{
    int heap[max];
    int size; 

  public:
priorityQueue(){
   size =0;
}
void heapifyUp(int);
void heapifyDown(int);
int insert(int);
int deletemax();
void display();
int search(int);
void sort();
};
int main(){
    priorityQueue obj;
    int choice,result,value,target;
    do{
        printf("\n===Priority Queue Menu===\n");
        printf("Enter 1 : To insert an element into Priority Queue\n");
        printf("Enter 2 : To Delete an element from the Priority Queue\n");
        printf("Enter 3 : To Display the Priority Queue\n");
        printf("Enter 4 : To search for element in the Priority Queue\n");
        printf("Enter 5 : To Perform heap sort\n");        
        printf("Enter 6 : Exit the program\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
    switch(choice){
        case 1:
        printf("Enter the value : ");
        scanf("%d",&value);
        obj.insert(value);
        break;
        case 2:
        value = obj.deletemax();
        if(value!= 0){
            printf("The element deleted is %d",value);
        }
        break;
        case 3:
        obj.display();
        break;
        case 4:
        printf("Enter the value to search : ");
        scanf("%d",&target);
        value =obj.search(target);
        if(value!= 0){
            printf("Element %d is found in the Priority Queue",target);
        }
        else{
            printf("The element is not found in Priority Queue");
        }
        break;
        case 5:
        obj.sort();
        break;
        case 6:
        printf("program Ended\n");
        break;
        default:
        printf("Invalid choice\n");
        printf("Enter the choice between 1 to 5\n");

    }}
    while(choice !=6);
}
// Function to perform the heapify up
void priorityQueue:: heapifyUp(int index){
while(index>0){
    int parent = (index-1)/2;
    if(heap[index]>heap[parent]){
        int temp = heap[index];
        heap[index]= heap[parent];
        heap[parent]= temp;
        index=parent;
    }
    else{
        break;
    }
}}
// Function to perform the heapify down
void priorityQueue:: heapifyDown(int index){
    while(index>size){
        int left = 2*index+1;
        int right = 2*index+2;
        int largest = index;
        if(left<size && heap[left]>heap[largest]){
            largest = left;
        }
        if(right<size && heap[right]>heap[largest]){
            largest = right;
        }
        if(largest!=index){
        int temp = heap[index];
        heap[index]= heap[largest];
        heap[largest]= temp;
        index=largest;
        }
        else{
            break;
        }
    }
}
// Function to insert an element
int priorityQueue:: insert(int value){
    if(size==max){
        printf("The Queue is full!\n");
        return 0;
    } 
    heap[size]= value;
    heapifyUp(size);
    size++; 
}
// Function to Detete an element
int priorityQueue::deletemax(){
    if(size==0){
        printf("Priority Queue is empty!");
        return 0;
    }
    int del = heap[0];
    heap[0]=heap[size-1];
    size--;
    heapifyDown(0);
    return del;
}
// Function to display the elements
void priorityQueue::display(){
    if(size==0){
        printf("Priority Queue is empty!");
        return ;
    }
    printf("Priority Queue:");
    for(int i =0;i<size;i++){
        printf("%d  ",heap[i]);
    }
    printf("\n");
}
// Function to search an element 
int priorityQueue::search(int target){
    for(int i =0;i<size;i++){
        if(heap[i]==target){
            return 1;
        }
    }
    return -1;
}
// Function to perfrom heap sort
void priorityQueue:: sort(){
    if(size==0){
        printf("Priority Queue is empty!");
        return ;
    }
    int temp = size;
    int tempheap[max];
    for (int i = 0; i < size; i++) {
        tempheap[i] = heap[i];
    }
    printf("Sorted elements: ");
    while(temp>0){
        printf("%d ",tempheap[0]);
        int tem = tempheap[0];
        tempheap[0]= tempheap[temp-1];
        tempheap[temp-1]= tem;
        temp--;
        int index=0;
        while(index<temp){
            int left = 2 * index + 1;
                int right = 2 * index + 2;
                int largest = index;
                if (left < temp && tempheap[left] > tempheap[largest]) 
                largest = left;
                if (right < temp && tempheap[right] > tempheap[largest])
                 largest = right;
                if (largest != index) {
                    int tem2 = tempheap[index];
                    tempheap[index]= tempheap[largest];
                    tempheap[largest]= tem2;
                    index=largest;
                } else {
                    break;
                }
            }
        }
        printf("\n");
    }





























// Question headache
// #include <iostream>
// #include<vector>
// using namespace std;
// int main(){
//     vector<int> nums = {12,6,1,2,7};
//     int size = nums.size();
//     if(size<3){
//         printf("the value1 is 0");
//     }
//     else{
//         int max = nums[0];int a =0;
//         int max2 = nums[0];int c =0;
//         for(int i =1;i<size;i++){
//             if(nums[i]>max){
//                 max = nums[i];
//                 a =i;
//             } 
//             int min = nums[0];
//             int b =0;
//                 for(int k =1;k<size;k++){
//                     if(nums[k]<min){
//                         min = nums[k];
//                         b =k;
//                     }
//                 }
//             if(a==0){
//                 c =1;
//                 max2 = nums[1];
//            }
//            for(int j =1;j<b;j++){
//                if(nums[j]<=max && a!=j && nums[j]>=max2){
//                    max2 = nums[j];
//                    c = j;
//                }
//            }
//            if(a>c){
//             int t =c;
//             c=a;
//             a=t;
//            }
//             long long result = (long long)(nums[a]-nums[b])*nums[c];
//             printf("%d %d %d\n",a,b,c);
//             if(result>0){
//                 printf("%ld",result);
//             }
//             else{
//                 printf("the vale2 is 0");
//             }
//         }

//     }
// }
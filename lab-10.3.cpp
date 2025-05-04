#include<iostream>
using namespace std;
#define max 200001
int find(int arr[],int size);
int main(){
    int cases,length;
    printf("Enter the number of Testcases: ");
    scanf("%d",&cases);
    for(int i =1;i<=cases;i++){
        printf("\nEnter the details of the Testcase %d:-\n",i);
        printf("Enter the length of Sequence:");
        scanf("%d",&length);
        int seq[length];
        printf("Enter the elements in the sequence: ");
        for(int j =0;j<length;j++){
            scanf("%d",&seq[j]);
        }
        printf("the number elements to be removed are :%d",find(seq,length));
        printf("\n");
    }
}
// Function to check the unique elements 
int find(int arr[],int size){
    int freq[max]={0};
        for(int i =size-1;i>=0;i--){
            if(freq[arr[i]]==0){
                freq[arr[i]]= 1;
            }
            else if (freq[arr[i]]==1){
                return i+1;
            }
        }
        return 0;
}

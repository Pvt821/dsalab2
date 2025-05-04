#include<iostream>
#include<vector>
using namespace std;
int main(){
    int cases,num;
    printf("Enter the number of Testcases: ");
    scanf("%d",&cases);
    for(int i =1;i<=cases;i++){
        printf("\nEnter the details of the Testcase %d:-\n",i);
        printf("Enter the no of words written by each:");
        scanf("%d",&num);
        vector<string> a(num),b(num),c(num);
        vector<string>allwords(3*num);
        printf("Enter the words of 1st person:\n");
        for(int i =0;i<num;i++){
            cin >>a[i];
            allwords[i]=a[i];
        }
        printf("Enter the words of 2nd person:\n");
        for(int i =0;i<num;i++){
            cin >>b[i];
            allwords[num+i]=b[i];
        }
        printf("Enter the words of 3rd person:\n");
        for(int i =0;i<num;i++){
            cin >>c[i];
            allwords[2*num+i]=c[i];
        }
        int freq[3 * num] = {0}; // One count for each word
        for (int i = 0; i < 3 * num; ++i) {
            for (int j = 0; j < 3 * num; ++j) {
                if (i != j && allwords[i] == allwords[j]) {
                    freq[i]++;
                }
            }
        }
        // Score calculation
        int score1 = 0, score2 = 0, score3 = 0;

        for (int i = 0; i < num; ++i) {
            if (freq[i] == 0) score1 += 3;
            else if (freq[i] == 1) score1 += 1;
        }
        for (int i = num; i < 2 * num; ++i) {
            if (freq[i] == 0) score2 += 3;
            else if (freq[i] == 1) score2 += 1;
        }
        for (int i = 2 * num; i < 3 * num; ++i) {
            if (freq[i] == 0) score3 += 3;
            else if (freq[i] == 1) score3 += 1;
        }

        cout << score1 << " " << score2 << " " << score3 << endl;
    }
    return 0;
}
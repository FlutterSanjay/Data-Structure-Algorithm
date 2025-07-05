// Print Sub - Array
#include<bits/stdc++.h>
using namespace std;

// TIme Complexity = O(n^2)
// Space Complexity = O(n)

void printArray_util(vector<int>& num,int s,int e){
    // Base Case
    if(e>=num.size()){
        return;
    }

    // Processing
    for (int i = s; i <= e;i++){
        cout << num[i] << " ";
    }
    cout << endl;

    // Recursive Relation
    printArray_util(num, s, e + 1);
}
void printArray(vector<int>&num){
    for (int i = 0; i < num.size();i++){
        int end = i;
        printArray_util(num, i, end);
    }
}
int main(){
    vector<int> num = {1, 2, 3, 4, 5};
    printArray(num);
    return 0;
}
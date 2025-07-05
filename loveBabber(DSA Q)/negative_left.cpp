// moves all negative element to the left side of an array
#include<iostream>
#include<vector>
using namespace std;

void moveNegative(vector<int> arr){
    int start=0;
    for(int i=0;i<arr.size();i++){
        if(arr[i]<0){
            swap(arr[start],arr[i]);
            start++;
        }
    }
    // for display
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    }
}
int main(){
    vector<int> ans{-1,-2,-3,-4,-5,6};
    moveNegative(ans);
    return 0;
}
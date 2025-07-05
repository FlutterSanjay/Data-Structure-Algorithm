// Reverse the given String
#include<bits/stdc++.h>
using namespace std;
void reverseString(string& arr,int i,int j){
    // Base Case
    if(i >= j) return;
    
    // Processing
    swap(arr[i],arr[j]);
    
    // Recursive relation
    reverseString(arr,i+1,j-1);
}

int main(){
    string arr="sanjay";
    int i=0;
    int j=arr.size()-1;
    reverseString(arr,i,j);
    cout<<"Reverse of String :"<<arr;
    return 0;
}
// check the given string is Plindrome or not
#include<bits/stdc++.h>
using namespace std;

void checkPalindrome(string& arr,int i,int j,bool& ans){
    
    //Base Case
    if(i >= j){
    ans=true;
    return;
    }
    if(arr[i] != arr[j]){
        ans= false;
        return;
    }
    
    // Recursive Relation
    checkPalindrome(arr,i+1,j-1,ans);
    
    
}
int main(){
    
    string arr = "121";
    int i=0;int j=arr.size()-1;
    bool ans=false;
    checkPalindrome(arr,i,j,ans);
    cout<<(ans?"Palindrome":"Not Palindrome");
    return 0;
    
}
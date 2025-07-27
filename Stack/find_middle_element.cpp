// Find the Middle Element
#include<bits/stdc++.h>
using namespace std;

int findMiddle(stack<int>&s,int totalSize){
    //stack is Empty
    if(totalSize==0){
        return -1;
    }

    // Base Case
    if((totalSize/2) + 1 == s.size()){
        return s.top();
    }

    int temp = s.top();
    s.pop();

    // Recursive Call
    return findMiddle(s, totalSize);

    s.push(temp);
}
int main(){
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);
    
    cout << findMiddle(s, s.size());
    return 0;
}
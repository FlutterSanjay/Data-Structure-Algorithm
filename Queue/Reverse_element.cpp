// reverse the Queue element // GeeksforGeeks
#include<iostream>
#include<queue>
#include<stack>
using namespace std;
queue<int> rev(queue<int>& q){
    stack<int> s;
    while(!q.empty()){
        int ans=q.front();
        q.pop();
        s.push(ans);
    }
    while(!s.empty()){
        int ans=s.top();
        s.pop();
        q.push(ans);
    }
    return q;
}
int main(){
    queue<int> q;
    int size,data;
    cout<<"Enter the size of list : ";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter your no : ";
        cin>>data;
        q.push(data);
    }
    q=rev(q);
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}
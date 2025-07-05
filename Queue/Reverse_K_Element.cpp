// reverse the K Element in Queue            // GeeksforGeeks
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverse(queue<int> q,int k){
    stack<int> s;
    // step-1 : push k Element from Q to stack
    for(int i=0;i<k;i++){
       int ans=q.front();
       q.pop();
       s.push(ans);
    }
    // step 2 : push all Stack Element in Q
    while(!s.empty()){
        int ans=s.top();
        s.pop();
        q.push(ans);
    }
    
    // step 3 : fetch n-k Element from Q and push to Q
    int t=q.size()-k;
    while(t--){
        int ans=q.front();
        q.pop();
        q.push(ans);
    }
    return q;
}
int main(){
    queue<int> q;
    int size,k,data;
    cout<<"Enter the size of Queue  : ";
    cin>>size;
    for(int i=0;i<size;i++){
        cout<<"Enter your no : ";
        cin>>data;
        q.push(data);
    }
    cout<<"Enter the Number of Element want to Rotate : ";
    cin>>k;
    q=reverse(q,k);
    
    // for output 
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
    return 0;
}


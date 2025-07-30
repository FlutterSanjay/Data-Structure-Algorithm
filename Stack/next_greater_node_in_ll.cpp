// Next Greater Element in Linked List
#include<bits/stdc++.h>
using namespace std;

class Node{
public:
int data;
Node* next;
Node(int data){
  this->data=data;
  this->next=NULL;
}
};
vector<int> NextGreaterElement(Node* &head){
  // sare element ko vector mai dal do
  vector<int> ll;
  while(head!=NULL){
    ll.push_back(head->data);
    head=head->next;
  }
stack<int> st;

  for(int i=0;i<ll.size();i++){

    while(!st.empty() && ll[i]>ll[st.top()]){
      int kids=st.top();
      st.pop();
      ll[kids]=ll[i];
    }
    st.push(i);
  }


  // for Greater Element
  while(!st.empty()){
    int kids=st.top();
    st.pop();
    ll[kids]=0;
  }

  // for last Element
  ll[ll.size()-1]=0;
  return ll;
  }


int main(){
  Node* head=new Node(2);
  head->next=new Node(1);
  head->next->next=new Node(7);
  head->next->next->next=new Node(4);
  head->next->next->next->next=new Node(3);
  head->next->next->next->next->next=new Node(5);
  vector<int> ans=NextGreaterElement(head);
  for(int i=0;i<ans.size();i++){
    cout<<ans[i]<<" ";
  }
  
  


  return 0;
}
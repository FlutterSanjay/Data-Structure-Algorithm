

// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

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


void print(Node* &head){
  Node* temp=head;
  while(temp!=NULL){
      cout<<temp->data<<" ";    
      temp=temp->next;
  }
}

vector<int> CriticalPoint(Node* &head){
  vector<int> ans{-1,-1};

  Node* prev=head;
  Node* curr=head->next;
  Node* nxt=head->next->next;


  // All Condition
  if(prev==NULL){
    return ans;
  }
  if(curr==NULL){
    return ans;
  }
  if(nxt==NULL){
    return ans;
  }

  int firstCp=-1;
  int lastCp=-1;
  int minDist=INT_MAX;
  int i=1;
  
  while(nxt!=NULL){

    bool isCp = ((prev->data>curr->data && curr->data<nxt->data) || (prev->data<curr->data && curr->data>nxt->data))?true:false;

    if(isCp && firstCp==-1){
      firstCp=i;
      lastCp=i;
       }
    else if(isCp){
      minDist=min(minDist,i-lastCp);
      lastCp=i;
      }
 i++;
    prev=prev->next;
    curr=curr->next;
    nxt=nxt->next;
    }

  if(firstCp== lastCp){
    return ans;
  }else{
  ans[0]=minDist;
  ans[1]=lastCp-firstCp;
  }
    return ans;
  }

  


int main(){
  Node* head1=new Node(5);
  Node* second = new Node(3);
  Node* third = new Node(1);
  Node* fourth = new Node(2);
  Node* fifth = new Node(5);
  Node* sixth = new Node(1);
  Node* seventh = new Node(2);

  head1->next=second;
  second->next=third;
  third->next=fourth;
  fourth->next=fifth;
  fifth->next=sixth;
  sixth->next=seventh;
  seventh->next=NULL;

  print(head1);
  cout<<endl;
  vector<int> ans=CriticalPoint(head1);
  cout<<ans[0]<<" "<<ans[1];
  cout<<endl;
 

 


  return 0;
}
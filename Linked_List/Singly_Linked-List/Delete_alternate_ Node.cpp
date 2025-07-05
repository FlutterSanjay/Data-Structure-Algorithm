// Delete the alternate element from the given node
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* next;

    Node(int data){
        val=data;
        next=NULL;
    }
};
void insert(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}

void insert_tail(Node* &head,int data){
    Node* temp=new Node(data);
    Node* lnode=head;
    while(lnode->next!= NULL){
        lnode=lnode->next;

    }
    lnode->next = temp;
}

void alter(Node* &head){
    Node* current=head;
    Node* temp;
    while(current!= NULL && current->next!=NULL){
        temp=current->next;
        current->next=current->next->next;
        free(temp);
        current=current->next;
    }
}
void display(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}
int main(){
    int data;
    Node* head=NULL;
    insert(head,2);
   for(int i=0;i<5;i++){
    cout<<"Enter your no : ";
    cin>> data;
    insert_tail(head,data);
   }
          display(head);

          cout<<"\n"<<"After Alternate Deletion of Element-"<<endl;
          alter(head);
          display(head);
          return 0;

}
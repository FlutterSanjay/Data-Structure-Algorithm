//Rearrangement the list - 
//l0->ln->l1->ln-1...
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
    while(lnode->next!=NULL){
        lnode=lnode->next;
    }
    lnode->next=temp;
}

Node* reorder(Node* &head){
    Node* slow=head;
    Node* fast=head;

    while(fast&&fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    // now slow pointing the the middle element of node
    //seperate the linked list and reverse the second half

    Node* curr=slow->next;
    slow->next=NULL;
    Node* prev=slow;

    while(curr){
        Node* nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }

    // merege the two half of Linked List
    Node* ptr1=head;
    Node* ptr2=prev;

    while(ptr1!=ptr2){
        Node* temp=ptr1->next;
        ptr1->next=ptr2;
        ptr1=ptr2;
        ptr2=temp;
    }
    return head;
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

int main(){
    Node* head=NULL;
    insert(head,1);
    int data;
    for(int i=0;i<4;i++){
        cout<<"Enter your no : ";
        cin>>data;
        insert_tail(head,data);
    }
   display(head);
    cout<<endl;
Node* temp=reorder(head);
cout<<endl;
display(temp);
return 0;

}
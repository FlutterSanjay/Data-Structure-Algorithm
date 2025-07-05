// remove the kth Element from the last
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

void remove_kth_node(Node* &head,int k){
    Node* ptr1=head;
    Node* ptr2=head;
    int count=k;
    while(count--){
        ptr2=ptr2->next;
    }
    if(ptr2==NULL){
        Node* temp=head;
        head=head->next;
        free(temp);
        return ;
    }
    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    Node* temp=ptr1->next;
    ptr1->next=ptr1->next->next;
    free(temp);
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

int main(){
    int k;
    Node* head=NULL;
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    display(head);
    cout<<endl;
    cout<<"Enter your position : ";
    cin>>k;
    remove_kth_node(head,k);  // indexing will be done in reverse order 
   // NULL will also count as index 0
    display(head);
    return 0;
}
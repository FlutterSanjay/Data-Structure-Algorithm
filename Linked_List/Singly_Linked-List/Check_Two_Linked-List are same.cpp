// check the two linked list are same or not
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
void insert(Node* & head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}

bool check(Node* head,Node* head1){
    while(head1 != NULL && head != NULL){
        if(head->val != head1->val) return false;
        head=head->next;
        head1=head1->next;
    }
    if(head ==NULL && head1 ==NULL) return true;
}
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    
}
int main(){
    Node* head=NULL;
    Node* head1=NULL;
    insert(head,2);
    insert(head,3);
    insert(head,4);
    cout<<"First Linked Data-";
    display(head);
    cout<<endl;
    insert(head1,2);
    insert(head1,3);
    insert(head1,4);
    cout<<"Second Linked Data-";
    display(head1);
    cout<<endl;
    if(check(head,head1)==0) cout<<"NOT SAME !";
    else cout<<"SAME LINKED LIST !";
    
    return 0;
}
// print th element in rverse order
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

void reverse(Node* &head){
    if(head==NULL) return ;
    reverse(head->next);
    cout<<head->val<<" ";
}

void display(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* head=NULL;
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    insert(head,6);
    display(head);

    cout<<endl;

    reverse(head);
    return 0;

}
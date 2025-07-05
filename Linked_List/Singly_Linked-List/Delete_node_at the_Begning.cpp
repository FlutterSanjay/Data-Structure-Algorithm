// Deleting the Node at the starting
#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node* link;

    Node(int data){
        val=data;
        link=NULL;
    }
};
void insert(Node* &head,int data){
    Node* temp=new Node(data);
    temp->link=head;
    head=temp;
}

void del(Node* &head){
    Node* temp=head;
    head=head->link;
    free(temp);
}
void display(Node* head){
    Node* temp=head;
    while(temp !=NULL){
        cout<<temp->val<<" ";
        temp=temp->link;
    }
}
int main(){
    Node* head=NULL;
    insert(head,2);
    insert(head,4);
    insert(head,6);
    insert(head,8);
    display(head);
    cout<<endl;
    cout<<"After Deletion"<<endl;
    del(head);
    display(head);
    return 0;

}
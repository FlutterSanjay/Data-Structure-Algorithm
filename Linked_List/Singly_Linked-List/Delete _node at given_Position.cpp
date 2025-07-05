// Delete the node at given position..
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
// deletion operation
void delete_pos(Node* &head,int pos){
    if(pos==0){
        del(head);
        return ;
    }
    Node* prev=head;
    int cur_pos=0;
    while(cur_pos!=pos-1){
        prev=prev->link;
        cur_pos++;
    }
    Node* temp=prev->link;
    prev->link=prev->link->link;
    free(temp);
}
void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->link;
    }
}
int main(){
    Node* head=NULL;
    insert(head,2);
    insert(head,4);
    insert(head,6);
    display(head);
    int pos;
    cout<<endl;
    cout<<"Enter your position to delete : ";
    cin>>pos;
    cout<<endl;
    delete_pos(head,pos);
    display(head);

    return 0;
}
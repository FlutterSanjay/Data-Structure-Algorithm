// Delete the node at the starting
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
class circular{
    public:
    Node* head;
    circular(){
        head=NULL;
    }
    void insert(int data){
        Node* temp=new Node(data);
        if(head==NULL){
        head=temp;
        head->next=head;
        return;
        }
        Node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        tail->next=temp;
        temp->next=head;
        head=temp;
    }
    void del_end(){
        if(head==NULL){
            return ;
        }
        Node* tail=head;
        while(tail->next!=head){
            tail=tail->next;
        }
        Node* temp=tail->next;
        tail->next=head;
        free(temp);
    }
    void display(){
        Node* temp=head;
        do{
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        while(temp!=head);
    }
};
int main(){
    circular aa;
    int data;
    for(int i=0;i<6;i++){
        cout<<"Enter your no: ";
        cin>>data;
        aa.insert(data);
    }
    aa.display();
    cout<<endl;
    aa.del_end();
    aa.display();
    return 0;
}
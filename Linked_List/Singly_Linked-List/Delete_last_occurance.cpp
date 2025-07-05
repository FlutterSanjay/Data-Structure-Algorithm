// Delete the last occurance of given argument Element
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int val){
        data=val;
        next=NULL;
    }
};
void insert(Node* &head,int data){
    Node* temp=new Node(data);
    Node* head1=head;
    if(head==NULL){
        head=temp;
        return;
    }
    while(head1->next!=NULL){
        head1=head1->next;
    }
    head1->next=temp;
}

int delete_last_occurance(Node* &head,int key){
    Node* temp=head;
    Node* last;
    Node* prev;
    while(temp!=NULL){
        if(temp->data==key){
            last=temp;
        }
        prev=temp;
        temp=temp->next;
    }
    if(last!=NULL){
        if(last==head){
            head=head->next;
        }
        else{
            prev->next=last->next;
        }
        int val=last->data;
        free(last);
        return val;
    }
}
int main(){
    Node* head=NULL;
    insert(head,1);
    insert(head,2);
    insert(head,2);
     insert(head,3);
    insert(head,4);
    insert(head,2);
    cout<<"Deleted ELement : "<<delete_last_occurance(head,2);
    return 0;
}
// delete the neighbour value
#include<iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node* prev;

    Node(int data){
        val=data;
        next=NULL;
        prev=NULL;
    }
};
class Doubly{
    public:
    Node* head;
    Node* tail;

    Doubly(){
        head=NULL;
        tail=NULL;
    }
    void insert(int val){
        Node* end=new Node(val);
        if(tail==NULL){
            head=end;
            tail=end;
            return;
        }
        tail->next=end;
        end->prev=tail;
        tail=end;
        return ;
    }
    void display(){
        while(head!=NULL){
            cout<<head->val<<" ";
            head=head->next;
        }
    }
};
void display(Node* head){
        while(head!=NULL){
            cout<<head->val<<" ";
            head=head->next;
        }
    }

void del_neighbour(Node* &head,Node* &tail){
    Node* curr=tail->prev;
    while(curr!= head){
    Node* prev=curr->prev;
    Node* next=curr->next;
    if(prev->val==next->val){
        prev->next=next;
        next->prev=prev;
        free(curr);
    }
    curr=prev;
}
}

int main(){
    Doubly aa;
    int data;
    for(int i=0;i<5;i++){
        cout<<"Enter your no : ";
        cin>>data;
        aa.insert(data);
    }
    display(aa.head);
    del_neighbour(aa.head,aa.tail);
    cout<<endl;
    aa.display();
    return 0;

}
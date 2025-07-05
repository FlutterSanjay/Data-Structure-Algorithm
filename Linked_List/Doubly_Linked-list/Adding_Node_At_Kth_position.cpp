// Adding Node at Kth Position
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

class doubly{
    public:
    Node* head;
    Node* tail;
    doubly(){
        head=NULL;
        tail=NULL;
    }
void insert_tail(int data){
    Node* end=new Node(data);
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
    void insert_position(int val,int k){
        Node* temp=head;
        int count=1;
        while(count<(k)){
          temp=temp->next;
          count++;
        }
        Node* new_node=new Node(val);
        new_node->next=temp->next;
        temp->next=new_node;

        new_node->prev=temp;
        new_node->next->prev=new_node;
        return;
    }

    void display(){
        while(head!=NULL){
            cout<<head->val<<" ";
            head=head->next;
        }
    }
};

int main(){
    doubly aa;
    int data;
    for(int i=0;i<5;i++){
        cout<<"Enter your no : ";
        cin>>data;
        aa.insert_tail(data);
    }
    aa.insert_position(8,3);
    aa.display();
    return 0;
}
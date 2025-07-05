// Delete the Node at Kth Position
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
        if(head==NULL){
            head=end;
            tail=end;
            return;
        }
        tail->next=end;
        end->prev=tail;
        tail=end;
        return ;
    }
    void del_k(int k){
        Node* temp=head;
        int count=0;
        while(count<k){
            temp=temp->next;
            count++;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        return ;
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
    for(int i=0;i<6;i++){
        cout<<"Enter your no : ";
        cin>>data;
        aa.insert_tail(data);
    }
    aa.del_k(3);
    aa.display();
    return 0;
}
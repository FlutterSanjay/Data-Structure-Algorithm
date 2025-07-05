// Delete the Node at Starting
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
            return ;
        }
        tail->next=end;
        end->prev=tail;
        tail=end;
        return ;
    }

    void del(){
        if(head==NULL){
            return ;
        }
        Node* temp=head;
        head=head->next;
        if(head==NULL){
            tail=NULL;
        }
        else{
            head->prev=NULL;
        }
        free(temp);
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
    //aa.display();
    aa.del();
    cout<<endl;
    aa.display();
    return 0;
}
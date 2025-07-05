//Delete Node at End
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
        return;
    }

    void del_end(){
        if(head==NULL) return;
        Node* temp=tail;
        tail=tail->prev;
        if(tail==NULL) head=NULL;
        else tail->next=NULL;

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
    //aa.display();
    aa.del_end();
    cout<<endl;
    aa.display();
    return 0;
}
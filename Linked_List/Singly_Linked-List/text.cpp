// update the data of Linked List
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
void insert(Node* head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}
void insertT(Node* head,int data){
    Node* temp=new Node(data);
    Node* lnode=head;
    while(lnode->next != NULL){
        lnode=lnode->next;
    }
    lnode->next=temp;;
}

void update(Node* &head,int data,int pos){
    Node* temp=head;
    int cur_pos=0;
    while(cur_pos!=pos){
        temp=temp->next;
        cur_pos++;
    }
    temp->val=data;
}

void display(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

int main(){
    Node* head=NULL;
    int size ,data,pos;
    cout<<"Enter the size of list  :";
    cin>>size;
    for(int i=0;i<size;i++){
        if(i==0){
            cout<<"Enter your no : ";
            cin>>data;
            insert(head,data);
        }
        else{
            cout<<"Enter your no : ";
            cin>>data;
            insertT(head,data);
        }
    }
    display(head);
    cout<<"Enter your positon to upadate : ";
    cin>>pos;
    cout<<"Enter your data : ";
    cin>>data;
    update(head,data,pos);
    display(head);
    return 0;
}

// Add the Node at given position
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
void insertT(Node* &head,int data){
    Node* temp=new Node(data);
    Node* lnode=head;
    while(lnode->link != NULL){
        lnode=lnode->link;
    }
    lnode->link=temp;
}

void insert_pos(Node* &head,int data,int pos){
    if(pos==0){
        insert(head,data);
        return ;
    }
    Node* new_node=new Node(data);
    Node* temp=head;
    int cur_pos=0;
    while(cur_pos != pos-1){
        temp=temp->link;
        cur_pos++;
    }
    new_node->link=temp->link;
    temp->link=new_node;
}

void display(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp=temp->link;
    }
}

int main(){
    Node* head=NULL;
    int data,pos;
    insert(head,2);
    for(int i=0;i<=3;i++){
        cout<<"Enter your no :";
        cin>>data;
        insertT(head,data);
    }
    cout<<"Enter your no to add in node :";
    cin>>data;
    cout<<"Enter your position to add no : ";
    cin>>pos;
    insert_pos(head,data,pos);
    display(head);
    return 0;
}
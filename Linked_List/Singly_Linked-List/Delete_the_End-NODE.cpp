// delete the end node
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

void insert_Tail(Node* &head,int data){
    Node* temp=new Node(data);
    Node* lnode=head;
    while(lnode->link != NULL){
        lnode=lnode->link;
    }
    lnode->link=temp;

}

void insert_pos(Node* &head,int data,int pos){
    Node* temp=new Node(data);
    Node* new_node=head;
    if(pos==0){
        temp->link=head;
        return ;
    }
    int cur_pos=0;
    while(cur_pos != pos-1){
        temp=temp->link;
        cur_pos++;
    }
    temp->link=new_node;
    new_node->link=temp->link;
}

void del(Node* &head){
    Node* second_last=head;
    while(second_last->link->link!=NULL){
       
       second_last=second_last->link;
    }
    Node* temp=second_last->link;
    second_last->link=NULL;
        free(temp);
}

void display(Node* head){
    Node* temp=head;
    while(temp != NULL){
        cout<<temp->val<<" ";
        temp=temp->link;
    }
}
int main(){
    int data,pos;
    Node* head=NULL;
    insert(head,2);
    for(int i=0;i<5;i++){
        cout<<"Enter your no: ";
        cin>>data;
        insert_Tail(head,data);
    }
    display(head);
    cout<<endl;

    del(head);
    display(head);
    cout<<endl;
    return 0;
}

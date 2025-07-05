// update the given node
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

void insert_tail(Node* &head,int data){
    Node* temp=new Node(data);
    Node* lnode=head;
    while(lnode->link !=NULL){
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

// updating node
void insert_update(Node* &head,int data,int k){
    Node* temp=head;
    int cur_pos=0;
    while(cur_pos!= k){
        temp=temp->link;
        cur_pos++;
    }
    temp->val=data;
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
   // for(int i=0;i<4;i++){
    //    cout<<"Enter your no: ";
    //    cin>>data;
    //    insert_tail(head,data);
    //}
     insert(head,4);
      insert(head,6);
       insert(head,8);
       display(head);
    cout<<"Enter your no to add node at given posiiton: ";
    cin>>data;
    cout<<"Enter your position to add new Node : ";
    cin>>pos;
    insert_pos(head,data,pos);
    display(head);
    cout<<endl;
    
    // upadate the node data
       cout<<"Enter your no to update the Node : ";
    cin>>data;
    cout<<"Enter your position to Update Node : ";
    cin>>pos;
    insert_update(head,data,pos);
    display(head);
    return 0;
}

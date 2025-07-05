// find the intersection
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

void insert(Node* & head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}
int node_len(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
Node* move_node(Node* & head,int k){
    while(k--){
        head=head->next;
    }
    return head;
}

// intersecting section
Node* intersection(Node* head,Node* head1){
    int l1=node_len(head);
    int l2=node_len(head1);
    Node* ptr;
    Node* ptr1;
    if(l1>l2){
        int k=l1-l2;
        ptr= move_node(head,k);
        ptr1=head1;
    }
    else{
        int k=l2-l1;
        ptr=head;
        ptr1=move_node(head1,k);
    }

    while(ptr!=NULL){
        if(ptr==ptr1){
            return ptr;
        }
        ptr=ptr->next;
        ptr1=ptr1->next;
    }
    return NULL;
}

void display(Node* head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
}

int main(){
    Node* head=NULL;
    Node* head1=NULL;
    insert(head,2);
    insert(head,3);
    insert(head,4);
    insert(head,5);
    display(head);
    cout<<endl;
    insert(head1,3);
    insert(head1,1);
    head1->next->next=head->next->next;  // back pointing is done here
    display(head1);
    Node* temp=intersection(head,head1);
    if(temp){
        cout<<endl;
        cout<<temp->val;
    }
    else{
        cout<< "Intersection Not Found !";
    }
   return 0;

}
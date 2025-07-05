// Arrange the Element Index wise 
// odd Index Element in one place
//Even Index Element in One Place
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
void insert(Node* &head,int data){
    Node* temp=new Node(data);
    temp->next=head;
    head=temp;
}
void insert_tail(Node* &head,int data){
    Node* temp=new Node(data);
    Node* lnode=head;
    while(lnode->next!=NULL){
        lnode=lnode->next;
    }
    lnode->next=temp;
}

Node* indeces(Node* &head){
    if(!head) return head;
    Node* evenHead=head->next;
    Node* oddptr=head;
    Node* evenptr=evenHead;

    while(evenptr && evenptr->next){
        oddptr->next=oddptr->next->next;
        evenptr->next=evenptr->next->next;
        oddptr=oddptr->next;
        evenptr=evenptr->next;
    }
    oddptr->next=evenHead;
    return head;
}
void display(Node* head){
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}

int main(){
    Node* head=NULL;
    insert(head,1);
    int data;
    
    for(int i=0;i<7;i++){
        cout<<"Enter your data :";
        cin>>data;
        insert_tail(head,data);
    }
    display(head);
    cout<<endl;
    Node* temp=indeces(head);
    display(temp);
    return 0;
}

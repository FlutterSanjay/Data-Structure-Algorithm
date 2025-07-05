// Merge the k Linked _List
#include<iostream>
#include<vector>
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
    while(lnode->next !=NULL){
        lnode=lnode->next;
    }
    lnode->next=temp;
}

Node* merge(Node* head,Node* head1){
    Node* dummy=new Node(-1);
    Node* ptr=head;
    Node* ptr1=head1;
    Node* ptr2=dummy;
    while(ptr!=NULL && ptr1!=NULL){
   
    if(ptr->val<ptr1->val){
        ptr2->next=ptr1;
        ptr1=ptr1->next;
    }
    else{
        ptr2->next=ptr1;
        ptr1=ptr1->next;
    }
    ptr2=ptr2->next;
}
if(ptr!=NULL){
    ptr2->next=ptr;
}
else{
    ptr2->next=ptr1;
}
return dummy->next;
}

Node* mergeKLink(vector<Node*> &list){
    if(list.size()==0){
        return NULL;
    }
    while(list.size()>1){
        Node* mergeHead=merge(list[0],list[1]);
        list.push_back(mergeHead);
        list.erase(list.begin());
        list.erase(list.begin());
    }
    return list[0];
}

 void display(Node* head){
    while(head !=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
 }

 int main(){
    Node* head=NULL;
    Node* head1=NULL;
    Node* head2=NULL;
    insert(head,1);
    int data;
    for(int i=0;i<3;i++){
        cout<<"Enter your no : ";
        cin>>data;
        insert_tail(head,data);
    }
    display(head);
    cout<<endl;
    insert(head1,3);
    for(int i=0;i<3;i++){
        cout<<"Enter your no : ";
        cin>>data;
        insert_tail(head1,data);
    }
    display(head1);
    cout<<endl;
    insert(head2,8);
    for(int i=0;i<3;i++){
        cout<<"Enter your no : ";
        cin>>data;
        insert_tail(head2,data);
    }
    display(head2);
    vector<Node*> list;
    list.push_back(head);
    list.push_back(head1);
    list.push_back(head2);

    Node* temp=mergeKLink(list);
    cout<<endl;
    display(temp);
    return 0;
 }

// verified the answer
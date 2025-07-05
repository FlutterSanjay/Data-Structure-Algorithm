//check the givven linked list palindrome
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
 class Doubly{
    public:
    Node* head;
    Node* tail;

    Doubly(){
        head=NULL;
        tail=NULL;
    }
    
    void insert(int data){
        Node* end=new Node(data);
        if(tail==NULL){
            head=end;
            tail=end;
            return;
        }
        tail->next=end;
        end->prev=tail;
        tail=end;
        return ;
    }

    void display(){
        while(head !=NULL){
            cout<<head->val<<" ";
            head=head->next;
        }

    }

 };

 bool palindrome(Node* head,Node* tail){
    while(head!=tail && tail != head->prev){
        if(head->val != tail->val){
            return false;
        }
        head=head->next;
        tail=tail->prev;
    }
    return true;
 }

 int main(){
    Doubly aa;
    int data;
    for(int i=0;i<5;i++){
        cout<<"Enter your no :";
        cin>>data;
        aa.insert(data);
    }
    

 bool result=palindrome(aa.head,aa.tail);
 if(result==1) cout<<"Palindrome Node!";
 else cout<<"Not Palindrome Node!";
 cout<<endl;
 aa.display();
 return 0;
 }
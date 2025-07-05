// Basic implementation of Doubly Linked -List
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
};

int main(){
    Node* head=new Node(2);
    doubly aa;
    aa.head=head;
    aa.tail=head;
    cout<<aa.head->val<<endl;
    return 0;
}
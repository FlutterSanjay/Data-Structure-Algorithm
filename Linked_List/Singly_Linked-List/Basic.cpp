// creating the node
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

int main(){
    Node* node1=new Node(10);

    cout<<"Node Value: "<<node1->val<<" "<<"Node Address : "<<node1->next;
    return 0;
}
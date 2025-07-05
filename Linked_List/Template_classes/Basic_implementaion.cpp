// Basic implementation of template classes
#include<iostream>
using namespace std;

template<typename T>
class Node{
    public:
    T val;
    Node* next;

    Node(T data){
        val=data;
        next=NULL;
    }

};


int main(){
    Node<int>* node1=new Node<int>(3);
    cout<<node1->val<<endl;
    Node<int>* node2=new Node<int>(5);
    cout<<node2->val<<endl;
    Node<float>* node3=new Node<float>(3.14);
    cout<<node3->val<<endl;
    Node<char>* node4=new Node<char>('a');
    cout<<node4->val<<endl;
    Node<string>* node5=new Node<string>("sanjay");
    cout<<node5->val<<endl;

    return 0;
 


}

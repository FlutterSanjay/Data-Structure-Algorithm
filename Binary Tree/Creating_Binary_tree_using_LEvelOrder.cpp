// Creating  Binary tree using Level Order
#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int val;
    Node* left;
    Node* right;
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};

void build_tree(Node* root){
    queue<Node*>q;
    cout<<"Enter the data of Root : ";
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        cout<<"Enter the data for left part : ";
        int leftData;
        cin>>leftData;

        if(leftData!=-1){
            temp->left=new Node(leftData);
            q.push(temp->left);
        }

        // right part
        cout<<"Enter the data for right part : ";
        int rightData;
        cin>>rightData;

        if(rightData!=-1){
            temp->right=new Node(rightData);
            q.push(temp->right);
        }
    }
}

int main(){
    Node* root=NULL;
    build_tree(root);
    return 0;
}
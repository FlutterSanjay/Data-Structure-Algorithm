// Search in Binary Search Tree
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

void level(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp=q.front();
        q.pop();

        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->val<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
    }
}

Node* insert_BST(Node* &root,int data){
    if(root==NULL){
        root=new Node(data);
        return root;
    }
    // right part
    if(data > root->val){
        root->right=insert_BST(root->right,data);
    }
    // left pert
    else{
        root->left=insert_BST(root->left,data);
    }
    return root;
}

void take_input(Node* &root ){
    int data;
    cin>>data;
    while(data !=-1){
        root=insert_BST(root,data);
        cin>>data;
    }
}

bool search(Node* root,int x){
    if(root==NULL){
        return false;
    }
    if(root->val==x){
        return true;
    }
    if(root->val > x){
        return search(root->left,x);
    }
    else{
        return search(root->right,x);
    }
}

int main(){
    int x=5;
    Node* root=NULL;
    cout<<"Enter data to create BST"<<endl;
    take_input(root);
    cout<<"Output-"<<endl;
    level(root);
    bool result=search(root,x);
    if(result) cout<<"Data is Present !..";
    else cout<<"Data is Not Present !..";
    return 0;
}

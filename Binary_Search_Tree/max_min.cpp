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
int min(Node* root){
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->val;
}
int max(Node* root){
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->val;
}

int main(){
    int x=5;
    Node* root=NULL;
    cout<<"Enter data to create BST"<<endl;
    take_input(root);
    cout<<"Output-"<<endl;
    level(root);
    cout<<endl;
    cout<<"Minimum of Number of BST -";
    cout<<min(root)<<endl;
    cout<<"Mamimum of Number of BST -";
    cout<<max(root)<<endl;
    return 0;
}
